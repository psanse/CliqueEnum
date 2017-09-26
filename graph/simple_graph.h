/*  
 * graph.h file from the GRAPH library, a C++ library for bit encoded 
 * simple unweighted graphs. GRAPH stores the adjacency matrix un full 
 * but each row is encoded as a bitsrting. GRAPH is at the core of  BBMC, a 
 * state of the art leading exact maximum clique algorithm. 
 * (see license file (legal.txt) for references)
 *
 * Copyright (C)
 * Author: Pablo San Segundo
 * Intelligent Control Research Group CAR(UPM-CSIC) 
 *
 * Permission to use, modify and distribute this software is
 * granted provided that this copyright notice appears in all 
 * copies, in source code or in binaries. For precise terms 
 * see the accompanying LICENSE file.
 *
 * This software is provided "AS IS" with no warranty of any 
 * kind, express or implied, and with no claim as to its
 * suitability for any purpose.
 *
 */

#ifndef __SIMPLE_GRAPH_H__
#define __SIMPLE_GRAPH_H__


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

#include "bitscan/bitscan.h"
#include "filter_graph_encoding_type.h"
#include "./formats/mmx_reader.h"
#include "./formats/edges_reader.h"
#include <math.h>
#include "utils/prec_timer.h"
#include "utils/logger.h"


//file extension for weights (W or D)-LAMSADE
//#define FILE_EXTENSION_W							0x100		//LAMSADE-original: weights according to degree
#define FILE_EXTENSION_D							0x101		//Classical weights used in tests: 1-200 in a loop

typedef vector<int> vint;

using namespace std; 
template<class T>
class Graph: public filterGraphEncodingType<T>{
	friend class GraphConversion;
public:
	typedef T bb_type;
	template <class B>
	friend bool operator ==				(const Graph<B>& lhs, const Graph<B>& rhs);	//not extended to weights (!)

	Graph								();											//does not allocate memory
	Graph								(int nV);									//creates empty graph with size vertices	
	Graph								(const Graph&);
	Graph								(std::string filename);		
	~Graph								(){clear();};

/////////////
// setters and getters
	int set_graph						(std::string filename);
		
	std::string get_name				() const {return m_name;}
	std::string get_path				() const {return m_path;}
	void set_name						(std::string graph_name, bool remove_path=false);
const T* get_graph						()					const;	
virtual void add_edge					(int v, int w);								//v->w	(no self_loops allowed)
virtual void remove_edge				(int v, int w);	
		void remove_edges				(int v);									//removes in-out edges from v

	//bitstring encoding
	int number_of_vertices				()					const;
	int number_of_blocks				()					const		{return m_BB;}
virtual	BITBOARD number_of_edges		(bool lazy=true);
virtual	BITBOARD number_of_edges		(const BitBoardN& bbsg )	const;								//on induced subgraph
const T& get_neighbors					(int v)				const		{return m_g[v];}
      T& get_neighbors					(int v)							{return m_g[v];}
const vint& get_weights					()					const		{return m_wv;}	
	vint& get_weights					()								{return m_wv;}	
	int maximum_weight					(int& v)			const;		

	//weights
	void set_wv							(int v, int w)					{m_wv[v]=w;}					//MUST call first init_wv()
	int get_wv							(int v) const					{return m_wv[v];}
	void reset_wv						();											//sets unit weights

//////////////////////////
// memory allocation 
virtual	int init						(int nV);									//allocates memory for n vertices
	int init_wv							();											//allocates memory for weights
	void clear							();											//deallocates memory if required
	Graph& create_subgraph				(int size, Graph& newh)  ;
	int shrink_to_fit					(int size);									//reduces the graph to size (currently only for sparse graphs)
	
	Graph& operator =					(const Graph&);					
//////////////	
// Basic operations
		
	double density						()						;	
	double density						(const T& )				;					//on induced graph
	double block_density				()						const;
	double block_density_index			()						;					//returns number of blocks/total possible number of blocks
 	double average_block_density_index	()						;					//average density per block

	int degree_out						(int v)					const;				//outgoing edges from v
	int degree_in						(int v)					const;				//edges incident to v

	void make_bidirected				();											//make all edges symmetrical
/////////////
// Boolean
virtual	bool is_edge					(int i, int j)			const;		
	bool is_weighted_v					()						const			{return m_is_wv;}	
private:
	bool is_no_self_loops				()						const;

/////////////
// Update operations
public:
	void remove_vertices				(const BitBoardN&, Graph&);				
virtual void remove_vertices			(const BitBoardN&);				

////////////
// E/S
public:
	int read_dimacs						(const string& filename);	
	int read_mtx						(const string& filename);
	int read_EDGES						(const string& filename);
virtual	void  write_dimacs				(ostream& o);	
virtual	void  write_EDGES				(ostream& o);
virtual	void print_data					(bool lazy=true, std::ostream& = std::cout);
	ostream& print_weights				(ostream& o= std::cout) const; 
	ostream& print_weights				(bb_type& bbsg, ostream& o= std::cout) const;
	virtual void print_edges			(ostream& = std::cout) const;
	virtual void print_edges			(bb_type& bbsg, ostream& = std::cout) const;	/* edges of subgraph*/
	int read_weights					(const string& filename);	

	
//////////////////////////
// ATTRIBUTES
protected:
	vector<T> m_g;			//adjacency matrix 
	int m_size;				//graph order (number of vertices)
	int m_BB;				//number of bit blocks per row (in the case of sparse graphs this is a maximum value)
	BITBOARD m_edges;		//number of edges (updated on the fly)
	
	bool m_is_wv;			//TRUE if the graph is weighted
	vector<int> m_wv;		//vector of weights (currently automated reading for DIMACS graphs in an auxiliary graph with extension *.w or *.d)

	std::string m_name;		//graph label	
	std::string m_path;		//path of name (extension used for weight files-4/3/17)
};

template <class T>
inline
int Graph<T>::maximum_weight(int& v)const{
	if(!m_is_wv){
		LOG_ERROR("Graph<T>::maximum_weight()-graph is not tagged as weighted");
		v=EMPTY_ELEM;
		return 1;
	}
	vector<int>::const_iterator it=max_element(m_wv.begin(), m_wv.end());
	v=it-m_wv.begin();
	return *it;
}

template <class T>
inline
ostream& Graph<T>::print_weights (bb_type& bbsg, ostream& o) const{
	if(!m_is_wv){
		LOG_ERROR("Graph<T>::print_weights-unweighted graph!");
		return o;

	}
	bbsg.init_scan(bbo::NON_DESTRUCTIVE);										/* CHECK sparse graphs */
	while(true){
		int v=bbsg.next_bit();
		if(v==EMPTY_ELEM) break;
		o<<"["<<v<<","<<m_wv[v]<<"] ";
	}
	o<<"("<<bbsg.popcn64()<<")"<<endl;
	return o;
}

template <class T>
inline
ostream& Graph<T>::print_weights (ostream& o) const{
	
	if(!m_is_wv){
		LOG_ERROR("Graph<T>::print_weights-unweighted graph!");
		return o;
	}

	for(int i=0; i<m_size; i++){
		o<<"["<<i<<","<<m_wv[i]<<"] ";
	}
	o<<endl;
	return o;
}


template <class T>
bool operator == (const Graph<T>& lhs, const Graph<T>& rhs){
	for(int i=0; i<lhs.m_size; i++){
		if(!(lhs.get_neighbors(i)==rhs.get_neighbors(i)))
			return false;
	}
	return true;
}



template<class T>
Graph<T>::Graph(void){
	m_size=0;
	m_BB=0;
	m_g.clear();
	m_name.clear();
	m_path.clear();
	m_edges=0;
	m_is_wv=false;
}


template<class T>
Graph<T>::Graph(const Graph& g){
	m_size=0;
	m_BB=0;
	m_g.clear();
    m_name.clear();
	m_path.clear();
	m_edges=0;
	(*this)=g;
}


template<class T>
Graph<T>::Graph(string filename){
	m_size=0;
	m_BB=0;
	m_g.clear();
	m_name.clear();
	m_path.clear();
	m_edges=0;
	set_graph(filename);
}


template<class T>
Graph<T>::Graph (int size){
//creates empty graph of size
	m_size=0;
	m_BB=0;
	m_g.clear();
	m_name.clear();
	m_path.clear();
	m_edges=0;
	init(size);
	m_is_wv=false;
}

template<class T>
void Graph<T>::set_name(std::string name, bool remove_path){
//name for file of weights assumed to be the same as "name" but with a w

	if(remove_path){
		std::string str=name;
		size_t found=str.find_last_of("/\\");
		m_name=str.substr(found+1);
		m_path=str.substr(0,found+1);  //includes slash

	}else{
		m_name=name;
		m_path.clear();
	}

	//adding name for weights in nodes (6/10/16)
	//std::string str=name;
	//string wname=str.substr(str.find_last_of("/\\")+1);
	//wname="w"+wname;
	//string str1(name);
	//m_wname=str.substr(0,str1.find_last_of("/\\")+1);
	//m_wname+=wname;
}

template<class T>
Graph<T>& Graph<T>::operator= (const Graph& g){
/////////////////
// Sets graph (allocates memory)

	if(this==&g) return *this;		//same graph

	//allocation
	init(g.m_size);					 //possibly throw exception
	for(int i=0; i<m_size; i++){
					m_g[i]=g.m_g[i];
	}
	
	this->m_name=g.m_name;
	this->m_path=g.m_path;

	//weights
	this->m_is_wv=g.m_is_wv;
	if(this->m_is_wv)
		this->m_wv=g.m_wv;	
	else this->m_wv.clear();
			
return *this;
}

template<class T>
void Graph<T>::clear	(){
	m_g.clear();
	m_wv.clear();			
	m_size=0;
	m_BB=0;
	m_name.clear();
	m_edges=0;
	m_is_wv=false;
}

template<class T>
int Graph<T>::init(int size){
///////////////////////////
// Allocates memory for the empty graph (deallocates previous)

	//deallocates previous
	clear();
		
	try{
		m_g.resize(size);	
	}catch(...){
		cout<<"memory for graph not allocated";
		return -1;
	}

	m_size=size;
	m_BB=INDEX_1TO1(m_size);

	//zero edges
	for(int i=0; i<m_size; i++){
		m_g[i].init(m_size);		
	}

return 0;
}

template<class T>
inline
int Graph<T>::init_wv (){
//////////////
// weights default value is 1
	m_wv.clear();
	try{
		m_wv.resize(m_size);	
	}catch(...){
		cout<<"memory for graph not allocated";
		return -1;
	}
	
	//zero edges
	for(int i=0; i<m_size; i++){
		m_wv[i]=1;		
	}
	m_is_wv=true;
	return 0;
}

template<class T>
inline
Graph<T>& Graph<T>::create_subgraph (int size, Graph<T>& newg)  {
//////////////////////////
// creates new subgraph with subset of size vertices 

	//assert is size required is greater or equal current size
	if(size>=m_size || size<=0){
		cerr<<"wrong shrinking size for graph. Remains unchanged"<<endl;
		return *this;
	}
		
	newg.init(size);
	int bbh=WDIV(size-1);

	
	for(int i=0; i<newg.m_size; i++){
		for(int j=0; j<=bbh; j++){
			newg.m_g[i].get_bitboard(j)=m_g[i].get_bitboard(j);
		}
		//trims last bitblock
		newg.m_g[i].get_bitboard(bbh)&=~Tables::mask_left[WMOD(size-1)];
	}
	
return newg;
}

template<>
inline
Graph<sparse_bitarray>& Graph<sparse_bitarray>::create_subgraph (int size, Graph<sparse_bitarray>& newg)  {
//////////////////////////
// creates new subgraph with vertex set V=[1,2,..., size]
//
// RETURNS: reference to the new subgraph
	
	//assert is size required is greater or equal current size
	if(size>=m_size || size<=0){
		cerr<<"wrong shrinking size for graph. Remains unchanged"<<endl;
		return *this;
	}
		
	newg.init(size);
	
	//copies to the new graph
	for(int i=0; i<newg.m_size; i++){
		newg.m_g[i]=m_g[i];
		newg.m_g[i].clear_bit(size, EMPTY_ELEM);		//from size to the end
	}

return newg;
}

template<class T>
int Graph<T>::shrink_to_fit(int size){
/////////////////////
// shrinks graph to the size passed (must be less than current size)
	
	cerr<<"shrinking is only possible in sparse graphs; the graph remains unchanged"<<endl;

return -1;
}

template<>
inline
int Graph<sparse_bitarray>::shrink_to_fit(int size){
/////////////////////
// shrinks graph to the size passed (must be less than current size)
	if(m_size<=size){
		cerr<<"wrong shrinking size for graph, remains unchanged"<<endl;
		return -1;
	}

	//trims vertices 
	for(int i=0; i<size; i++){
		m_g[i].clear_bit(size, EMPTY_ELEM);		//from size to the end
	}
	
	//resizes adjacency matrix
	m_g.resize(size);
	m_size=size;
	m_edges=0;									//so that when needed will be recomputed

return 0;
}


template<class T>
int Graph<T>::number_of_vertices()		const{
	return m_size;
}


template<class T>
const T* Graph<T>::get_graph()	const{
	return m_g;
}

template<class T>
int Graph<T>::set_graph (string filename){
	if(read_dimacs(filename)==-1){
		if(read_mtx(filename)==-1){
			if(read_EDGES(filename)==-1){
				cerr<<"unable to read file in any of these formats: DIMACS/MTX/EDGES"<<endl;
				return -1;
			}
		}
	}
return 0;
}

template<class T>
void Graph<T>::add_edge (int v, int w){
///////////////
// sets v-->w (no self loops allowed)
	if(v!=w){
		m_g[v].set_bit(w);
		m_edges++;
	}

}

template<class T>
void Graph<T>::remove_edge	(int v, int w){
	m_g[v].erase_bit(w);
	m_edges--;
}

template<class T>
void Graph<T>::remove_edges (int v){
//removes in-out edges from v
	
	//erases all outgoing edges from v
	m_g[v].erase_bit();

	//erases all ingoing edges
	for(int w=0; w<m_size; w++){
		if(w==v) continue;
		m_g[w].erase_bit(v);
	}

	//updates edges
	number_of_edges(false);
}

template<class T>
int Graph<T>::read_dimacs(const string& filename){
/////////////////////////////
// Reads an unweighted simple directed graph in dimacs format
// 'c' comment
// 'p' next numbers in the line are size and number of edges
// 'e' next in the lines is an edge
// 
// RETURN VALUE: 0 if correct, -1 in case of error (no memory allocation)
//
// Extension (9/10/16): Will awways attempt to read weights for nodes from 
//						filename.w file
//
// Extension (6/09/17): Reading weights in DIMACS format (n <V> <W(V)>)
//////////////////////
	
	int size, nEdges, v1, v2, edges=0, wv=0;
	char token[10]; char line [250]; char c;
	
	fstream f(filename.c_str());
	if(!f){
		cerr<<"File could not be opened reading DIMACS format"<<endl;
		clear();
		return -1;
	}

	//header (find p edges line)
	
	bool loop_finding_header=true;
	do{
		c=f.peek();
		if(c=='\n' || c=='c' || c=='\r'){
			f.getline(line, 250);
			continue;		
		}
		switch(c){
		case 'p':  //header p edge <nV> <nE>
			f>>token>>token>>size>>nEdges;
			if(!f.good() || strstr(token, "edge")==0){
				cerr<<"bad header 'p' line"<<endl;
				clear();
				f.close();
				return -1;
			}
			loop_finding_header=false;
			f.getline(line, 250);			//remove remaining part of the line
			break;
		case 'c':
			break;						//comment			
		default:									
			clear();
			f.close();
			cerr<<"wrong DIMACS protocol: first character of new line is: "<<c<<endl;;
			return -1;
		}
	}while(loop_finding_header);

	//allocation
	init(size);

	//weights if they exist
	c=f.peek();
	if(c=='n'){						//weights
		LOG_INFO("DIMACS weights found in file: excluding other weights");
		init_wv();
		m_is_wv=true;
		for(int n=0; n<m_size; n++){
			f>>c>>v1>>wv;
			if(!f.good()){
				cerr<<"bad line related to weights"<<endl;
				clear();
				f.close();
				return -1;
			}
			m_wv[v1-1]=wv;
			if(wv==0){
				cerr<<filename<<":wrong header for edges reading DIMACS format"<<endl;
				clear();
				f.close();
				return -1;
			}
			f.getline(line, 250);  //remove remaining part of the line
		}

		LOG_INFO("Weights read correctly from DIMACS file"<<filename);
	}

	//read weights
	for(int e=0; e<nEdges; e++){
		f>>c;
		if(c!='e'){
			cerr<<filename<<":wrong header for edges reading DIMACS format"<<endl;
			clear();
			f.close();
			return -1;
		}
		//add bidirectional edge
		f>>v1>>v2;
		add_edge(v1-1,v2-1);
			
		f.getline(line, 250);  //remove remaining part of the line
	}
	f.close();
	
	//name (removes path)
	set_name(filename, true);

	//extension for weighted files (9/10/16)
	string str(filename);					//filename contains the full path

	//read weights from external files if necessary
	if(!m_is_wv){

#ifdef FILE_EXTENSION_W	
		str+=".w";
#elif FILE_EXTENSION_D
		str+=".d";
#else
		str+=".nofile";
#endif

		read_weights(str);
	}
return 0;
}

template<class T>
int  Graph<T>::read_mtx	(const string& filename){
//////////////////
// reads matrix exchange format (at the moment only MCPS)

	MMI<Graph<T> > myreader(*this);
	return (myreader.read(filename));
}

template<class T>
int  Graph<T>::read_EDGES (const string& filename){
//////////////////
// reads matrix exchange format (at the moment only MCPS)

	EDGES<Graph<T> > myreader(filename, *this);
	return (myreader.read());
}

template<class T>
inline
void Graph<T>::print_data( bool lazy, std::ostream& o) {
	o<<number_of_vertices()<<" "<<fixed<<number_of_edges(lazy)<<" "<<std::setprecision(6)<<density()<<" "<<m_name.c_str();
	if(m_is_wv) o<<" w";
	o<<endl;
}


template<class T>
inline
void Graph<T>::print_edges (std::ostream& o) const{
	for(int i=0; i<m_size-1; i++){
		for(int j=i+1; j<m_size; j++){
			if(is_edge(i,j)){
				o<<"["<<i<<"]"<<"-->"<<"["<<j<<"]"<<endl;
			}
			if(is_edge(j,i)){
				o<<"["<<j<<"]"<<"-->"<<"["<<i<<"]"<<endl;
			}
		}
	}
}

template<class T>
inline
void Graph<T>::print_edges (bb_type& bbsg, ostream& o)const {
/////////////
// TODO-optimize
	for(int i=0; i<m_size-1; i++){
		if(!bbsg.is_bit(i)) continue;
		for(int j=i+1; j<m_size; j++){
			if(!bbsg.is_bit(j)) continue;
			if(is_edge(i,j)){
				o<<"["<<i<<"]"<<"-->"<<"["<<j<<"]"<<endl;
			}
			if(is_edge(j,i)){
				o<<"["<<j<<"]"<<"-->"<<"["<<i<<"]"<<endl;
			}
		}
	}
}


template<class T>
BITBOARD Graph<T>::number_of_edges	(const BitBoardN& bbn) const{
////////////////
// Number of edges in the graph induced by bbn 
// Source: 17/6/10 
// Last Updated: 12/4/12  
	
	BITBOARD edges=0;
	for(int i=0; i<m_size; i++){
		if(bbn.is_bit(i)){
			for(int j=0; j<m_size; j++)
				if(bbn.is_bit(j)){
					if(m_g[i].is_bit(j)) edges++;
				}
		}
	}
return edges;
}

template<class T>
BITBOARD Graph<T>::number_of_edges	(bool lazy) {
////////////
// Computes edges only once and caches its value
//
// REMARKS: Can be an expensive operation
	if(lazy && m_edges !=0) 
				return m_edges;
	
	BITBOARD  edges=0;
	for(int i=0; i<m_size; i++){
		for(int j=0; j<m_size; j++){
			if(is_edge(i,j)){			//O(log) in sparse graphs (specialize)
				edges++;
			}
		}
	}
	m_edges=edges;
	

return m_edges;
}

template<> inline
BITBOARD Graph<sparse_bitarray>::number_of_edges(bool lazy) {
//specialization for sparse graphs (is adjacent runs in O(log)) 
// 

	if(lazy && m_edges !=0) 
				return m_edges;
		
	BITBOARD  edges=0;
	for(int i=0; i<m_size; i++){
		edges+=m_g[i].popcn64();
	}
	m_edges=edges;
	
return m_edges;
}

template<class T>
double Graph<T>::density () {
	BITBOARD max_edges=m_size;									//important for very large graphs as (I) is bigger than unsigned int
	max_edges*=(max_edges-1);									//(I)
	return (number_of_edges()/(double)max_edges);				//n*(n-1) edges
}

template<class T>
double Graph<T>::block_density	()	const{
/////////////////////////
// number of empty bitblocks wrt total amount 
//
// REMARKS: has to be specialized for sparse graphs

	size_t nBB=0;
	for(int v=0; v<m_size; ++v){
		for(int bb=0; bb<m_BB; bb++){
			if(m_g[v].get_bitboard(bb))				
				nBB++;
		}
	}

return (nBB/static_cast<double>(m_BB*m_size));
}

template<> inline
double Graph<sparse_bitarray>::block_density	()	const{
/////////////////////////
// specialization for sparse graphs
//
// RESULT: should be a 1.0 ratio, since only non-zero bitblocks are stored

	size_t nBB=0; size_t nBBt=0;
	for(int v=0; v<m_size; ++v){
		nBBt+=m_g[v].number_of_bitblocks();
		for(int bb=0; bb<m_g[v].number_of_bitblocks(); bb++){
			if(m_g[v].get_bitboard(bb))							
						nBB++;
		}
	}

return nBB/double(nBBt);
}

template<>
inline
double Graph<sparse_bitarray>::block_density_index()	{
/////////////////////////
// a measure of sparsity in relation to the number of bitblocks //
	size_t nBB=0; size_t nBBt=0;
	for(int v=0; v<m_size; ++v){
		nBBt+=m_g[v].number_of_bitblocks();
	}

	BITBOARD aux=ceil(m_size/double(WORD_SIZE));
	BITBOARD maxBlock=m_size*aux;

	cout<<m_size<<":"<<aux<<":"<<nBBt<<":"<<maxBlock<<endl;
	return (double(nBBt))/maxBlock;

}

template<>
inline
double Graph<sparse_bitarray>::average_block_density_index()	{
/////////////////////////
// average of density per block
//
	size_t nBB=0; size_t nBBt=0;
	double den=0.0;
	for(int v=0; v<m_size; ++v){
		nBB=m_g[v].number_of_bitblocks();
		nBBt+=nBB;
		int pc=m_g[v].popcn64();
		den+=double(pc)/(BITBOARD(nBB)*WORD_SIZE);
	}

	
	return (den/nBBt);
}

template<class T>
double Graph<T>::density(const T & bbN )  {
	unsigned long long  edges=number_of_edges(bbN);
	if(edges==0) return 0.0;
	unsigned long long  pc=bbN.popcn64();
	return edges/(double)(pc*(pc-1)/2);
}


template<class T>
bool Graph<T>::is_edge	(int i, int j) const{
//////////////////
// true if there is an edge (i,j)
// First created: 14/10/2010

	return(m_g[i].is_bit(j));
}


template<class T>
bool Graph<T>::is_no_self_loops () const{
//////////////////
// true if there is no edge (v,v) 

	for(int i=0; i<m_size; i++)
		if( m_g[i].is_bit(i)) {
			cout<<"Graph with self-loops in:"<<i<<endl;
			return false;
		}
return true;
}


template<class T>
void Graph<T>::remove_vertices (const BitBoardN& bbn, Graph& g){
/////////////////////
// returns in g the induced graph by bbn

	m_edges=0;									//resets vertices
	int pc=bbn.popcn64();
	int new_size=m_size-pc;
	if(pc==0){return;}
	else if(new_size==0){ g.clear();}				//empty graph
	
	g.init(new_size);
	g.set_name(this->m_name);
	int l=0; int m=0;
	
	//runs through the whole graph
	for(int i=0; i<m_size-1; i++){
		if(bbn.is_bit(i))continue;				//jumps over vertices marked for deletion
		m=l+1;										
		for(int j=i+1; j<m_size; j++){
			if(bbn.is_bit(j)) continue;			//jumps over vertices marked for deletion
			if(m_g[i].is_bit(j)){
				g.add_edge(l,m);
			}
			m++;
		}
		l++;
	}
return ;
}


template<class T>
void Graph<T>::remove_vertices (const BitBoardN& bbn){
///////////////
// Experimental: deletes input list of nodes by creating a temporal graph
//
// OBSERVATIONS:
// 1.Inefficient implementation with double allocation of memory

	Graph<T> g;
	remove_vertices(bbn,g);			//allocation 1
	(*this)=g;						//allocation 2	
}


template<class T>
int Graph<T>::degree_out (int v)const{
///////////////////
// outcoming edges from v

	return m_g[v].popcn64();
}


template<class T>
int Graph<T>::degree_in (int v)const{
///////////////////
// incoming edges to v (endpoint in v)
	int res=0;
	for(int i=0; i<m_size; i++){
		if(i==v) continue;
		if(m_g[i].is_bit(v)) 
			res++;
	}
return res;
}

template<class T>
void Graph<T>::make_bidirected (){
///////////////////
// makes all edges symmetrical
	for(int i=0; i<m_size; i++){
		for(int j=0; j<m_size; j++){
			if(is_edge(i,j)) add_edge(j, i);
			if(is_edge(j,i)) add_edge(i, j);
		}
	}
	
	m_edges=0;	//resets edges to avoid lazy evaluation later
}

template<class T>
inline
void Graph<T>::write_dimacs (ostream& o) {
/////////////////////////
// writes file in dimacs format 
	
	//timestamp 
	o<<"c File written by GRAPH:"<<PrecisionTimer::local_timestamp();
	
	//name
	if(!m_name.empty())
		o<<"\nc "<<m_name.c_str()<<endl;

	//tamaño del grafo
	o<<"p edge "<<m_size<<" "<<number_of_edges()<<endl<<endl;

	//write DIMACS nodes n <v> <w>
	if (is_weighted_v()){
		for(int v=0; v<m_size; v++){
			o<<"n "<<v+1<<" "<<get_wv(v)<<endl;
		}
	}
	
	//write edges
	for(int v=0; v<m_size; v++){
		for(int w=0; w<m_size; w++){
			if(v==w) continue;
			if(is_edge(v,w) )							//O(log) for sparse graphs: specialize
					o<<"e "<<v+1<<" "<<w+1<<endl;		//1 based vertex notation dimacs
			
		}
	}
}

template<class T>
inline
void  Graph<T>::write_EDGES	(ostream& o){
/////////////////////////
// writes simple unweighted grafs  in edge list format 
// note: loops are not allowed
		
	//timestamp 
	o<<"% File written by GRAPH:"<<PrecisionTimer::local_timestamp();
	
	//name
	if(!m_name.empty())
		o<<"\n%  "<<m_name.c_str()<<endl;
	
	//write edges
	for(int v=0; v<m_size; v++){
		for(int w=0; w<m_size; w++){
			if(v==w) continue;
			if(is_edge(v,w) )							//O(log) for sparse graphs: specialize
					o<<v+1<<" "<<w+1<<endl;				//1 based vertex notation dimacs
			
		}
	}
}

template<>
inline
void Graph<sparse_bitarray>::write_dimacs (ostream& o) {
/////////////////////////
// writes file in dimacs format 
	
	//***timestamp 
	
	//name
	if(!m_name.empty())
		o<<"\nc "<<m_name.c_str()<<endl;

	//tamaño del grafo
	o<<"p edge "<<m_size<<" "<<number_of_edges()<<endl<<endl;
	
	//Escribir nodos
	for(int v=0; v<m_size; v++){
		//non destructive scan of each bitstring
		if(m_g[v].init_scan(bbo::NON_DESTRUCTIVE)!=EMPTY_ELEM){
			while(1){
				int w=m_g[v].next_bit();
				if(w==EMPTY_ELEM)
					break;
				o<<"e "<<v+1<<" "<<w+1<<endl;	
			}	
		}
	}
}

template<class T>
inline
int Graph<T>::read_weights(const string& filename){
///////////////
// reads weights in m_wv (if possible)
// 
// REMARKS
// I.assumes the format are separated (line, space,...) ordered weights
// i.e. (5 6 7 ...)->w(1)=5, w(2)=6, w(3)=7,...
// II. allocates memory for m_wv
		
	m_is_wv=false;
	ifstream f(filename.c_str());
	if(f.fail()){
		LOG_DEBUG("could not open weight file: " <<filename);
		return -1;
	}	

	//allocate memory
	init_wv();
	
	//simple reading: assumes no empty lines and no
	int w=-1;
	for(int i=0; i<m_size; i++){
		f>>w;
		if(f.fail()){
			LOG_ERROR("bad reading of weights in:" <<filename);
			m_is_wv=false;
			return -1;		
		}
		m_wv[i]=w;		/*memory is already allocated for m_w*/
	}
	f.close();

	//check to screen
	/*for(int i=0; i<m_size; i++){
		cout<<m_wv[i]<<" ";
	}
	cout<<endl;*/
		
	return 0; 
}

template<class T>
inline
void Graph<T>::reset_wv(){
	for(int i=0; i<m_size; i++){
		m_wv[i]=1;
	}
}

#endif