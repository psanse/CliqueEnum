//init_color.h: header for InitColor implementation, a wrapper to color bit encoded
//				undirected graphs using greedy independent set heuristic
//
//date of creation: 23/09/14
//last update: 23/09/14
//author: pablo san segundo

#ifndef __CLIQUE_H__
#define __CLIQUE_H__

#include <iostream>
#include <sstream>
#include <map>
#include "clique_types.h"
#include "../init_color.h"
#include "../clique_sort.h"
#include "graph/graph.h"
#include "graph/kcore.h"
#include "utils/prec_timer.h"	
#include "utils/logger.h"
#include "utils/common.h"	

using namespace std;


template <class T>
class Clique:public CLQParam{
public:
//an array of nodes (seems to be more efficient than STL vectors in this particular case)
struct nodelist_t{
	nodelist_t():nodos(NULL),index(0){}
	int* nodos;
	int index;
	void print(ostream& o, bool end_ptr=false){
		if(end_ptr) for ( int i=0; i<=index; i++) { o<<nodos[i]<<" ";}
		else for ( int i=0; i<index; i++) { o<<nodos[i]<<" ";}
	}
};

protected:
typedef map<int, int> mint_t;
typedef void (Clique::*func)(int, typename T::bb_type&, nodelist_t&);

public:
////////////////
// constructors/destructors
	Clique(T* gout, param_t p):g(gout), CLQParam(p){	
		m_bbsets=NULL; m_lsets=NULL; m_path=NULL;	m_lcol=NULL; m_colsets=NULL;
		maxac=0;maxno=0;
		m_alloc=g->max_degree_of_graph();
		m_size=g->number_of_vertices();
	}

	Clique(param_t p):g(NULL), CLQParam(p){
		m_bbsets=NULL; m_lsets=NULL; m_path=NULL; m_lcol=NULL; m_colsets=NULL;
		maxac=0; maxno=0; m_alloc=0; m_size=0;
	}
	
	virtual ~Clique(){clear_all();}
		
////////////////
// setters and getters
virtual	void set_graph(T* g_out){
		clear_all();
		maxac=0;
		maxno=0;
		g=g_out;
		m_alloc=g->max_degree_of_graph();
		m_size=g->number_of_vertices();
	}

	int get_max_clique()		{return res.get_upper_bound();}
	void set_malloc(int M)		{m_alloc=M;}
	void hint_lb(int lb)		{get_param().lb=lb;}
	void fix_lb(int lb)			{maxno=lb;}
	mint_t& get_filter()		{return m_filter;}
	int problem_size()			{return m_size;}
	
	int* get_color_set(int depth)	{return m_lcol[depth];}	
	nodelist_t& get_root_nodelist() {return m_lroot; }				
	typename T::bb_type& get_root_bitstring(){return m_bbroot;}
	int* get_root_coloring()		{return Clique<T>::m_lcol[0];}

/////////////////////////////////
//allocation of search data structures
	virtual int init_bitarrays();
	virtual int init_nodelists();
	int init_path();
	virtual int init_color_labels();
	virtual int init_color_sets();
	virtual int init_others();

	virtual void clear_bitarrays();
	virtual void clear_nodelists();
	void clear_path();
	virtual void clear_color_labels();
	virtual void clear_color_sets();

	void clear_all(){clear_bitarrays(); clear_nodelists(); clear_path(); clear_color_labels(); clear_color_sets();}

	//allocation drives
	int search_allocation(search_alloc_t info);
	
	//computation of initial bounds
	vector<int> kcore_bounds(int& lb, int& ub,  KCore<T>* = NULL);
virtual	int initial_bounds(int& lb, int& ub,  KCore<T>* = NULL);

//////////////////
//approximate vertex coloring
	void paint							(int depth);					//independent set SEQ
	void paint_T						(int depth);					//non independent set SEQ
	void paint_R						(int depth);					//recoloring (BBMCR)
	void paint_sel						(int depth);					//selective coloring independent set (BBMCL)
	void paint_sel_T					(int depth);					//selective coloring non independent set (BBMCL_T)
	void paint_sel_R					(int depth);					//selective coloring with recoloring (BBMCL_R)
//////////////////	
// search

	virtual int set_up();
	virtual void tear_down				() {clear_all(); m_alloc=0;}	
	virtual void run					();

	//subgraph: also provides an alternative interface to setup()/run()/tear_down (10/11/16)
public:	
	virtual int set_up_subgraph					(typename T::bb_type& bbs, search_alloc_t* pinfo=NULL);					//use pinfo only the first time for allocation
	virtual void run_subgraph					(typename T::bb_type& bbs);												//runs non-unrolled alg for subgraph bbs	(simple framework for unrolled subgraph clique)
	virtual	void run_subgraph_with_ordering		(typename T::bb_type& bbs,  clqo::init_order_t o, gbbs::place_t p );	
	
	int sort_root_subgraph				(typename T::bb_type& bbs, clqo::init_order_t o, gbbs::place_t p);
protected:	
	virtual int allocate				(search_alloc_t info);	
	virtual int compute_upper_bounds	(typename T::bb_type& bbs);		
	virtual int compute_initial_sol		(typename T::bb_type& bbs);
public:	
///////////////////
// bool
	bool is_clique						(typename T::bb_type& l_bb) const;	
	bool is_clique						( vint& v) const;

//protect in the future
	int set_up_unrolled					(search_alloc_t info);
virtual	int set_up_non_unrolled			(search_alloc_t info);
	void run_unrolled					();
	void run_non_unrolled				();
	
protected:
	void expand							(int depth, typename T::bb_type& l_bb , nodelist_t& l_v);	//BBMC
	void expand_T						(int depth, typename T::bb_type& l_bb , nodelist_t& l_v);	//BBMC_T (classical SEQ)
	void expand_R						(int depth, typename T::bb_type& l_bb, nodelist_t& l_v);	//BBMCR
	void expand_sel						(int depth, typename T::bb_type& l_bb, nodelist_t& l_v);	//BBMCL 
	void expand_sel_T					(int depth, typename T::bb_type& l_bb, nodelist_t& l_v);	//BBMCL_T (classical SEQ)
	void expand_sel_R					(int depth, typename T::bb_type& l_bb, nodelist_t& l_v);	//BBMCL_R (recoloring)
	void initial_expand					(func expand);

//////////////////
// heuristics
	void filter_heur				(int maxno, typename T::bb_type& l_bb , nodelist_t& l_v);			//kcore filter
	void filter_heur_shrink			(int maxno);														//kcore filter

///////////////////
// I/O
public:
	void print_filter				(ostream& o=cout);

protected:	
	T* g;															//T restricted to ugraph and sparse_ugraph
	
	typename T::bb_type*	m_bbsets;								//[DEPTH][MAX_VERTEX]
	typename T::bb_type		m_bbroot;								//bitstring at root

	typename T::bb_type		m_sel;
	typename T::bb_type		m_unsel;

	int	**					m_lcol;									//[DEPTH][MAX_VERTEX]
	nodelist_t*				m_lsets;								//[DEPTH]
	nodelist_t				m_lroot;								//initial list of nodes at root
	int*					m_path;									//[DEPTH]
	typename T::bb_type*	m_colsets;								//[COLORS], storage of color sets								

	mint_t					m_filter;								//[clique LB]-->[FIRST_VERTEX_PRUNED]

	int maxno;														//size of largest solution found in current branch 
	int maxac;														//size of current best solution found at any moment
	int m_alloc;
	int m_size;
};

///////////////
// notation
#define  LISTA_L(depth)		m_lsets[(depth)]						//conventional list of vertices
#define  LISTA_BB(depth)    m_bbsets[(depth)]						//list of vertices encoded as a bitstring
#define	 MAXAC_PLUS1		maxac+1

template<>
int Clique<ugraph>::compute_upper_bounds(bitarray& bbs);
template<>
int Clique<ugraph>::compute_initial_sol(bitarray& bbs);
template <>
int Clique<ugraph>::sort_root_subgraph (bitarray& bbs, clqo::init_order_t o, gbbs::place_t p);
template<>
void Clique<ugraph>::run_subgraph_with_ordering (bitarray& bbs, clqo::init_order_t o, gbbs::place_t p);

template<class T>
int Clique<T>::init_bitarrays(){
////////////////
// arrays of bitstrings
	clear_bitarrays();
	try{
		m_bbsets=new typename T::bb_type[m_alloc];
		for(int i=0; i<m_alloc; i++){
			m_bbsets[i].init(m_size);			//set_to_0
		}
	}catch(exception& e){
		throw;
	}
	

	//bitstring at root node
	m_bbroot.init(m_size);
	m_bbroot.set_bit(0,m_size-1);
	return 0;
}

template<class T>
void Clique<T>::clear_bitarrays(){
	if(m_bbsets!=NULL){
		delete [] m_bbsets;  //Llama a destructores de BBN
	}

	m_bbsets=NULL;
}

template<class T>
int Clique<T>::init_nodelists(){
////////////////////
//arrays of lists of nodes
	clear_nodelists();
	
	try{
		m_lsets=new nodelist_t[m_alloc];
		for(int i=0; i<m_alloc; i++){
			m_lsets[i].nodos=new int [m_size];				//index=0 en el constructor
		}
		
		//list of nodes at root
		m_lroot.nodos=new int [m_size];
		for(int i=0; i<m_size; i++){
			m_lroot.nodos[i]=i;
		}
		m_lroot.index=m_size-1;								 //vertices read from first to last

	}catch(exception& e){
		throw;
	}
	return 0;
}

template<class T>
void Clique<T>::clear_nodelists(){
	//lista de nodos
	if(m_lsets!=NULL){
		for(int i=0; i<m_alloc; i++){
			if(m_lsets[i].nodos!=NULL /*&& m_lsets[i].index==0*/){
				delete [] m_lsets[i].nodos;
			}
			m_lsets[i].nodos=NULL;
		}
	delete [] m_lsets;		
	}
	m_lsets=NULL;

	//list at root
	if(m_lroot.nodos!=NULL){
		delete [] m_lroot.nodos;
	}
	m_lroot.nodos=NULL;
	m_lroot.index=EMPTY_ELEM;
}

template<class T>
int Clique<T>::init_path(){
	clear_path();
	try{
		m_path= new int[m_size];
		for(int i=0; i<m_size; i++)
			m_path[i]=EMPTY_ELEM;
	}catch(exception& e){
		throw;
	}
	return 0;	
}

template<class T>
void Clique<T>::clear_path(){
	if(m_path!=NULL)
		delete [] m_path;
	m_path=NULL;
}

template<class T>
void Clique<T>::clear_color_labels(){
	if(m_lcol!=NULL){
		for(int i=0; i<m_alloc; i++)	
			 delete [] m_lcol[i]; 
	
	delete [] m_lcol;  
	}
	m_lcol=NULL;
}

template<class T>
int Clique<T>::init_color_labels(){
//////////////////
// 	
	clear_color_labels();
	try{
		m_lcol=new int* [m_alloc];				

		for(int i=0; i<m_alloc;i++){
			m_lcol[i]=new int [m_size];					
			for(int j=0; j<m_size; j++){
				m_lcol[i][j]=CLQ_MAXINT;		//*** change to NUMBER OF NODES
			} 
		}
	}catch(exception& e){
		throw;
	}
	return 0;
}

template<class T>
int Clique<T>::init_others(){

	m_unsel.init(m_size);		
	m_sel.init(m_size);

	return 0;
}

template<class T>
void Clique<T>::clear_color_sets (){
	if(m_colsets!=NULL){
		delete [] m_colsets;  
	}
	m_colsets=NULL;
}

template<class T>
int Clique<T>::init_color_sets (){

	clear_color_sets();

	try{
		m_colsets= new typename T::bb_type[m_alloc+1];		//[0] is used to store the subgraph to color. Actual colors range from [1, N]	
		for(int i=0; i<=m_alloc; i++){
			m_colsets[i].init(m_size);						
		}
	}catch(exception& e){
		throw;
	}

	return 0;
}

template<class T>
int Clique<T>::search_allocation(search_alloc_t info){
	LOG_PRINT("init search allocation----------------");
	if(info.size>0)
		set_malloc(info.size);									//read from initial configurarion

	try{
		//allocation
		if(init_path()==-1) return -1;							//path is always necessary

		if(info.mem & search_alloc_t::ALLOC_BITARRAYS){
			if(init_bitarrays()==-1) return -1;
		}	

		if(info.mem & search_alloc_t::ALLOC_NODELISTS){
			if(init_nodelists()==-1) return -1;
		}	

		if(info.mem & search_alloc_t::ALLOC_COLOR_LABELS){
			if(init_color_labels()==-1) return -1;
		}

		if(info.mem & search_alloc_t::ALLOC_OTHERS){
			if(init_others()==-1) return -1;
		}

		if(info.mem & search_alloc_t::ALLOC_COLOR_SETS){
			if(init_color_sets()==-1) return -1;
		}

		
	}catch (exception& e){
		LOG_ERROR(e.what());
		LOG_ERROR("---------------------------------------");
		return -1;
	}


	LOG_PRINT("---------------------------------------");
	return 0;
}



template<class T>
vector<int>  Clique<T>::kcore_bounds(int& lb, int& ub,  KCore<T>* kc_out){
////////////////////
// kc_out should be NULL in practice except for the sparse case

	lb=0; ub=0;
	vector<int> vs;

	if(kc_out==NULL) {

		KCore<T> kc(*g);
		
		Result r;
		r.tic();
		LOG_PRINT("------init kcore bounds-----------");
		kc.kcore();
		ub=kc.get_kcore_number()+1;
		r.toc();
		LOG_INFO("[tkcproper:"<<r.get_user_time());
		r.tic();
		vs=kc.find_heur_clique();
		r.toc();
		LOG_INFO("[kcoreclq:"<<r.get_user_time());
		lb=vs.size();
		return vs;

	}else{
				
		Result r;
		r.tic();
		LOG_PRINT("------init kcore bounds-----------");
		kc_out->kcore();
		ub=kc_out->get_kcore_number()+1;
		r.toc();
		LOG_INFO("[tkcproper:"<<r.get_user_time());
		r.tic();
		vs=kc_out->find_heur_clique();
		r.toc();
		LOG_INFO("[kcoreclq:"<<r.get_user_time());
		lb=vs.size();
		
	}
	
	LOG_PRINT("---------------------------------------");
	return vs;
	
}

template<>
inline
vector<int>  Clique<sparse_ugraph>::kcore_bounds(int& lb, int& ub, KCore<sparse_ugraph>* kc_out){
///////////////
//specialization for the sparse case: updates filters
	//KCore<sparse_ugraph> kc(*g);
	lb=0; ub=0;
	
	LOG_PRINT("------init kcore bounds-----------");
	kc_out->kcore();
	ub=kc_out->get_kcore_number()+1;

	kc_out->make_kcore_filter(get_filter(), true);
	print_filter();								

	vector<int> vs=kc_out->find_heur_clique_sparse();
	lb=vs.size();

	LOG_PRINT("------------------------ªª---------------");
	return vs;
}

template<class T>
int Clique<T>::initial_bounds(int& lb, int& ub,  KCore<T>* kc_out){
	int lb_kc, ub_kc;
	int sol=0;
	vector<int> vset=kcore_bounds(lb_kc, ub_kc, kc_out); 
	lb=max(lb, lb_kc);  if(lb==0) lb=1;
	ub=min(ub, ub_kc);							//ub=0 always returns ub_kc
	sol=CLQParam::is_trivial_sol(lb, ub);
	res.add_solution(vset);						//just in case it cannot be improved!

return sol;
}

template<class T>
void Clique<T>::paint (int depth){
///////////////////
// Sequential greedy independent set vertex coloring which prunes the search tree

		int col=1; int kmin=maxno-depth; int nBB=EMPTY_ELEM; int v=EMPTY_ELEM;		
		LISTA_L(depth).index=EMPTY_ELEM;												//cleans the set fo candidate vertices
		const int DEPTH_PLUS1=depth+1;
	
		//copies list of vertices to color and stores size for fast empty check 
		int pc= (m_unsel=LISTA_BB(depth)).popcn64();
	
		//CUT based on population size
		if(pc<kmin){
				return;
		}

		while(true){ 
			m_sel=m_unsel;
			m_sel.init_scan(bbo::DESTRUCTIVE);
			while(true){
				v=m_sel.next_bit_del(nBB,m_unsel);
				if(v==EMPTY_ELEM)
								break;
				if(col>=kmin){  
					LISTA_L(depth).nodos[++LISTA_L(depth).index]=v;
					m_lcol[DEPTH_PLUS1][v]=col;				//labels start at 1	
				}
				if((--pc)==0)
							return;
				m_sel.erase_block(nBB,g->get_neighbors(v));
			}				
		col++;
		}
}

template<class T>
void Clique<T>::paint_T (int depth){
/////////////////////////
// non independent set SEQ 
// date of creation: 20/03/15
																															
	int cmax=1; int kmin=maxno-depth; int nBB=EMPTY_ELEM; int v=EMPTY_ELEM; 
	LISTA_L(depth).index=-1;								
	const int DEPTHPLUS1=depth+1;
	bool iscol;
	
	//clears first color (starts at index 1)
	m_colsets[1].erase_bit();
	
	//outer loop: select a vertex v to color
	LISTA_BB(depth).init_scan(bbo::NON_DESTRUCTIVE);
	while(1){
		if((v=LISTA_BB(depth).next_bit(nBB))==EMPTY_ELEM)
											break;
		//inner loop: search for SEQ color for v
		for(int col=1; col<=cmax; col++){
			iscol=g->get_neighbors(v).is_disjoint(0, nBB, m_colsets[col]);	
							
			//color found for vertex
			if(iscol){
				m_colsets[col].set_bit(v);			//if(col>=kmin){//añadir a lista}  no ordena los vertices por color
				break;
			}
		}

		//color not found: new color
		if(!iscol){
			cmax++;
			m_colsets[cmax].erase_bit();			//clears color (previous use in same level)
			m_colsets[cmax].set_bit(v);				//if(col>=kmin){//añadir a lista}  no ordena los vertices por color
		}
	}//pick next vertex to color	

////////////////////////
//copy vertices to child node candidate list sorted by color

	if(kmin<=0) kmin=1;								//if first branch (and no initial UB) kmin=1 so as to copy all nodes	
	for(int col=kmin; col<=cmax; col++){
		m_colsets[col].init_scan(bbo::DESTRUCTIVE);
		while(1){
			if( (v=m_colsets[col].next_bit_del())==EMPTY_ELEM )
						break;

			LISTA_L(depth).nodos[++LISTA_L(depth).index]=v;
			m_lcol[DEPTHPLUS1][v]=col;
		}
	}	

return;
}

template<class T>
void Clique<T>::paint_R (int depth){ 
	struct this_type_is_forbidden_for_paint_R{};		//paint_R only works for ugraph types
}

template<class T>
void Clique<T>::paint_sel (int depth){ 
	struct this_type_is_forbidden_for_paint_sel{};		//paint_R only works for ugraph types
}

template<class T>
void Clique<T>::paint_sel_R (int depth){ 
	struct this_type_is_forbidden_for_paint_sel_R{};		//paint_R only works for ugraph types
}


template<class T>
void Clique<T>::paint_sel_T (int depth){ 
	struct this_type_is_forbidden_for_paint_sel_T{};		//paint_R only works for ugraph types
}

template<> 
inline 
void Clique<ugraph>::paint_sel (int depth){
////////////////
// selective coloring (BBMCL): upruned vertices with labels above kmin are not
// sorted
//
// date: last optimization (23/3/12) in older framework
// OBSERVATIONS:
// 1- Interesting implementation: natural bound to finish coloring when col reaches kmin and there
//    is no need to check that color storage is clean


	int col=0/* important*/, kmin=maxno-depth, nBB=EMPTY_ELEM, v=EMPTY_ELEM; 
	LISTA_L(depth).index=EMPTY_ELEM;

	//copies list of vertices to color (does not count population)
	 m_unsel=LISTA_BB(depth);

	 while(1){
		col++;
		//exit once kmin-1 colors are assigned (first copy remaining vertices as candidates)
		if(col>=kmin){
			m_unsel.init_scan(bbo::DESTRUCTIVE);
			while(1){
				if((v=m_unsel.next_bit_del())==EMPTY_ELEM)
							return; 
				LISTA_L(depth).nodos[++LISTA_L(depth).index]=v;
			}
		}

		//copies to sel
		m_sel=m_unsel;
		m_sel.init_scan(bbo::DESTRUCTIVE);
		while(1){
			v=m_sel.next_bit_del(nBB,m_unsel);
			if(v==EMPTY_ELEM)
	  					break;
			
			//coloring
			m_sel.erase_block(nBB,g->get_neighbors(v));
	
		}
	 }//next color
}

template<> 
inline 
void  Clique<ugraph>::paint_sel_T (int depth){
////////////////
// selective coloring using traditional SEQ (BBMCL_T) 
	
	int col=1; int cmax=1; int kmin=maxno-depth; int nBB=EMPTY_ELEM; int v=EMPTY_ELEM; 
	LISTA_L(depth).index=EMPTY_ELEM;								
	const int K_MINUS_ONE=kmin-1;

	//exit if first branch: copy all child nodes and exit (obligatory check for completeness)
	if(kmin<=1){
		LISTA_BB(depth).init_scan(bbo::NON_DESTRUCTIVE);
		while(1){
			if((v=LISTA_BB(depth).next_bit())==EMPTY_ELEM) return;																	
			LISTA_L(depth).nodos[++LISTA_L(depth).index]=v;
		}
	}
			
	//clears primer color (starts at index 1)
	m_colsets[1].erase_bit();
	
	//outer loop: select a vertex v to color
	bool iscol=false;
	LISTA_BB(depth).init_scan(bbo::NON_DESTRUCTIVE);
	while(1){
		if((v=LISTA_BB(depth).next_bit(nBB))==EMPTY_ELEM)
											break;
		
		//inner loop: search for SEQ color for v
		for(int col=1; col<=cmax; col++){
			iscol=g->get_neighbors(v).is_disjoint(0, nBB, m_colsets[col]);	
							
			//color found for vertex
			if(iscol){
				m_colsets[col].set_bit(v);			//if(col>=kmin){//añadir a lista}  no ordena los vertices por color
				break;
			}
		}

		//color not found: new color
		if(!iscol){
			if(cmax<K_MINUS_ONE){
				cmax++;
				m_colsets[cmax].erase_bit();			//clears color (previous use in same level)
				m_colsets[cmax].set_bit(v);				//if(col>=kmin){//añadir a lista}  no ordena los vertices por color
			}else{
				//exit
				LISTA_L(depth).nodos[++LISTA_L(depth).index/*++*/]=v;
			}
		}
	}//pick next vertex to color	

return;
}

template<>
inline
void Clique<ugraph>::paint_R (int depth){
//////////////////////
// First version: (30-3-12), Update to the new framework (20-04-15)
// paint plus recoloring (independent set implementation, not strictly MCR): builds first Kmin colors and then tries to recolor the rest 
//
// COMMENTS
// Possible trivial customizations:
// 1-Recolor only the first vertex of each color class (or all)
// 2-Coloring from recol-->kmin or viceversa
//
// STATE-OF-THE-ART (4/9/13)
// 1-class coloring implementation for recoloring does not actually attempt simple 'color' as in the original Tomita. Simple coloring is captured implicitly by 
//   the condition pc_swap==0 which indicates that the constraint that vertices are adjacent to at least another vertex with less color does not hold any more
//   because of a previous recolor move. Tomita does not need this since all vertices are 'colored' before a 'recolor' move is attempted. Class coloring does not 'look'
//   at previous color classes

	int col=1; int kmin=maxno-depth; int nBB=EMPTY_ELEM; int v=EMPTY_ELEM;
	LISTA_L(depth).index=EMPTY_ELEM;												
	const int DEPTH_PLUS1=depth+1;
	bool first_color=true;								//flag to color only the first vertex of each color class 
	
	//copies list of vertices to color and stores size for fast empty check 
	int pc=(m_unsel=LISTA_BB(depth)).popcn64();
	
	//CUT based on population size
	if(pc<kmin){
			return;
	}
	
	//main loop
	while(1){
		//sets candidates nodes for coloring from unsel
		m_colsets[col]=m_unsel;
		m_colsets[col].init_scan(bbo::NON_DESTRUCTIVE);
		while(1){
next_v:		v=m_colsets[col].next_bit(nBB, m_unsel);
			if(v==EMPTY_ELEM) break;
///////////////////////////////////////
// RECOLORING ATTEMPT
			
			if( (col>=kmin) && (kmin>=3 /* at least two color classes below*/) && first_color /*selective recolor*/ ){

				for(int recol=1; recol<(kmin-1); recol++){		//loop to find initial color seed
					
					//check if color is valid for swapping (0-1 neighbors)	
					int vswap;
					int pc_swap=m_colsets[recol].single_disjoint(g->get_neighbors(v), vswap);
							
					//analysis
					if(pc_swap==1){	//color class found
																						
						//Busca swap con vertice ya coloreado
						for(int j=recol+1; j<kmin; j++){
					  //for(int j=kmin-1/*1 reverse directon; j>/*=1*/recol; j--){
							if(j==recol) continue;
							
							if( m_colsets[j].is_disjoint(g->get_neighbors(vswap))){
						
								//swap action
								m_colsets[j].set_bit(vswap);
								m_colsets[recol].set_bit(v);
								m_colsets[recol].erase_bit(vswap);
								
								//empty check of unsel in case vertex swapped is the last one
								if((--pc)==0){
									return;
								}else goto next_v;
							}
						}
					}else if(pc_swap==0){					//disjoint color class found (previous swap necessary)
						m_colsets[recol].set_bit(v);
						if((--pc)==0){
							return; 
						}else goto next_v;
					}


				}//next candidate for swap color seed
			}


///////////////////////////////////////
			if(col>=kmin){ 
				LISTA_L(depth).nodos[++LISTA_L(depth).index]=v;
				m_lcol[DEPTH_PLUS1][v]=col;				//labels start at 1	
			}

			if((--pc)==0)
						return;
			//actual coloring
			m_colsets[col].erase_block(nBB,g->get_neighbors(v));
			
			//updates flag for selective recoloring
			first_color=false;	
		}//next vertex
		first_color=true;	
		col++;
	}//next color
}

template<>
inline
void Clique<ugraph>::paint_sel_R (int depth){
//////////////////
// Selective coloring with recoloring 
// date:31/5/13
// last_update: 12/05/15
//
// COMMENTS: attemtps to recolor vertices with label kmin until first failure.
//			 To attempt to recolor all vertices,active while loop (1)

	
	int col=0/* important*/, kmin=maxno-depth, v=EMPTY_ELEM, nBB=EMPTY_ELEM;  
	bool flag_first_time; 
	LISTA_L(depth).index=EMPTY_ELEM;

	//copies list of vertices to color and stores size for fast empty check 
	int pc=(m_unsel=LISTA_BB(depth)).popcn64();

	//***CUT based on population size if(pc<kmin){return;}
	
	while(1){
		col++;
		//threshhold: either recolor or copy to selection list
		//needs to be placed here to catch col=1 and Kmin=0 or Kmin=1 where no recoloring should be done
		if(col>=kmin){	
///////////////////////////////////////////
// RECOLORING ATTEMPT
			if(kmin>=3){

				m_unsel.init_scan(bbo::NON_DESTRUCTIVE);
				//while(1){****}		(1)-attempt all colors
next_v:			v=m_unsel.next_bit();
				if(v==EMPTY_ELEM) break;		//or RETURN

				//recolor v if possible
				for(int recol=1; recol<(kmin-1); recol++){		//loop to find initial color seed
				
					//check if color is valid for swapping (0-1 neighbors)	
					int vswap;
					int pc_swap=m_colsets[recol].single_disjoint(g->get_neighbors(v), vswap);
							
					//analysis
					if(pc_swap==1){	//color class found
																						
						//Busca swap con vertice ya coloreado
						for(int j=recol+1; j<kmin; j++){
					  //for(int j=kmin-1/*1 reverse directon; j>/*=1*/recol; j--){
							if(j==recol) continue;
							
							if( m_colsets[j].is_disjoint(g->get_neighbors(vswap))){
						
								//swap action
								m_colsets[j].set_bit(vswap);
								m_colsets[recol].set_bit(v);
								m_colsets[recol].erase_bit(vswap);
								
								//empty check of unsel in case vertex swapped is the last one
								if((--pc)==0){
									return;
								}else goto next_v;
							}
						}
					}else if(pc_swap==0){					//disjoint color class found (previous swap necessary)
						m_colsets[recol].set_bit(v);
						if((--pc)==0){
							return; 
						}else goto next_v;
					}


				}//next candidate for swap color seed

			}

// END RECOLORING ATTEMPT
//////////////////////////////////////////

			//exit: copy remaining unlabeled vertices
			m_unsel.init_scan(bbo::DESTRUCTIVE);
			while(1){
				v=m_unsel.next_bit_del();
				if(v==EMPTY_ELEM) return;

				//add to candidate list
				LISTA_L(depth).nodos[++LISTA_L(depth).index]=v;
			}

		}//end col>=kmin
		
		//computes color set
		m_colsets[col]=m_unsel;
		m_colsets[col].init_scan(bbo::NON_DESTRUCTIVE);
		bool is_empty_color_set=true;						 //*** comment ***
		while(1){
			v=m_colsets[col].next_bit(nBB, m_unsel);
			if(v==EMPTY_ELEM){
				if(is_empty_color_set) return;		
				break;
			}

			//color as set difference
			m_colsets[col].erase_block(nBB,g->get_neighbors(v));
			is_empty_color_set=false;
		}

	}//next color

}

template<class T>
void Clique<T>::expand(int maxac, typename T::bb_type& l_bb , nodelist_t& l_v){
////////////////////////
// recursive search algorithm

	int v;
//main loop
	res.inc_number_of_steps();

	while(l_v.index>=0){
			
		//Estrategias
		v=l_v.nodos[l_v.index--];

		//cout<<"v:"<<v<<" d:"<<maxac<<endl;

		/*ofstream f("kk.txt", ios::app);
		f<<"v:"<<v<<" d:"<<maxac<<endl;
		f.close();*/

		//CUT by color (since [Konc & Janecic, 2007] this is of limited use (only for first branch))
		if( (m_lcol[maxac][v]+maxac)<=maxno )
				return;
/////////////////////////////////
// CHILD NODE GENERATION
		
		//Node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));		//optimized when place second the bitset with higher population
		
		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(maxac>=maxno){
				maxno=maxac+1;						//NEW GLOBAL OPTIMUM FOUND

				#ifdef STORE_SOLUTION
					res.set_UB(maxno);
					res.clear_all_solutions();
					m_path[maxac]=v;
					res.add_solution(maxno, m_path);
				
					#ifdef VIEW_PROGRESS
						stringstream sstr("");
						res.print_first_sol(sstr);
						LOG_INFO(sstr.str());
					#endif
					
				#endif

				
			}
		l_bb.erase_bit(v);
		continue;
		}
		//approx. coloring (generates child list of nodes in LISTA_L(maxac))
		paint(maxac);

		//cuts if there are no child nodes of v
		if(LISTA_L(maxac).index<0){
			l_bb.erase_bit(v);
			continue;
		}
				
///////////////////////////////////////////////////////
// CANDIDATE EXPANSION

		//sets path
		m_path[maxac]=v;
				
		//Generacion de nuevos nodos
		expand(maxac+1,LISTA_BB(maxac),LISTA_L(maxac));  

		//////////////////////////////////////////////
		// BACKTRACK (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
	}// next node

return;
}

template<class T>
void Clique<T>::expand_sel (int maxac, typename T::bb_type& l_bb , nodelist_t& l_v){
//////////////
// reference BBMCL variant (selective coloring)

	int v;
//main loop
	res.inc_number_of_steps();

	while(l_v.index>=0){
			
		//Estrategias
		v=l_v.nodos[l_v.index--];
		/*ofstream f("kk.txt", ios::app);
		f<<"v:"<<v<<" d:"<<maxac<<endl;
		f.close();*/
				
/////////////////////////////////
// CHILD NODE GENERATION
		
		//Node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));		//optimized when place second the bitset with higher population
		
		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(maxac>=maxno){
				maxno=maxac+1;						//NEW GLOBAL OPTIMUM FOUND

				#ifdef STORE_SOLUTION
					res.set_UB(maxno);
					res.clear_all_solutions();
					m_path[maxac]=v;
					res.add_solution(maxno, m_path);
				
					#ifdef VIEW_PROGRESS
						stringstream sstr("");
						res.print_first_sol(sstr);
						LOG_INFO(sstr.str());
					#endif
					
				#endif

				
			}
		l_bb.erase_bit(v);
		continue;
		}
		//approx. coloring (generates child list of nodes in LISTA_L(maxac))
		paint_sel(maxac);

		//cuts if there are no child nodes of v
		if(LISTA_L(maxac).index<0){
			l_bb.erase_bit(v);
			continue;
		}
				
///////////////////////////////////////////////////////
// CANDIDATE EXPANSION

		//sets path
		m_path[maxac]=v;
				
		//Generacion de nuevos nodos
		expand_sel(maxac+1,LISTA_BB(maxac),LISTA_L(maxac));  

		//////////////////////////////////////////////
		// BACKTRACK (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
	}// next node

return;
}

template<class T>
void Clique<T>::expand_sel_R (int maxac, typename T::bb_type& l_bb , nodelist_t& l_v){
//////////////
// reference BBMCL_R variant (selective coloring + recoloring (only until first failure))
// original date: 31/5/13
// last_update: 12/05/15
	
	int v;
//main loop
	res.inc_number_of_steps();

	while(l_v.index>=0){
			
		//Estrategias
		v=l_v.nodos[l_v.index--];
		/*ofstream f("kk.txt", ios::app);
		f<<"v:"<<v<<" d:"<<maxac<<endl;
		f.close();*/
				
/////////////////////////////////
// CHILD NODE GENERATION
		
		//Node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));		//optimized when place second the bitset with higher population
		
		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(maxac>=maxno){
				maxno=maxac+1;						//NEW GLOBAL OPTIMUM FOUND

				#ifdef STORE_SOLUTION
					res.set_UB(maxno);
					res.clear_all_solutions();
					m_path[maxac]=v;
					res.add_solution(maxno, m_path);
				
					#ifdef VIEW_PROGRESS
						stringstream sstr("");
						res.print_first_sol(sstr);
						LOG_INFO(sstr.str());
					#endif
					
				#endif
			}
		l_bb.erase_bit(v);
		continue;
		}
		//approx. coloring (generates child list of nodes in LISTA_L(maxac))
		paint_sel_R(maxac);

		//cuts if there are no child nodes of v
		if(LISTA_L(maxac).index<0){
			l_bb.erase_bit(v);
			continue;
		}
				
///////////////////////////////////////////////////////
// CANDIDATE EXPANSION

		//sets path
		m_path[maxac]=v;
				
		//Generacion de nuevos nodos
		expand_sel_R(maxac+1,LISTA_BB(maxac),LISTA_L(maxac));  

		//////////////////////////////////////////////
		// BACKTRACK (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
	}// next node

return;
}

template<class T>
void Clique<T>::expand_R (int maxac, typename T::bb_type& l_bb , nodelist_t& l_v){
////////////////////////
// recursive search algorithm with recoloring
	
	int v;
//main loop
	res.inc_number_of_steps();

	while(l_v.index>=0){
			
		//Estrategias
		v=l_v.nodos[l_v.index--];
		/*ofstream f("kk.txt", ios::app);
		f<<"v:"<<v<<" d:"<<maxac<<endl;
		f.close();*/

		//CUT by color (since [Konc & Janecic, 2007] this is of limited use (only for first branch))
		if( (m_lcol[maxac][v]+maxac)<=maxno )
				return;
/////////////////////////////////
// CHILD NODE GENERATION
		
		//Node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));		//optimized when place second the bitset with higher population
		
	
		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(maxac>=maxno){
				maxno=maxac+1;						//NEW GLOBAL OPTIMUM FOUND

				#ifdef STORE_SOLUTION
					res.set_UB(maxno);
					res.clear_all_solutions();
					m_path[maxac]=v;
					res.add_solution(maxno, m_path);
				
					#ifdef VIEW_PROGRESS
						stringstream sstr("");
						res.print_first_sol(sstr);
						LOG_INFO(sstr.str());
					#endif
					
				#endif

				
			}
		l_bb.erase_bit(v);
		continue;
		}

		//approx. coloring (generates child list of nodes in LISTA_L(maxac))
		paint_R(maxac);
	
		//cuts if there are no child nodes of v
		if(LISTA_L(maxac).index<0){
			l_bb.erase_bit(v);
			continue;
		}
				
///////////////////////////////////////////////////////
// CANDIDATE EXPANSION

		//sets path
		m_path[maxac]=v;
				
		//Generacion de nuevos nodos
		expand_R(maxac+1,LISTA_BB(maxac),LISTA_L(maxac));  

		//////////////////////////////////////////////
		// BACKTRACK (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
	}// next node

return;
}

template<class T>
void Clique<T>::expand_T(int maxac, typename T::bb_type& l_bb , nodelist_t& l_v){
////////////////////////
// bbmc with non independent set SEQ coloring 
// date of creation: 20/03/15

	int v;
//main loop
	res.inc_number_of_steps();

	while(l_v.index>=0){
			
		//Estrategias
		v=l_v.nodos[l_v.index--];

		//CUT by color (since [Konc & Janecic, 2007] this is of limited use (only for first branch))
		if( (m_lcol[maxac][v]+maxac)<=maxno )
				return;
/////////////////////////////////
// CHILD NODE GENERATION
		
		//Node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));		//optimized when placed second the bitset with higher population
		
		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(maxac>=maxno){
				maxno=maxac+1;						//NEW GLOBAL OPTIMUM FOUND

				#ifdef STORE_SOLUTION
					res.set_UB(maxno);
					res.clear_all_solutions();
					m_path[maxac]=v;
					res.add_solution(maxno, m_path);
				
					#ifdef VIEW_PROGRESS
						stringstream sstr("");
						res.print_first_sol(sstr);
						LOG_INFO(sstr.str());
					#endif
					
				#endif
			}
		l_bb.erase_bit(v);
		continue;
		}
		//approx. coloring (generates child list of nodes in LISTA_L(maxac))
		paint_T(maxac);

		//cuts if there are no child nodes of v
		if(LISTA_L(maxac).index<0){
			l_bb.erase_bit(v);
			continue;
		}
				
///////////////////////////////////////////////////////
// CANDIDATE EXPANSION

		//sets path
		m_path[maxac]=v;
				
		//Generacion de nuevos nodos
		expand_T(maxac+1,LISTA_BB(maxac),LISTA_L(maxac));  

		//////////////////////////////////////////////
		// BACKTRACK (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
	}// next node

return;
}

template<class T>
void  Clique<T>::expand_sel_T (int maxac, typename T::bb_type& l_bb , nodelist_t& l_v){
///////////////
// reference BBMCL variant (selective coloring) with classical SEQ (non independent set coloring)

	int v;
//main loop
	res.inc_number_of_steps();

	while(l_v.index>=0){
			
		//Estrategias
		v=l_v.nodos[l_v.index--];
		/*ofstream f("kk.txt", ios::app);
		f<<"v:"<<v<<" d:"<<maxac<<endl;
		f.close();*/
				
/////////////////////////////////
// CHILD NODE GENERATION
		
		//Node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));		//optimized when place second the bitset with higher population
		
		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(maxac>=maxno){
				maxno=maxac+1;						//NEW GLOBAL OPTIMUM FOUND

				#ifdef STORE_SOLUTION
					res.set_UB(maxno);
					res.clear_all_solutions();
					m_path[maxac]=v;
					res.add_solution(maxno, m_path);
				
					#ifdef VIEW_PROGRESS
						stringstream sstr("");
						res.print_first_sol(sstr);
						LOG_INFO(sstr.str());
					#endif
					
				#endif
			
			}
		l_bb.erase_bit(v);
		continue;
		}

		//approx. coloring (generates child list of nodes in LISTA_L(maxac))
		paint_sel_T(maxac);

		//cuts if there are no child nodes of v
		if(LISTA_L(maxac).index<0){
			l_bb.erase_bit(v);
			continue;
		}
				
///////////////////////////////////////////////////////
// CANDIDATE EXPANSION

		//sets path
		m_path[maxac]=v;
				
		//Generacion de nuevos nodos
		expand_sel_T(maxac+1,LISTA_BB(maxac),LISTA_L(maxac));  

		//////////////////////////////////////////////
		// BACKTRACK (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
	}// next node

return;
}

template<class T>
inline
int Clique<T>::set_up(){
//////////////
// allocates memory, evaluates initial bounds and determines 
// initial trivial solutions
//
// RETURN VALUE: -1 Error, 0-ok, >0 trivial solution found
	res.clear();
	d.clear();
	res.set_name(g->get_name());

	//determine allocation info
	search_alloc_t info;			//loads BBMC configuration for search allcoation
	switch(param.alg){
	case BBMC:
		break;
	case BBMC_T:
	case BBMCR:
		info.set(search_alloc_t::ALLOC_COLOR_SETS);
		break;
	case BBMCL:
		info.remove(search_alloc_t::ALLOC_COLOR_LABELS);		//no color labels or sets
		break;
	case BBMCL_R:
		info.set(search_alloc_t::ALLOC_COLOR_SETS);			
		break;
	case BBMCL_T:
		info.remove(search_alloc_t::ALLOC_COLOR_LABELS);		//no color labels or sets
		info.set(search_alloc_t::ALLOC_COLOR_SETS);				//requires auxiliary color sets for classical SEQ
		break;
	default:
		LOG_ERROR("set_up: unknown algorithm");
		return -1;
	}
	
	//actual set_up
	int sol=0;
	if(param.unrolled){
		if((sol=set_up_unrolled(info))>0){ 
			res.set_UB(sol);
		}
	}else{
		 if( (sol=set_up_non_unrolled(info))>0 ){
				res.set_UB(sol);
		}
	}	
	
	if(sol>0){
		LOG_INFO("[w="<<sol<<"]"<<" TRIVIALLY SOLVED DURING PRECOMPUTATION");
	}

	return sol;
}

template<class T>
void Clique<T>::run(){
	//algorithm
	if(param.unrolled){
		res.tic();
		run_unrolled();
		res.toc();
	}else{
		res.tic();
		run_non_unrolled();
		res.toc();
	}

	//read solution
	res.set_UB(maxno);
	LOG_INFO("[w:"<<res.get_upper_bound()<<","<<res.get_user_time()<<"s]");
}

template<class T>
void Clique<T>::run_unrolled(){
////////////////
// runs search unrolling first level
	
	//algorithm selection
	switch(param.alg){
	case BBMC:
		initial_expand(&Clique<T>::expand);
		break;
	case BBMC_T:
		initial_expand(&Clique<T>::expand_T);
		break;
	case BBMCR:
		initial_expand(&Clique<T>::expand_R);
		break;
	default:
		LOG_ERROR("run-unrolled:unknown clique algorithm");
	}
}

template<class T>
void Clique<T>::run_non_unrolled (){
////////////////
// runs normal search (non-unrolling of first level)
	
	//algorithm selection
	switch(param.alg){
	case BBMC:
		expand(0, m_bbroot, m_lroot);
		break;
	case BBMC_T:
		expand_T(0, m_bbroot, m_lroot);
		break;
	case BBMCR:
		expand_R(0, m_bbroot, m_lroot);
		break;
	case BBMCL:
		expand_sel(0, m_bbroot, m_lroot);
		break;
	case BBMCL_T:
		expand_sel_T(0, m_bbroot, m_lroot);
		break;
	case BBMCL_R:
		expand_sel_R(0, m_bbroot, m_lroot);
		break;
	default:
		LOG_ERROR("run-non_unrolled:unknown clique algorithm");
	}
}


template<>
inline
int Clique<ugraph>::set_up_subgraph (bitarray& bbs, search_alloc_t* pinfo){
///////////////
// allocates memory and computes feasible solution and bounds

	if(pinfo!=NULL){
		if(allocate(*pinfo)==-1) return -1;
	}
		
	get_result().clear();
	compute_initial_sol(bbs);
	compute_upper_bounds(bbs);
	
	int lb=get_result().get_lower_bound();
	int ub=get_result().get_upper_bound();
//	cout<<"LB:"<<lb<<" UB:"<<ub<<endl;
	
	if(ub<=lb){
		get_result().set_UB(get_result().get_lower_bound());
		LOG_INFO("TRIVIAL SOLUTION FOUND: "<<lb);
		return lb;
	}

	return 0;
}

template<class T>
inline
int Clique<T>::set_up_subgraph (typename T::bb_type& bbs, search_alloc_t* pinfo){
///////////////
// allocates memory and computes feasible solution and bounds
	struct set_up_subgraph_not_allowed_for_this_type {};
	return 0;
}

template<class T>
inline
void Clique<T>::run_subgraph (typename T::bb_type& bbs){
////////////////
// runs normal search for the subgraph passed (non-unrolling of first level)
// first update: 9/11/16
//
// REMARKS
// Do not use with set_up framework. Do manual setup
	
	maxno=get_result().get_lower_bound();
	m_bbroot=bbs;
	m_lroot.index=-1;
	bbs.init_scan(bbo::NON_DESTRUCTIVE);
	while(true){
		int v=bbs.next_bit();
		if(v==EMPTY_ELEM) break;
		m_lroot.nodos[++m_lroot.index]=v;
	}
		
	//algorithm selection
	switch(param.alg){
	case BBMC:
		expand(0, m_bbroot, m_lroot);
		break;
	case BBMC_T:
		expand_T(0, m_bbroot, m_lroot);
		break;
	case BBMCR:
		expand_R(0, m_bbroot, m_lroot);
		break;
	case BBMCL:
		expand_sel(0, m_bbroot, m_lroot);
		break;
	case BBMCL_T:
		expand_sel_T(0, m_bbroot, m_lroot);
		break;
	case BBMCL_R:
		expand_sel_R(0, m_bbroot, m_lroot);
		break;
	default:
		LOG_ERROR("run-non_unrolled:unknown clique algorithm");
	}

	res.set_UB(maxno);
}


template<class T>
inline
void Clique<T>::run_subgraph_with_ordering (typename T::bb_type& bbs, clqo::init_order_t o, gbbs::place_t p){
	struct run_subgraph_not_allowed_for_this_type {};
}

template<>
inline
void Clique<ugraph>::run_subgraph_with_ordering (bitarray& bbs, clqo::init_order_t o, gbbs::place_t p){
////////////////
// runs max clique for subgraph bbs ordered according to parameters o and p
	
	maxno=get_result().get_lower_bound();
	m_bbroot=bbs;
	if(sort_root_subgraph(bbs, o, p)==-1){
		LOG_ERROR("Clique<T>::run_subgraph-unable to sort root subraph");
	}else{

		//algorithm selection
		switch(param.alg){
		case BBMC:
			expand(0, m_bbroot, m_lroot);
			break;
		case BBMC_T:
			expand_T(0, m_bbroot, m_lroot);
			break;
		case BBMCR:
			expand_R(0, m_bbroot, m_lroot);
			break;
		case BBMCL:
			expand_sel(0, m_bbroot, m_lroot);
			break;
		case BBMCL_T:
			expand_sel_T(0, m_bbroot, m_lroot);
			break;
		case BBMCL_R:
			expand_sel_R(0, m_bbroot, m_lroot);
			break;
		default:
			LOG_ERROR("run-non_unrolled:unknown clique algorithm");
		}

	res.set_UB(maxno);
	}
}

template <typename T>
inline
int Clique<T>::sort_root_subgraph (typename T::bb_type& bbs, clqo::init_order_t o, gbbs::place_t p){
	struct sort_root_subgraph_not_allowed_for_this_type {};
	return 0;
}

template <>
inline
int Clique<ugraph>::sort_root_subgraph (bitarray& bbs, clqo::init_order_t o, gbbs::place_t p){
////////////////////
//orders list of nodes at root according to the specified criteria
// 
// RETURNS -1 if the list is empty, 0 if ok

	CliqueSort<ugraph> s(*g);
	vint vord=s.new_subg_order(o, bbs, p);
	if(vord.empty()){
		LOG_ERROR("Clique<ugraph>::sort_root_subgraph produced empty list");
		return -1;
	}

	copy(vord.begin(), vord.end(), m_lroot.nodos);
	m_lroot.index=vord.size()-1;
	return 0;
}


template<>
inline
int Clique<ugraph>::compute_initial_sol (bitarray& bbs){
///////////////////////
// Basic clique heuristic for any subgraph

	bitarray bb(bbs);
	int* sol=new int[g->number_of_vertices()]; int psol=0;
	const int nBB=bbs.number_of_bitblocks();
	bb.init_scan(bbo::DESTRUCTIVE);
	while(true){
		int v=bb.next_bit_del();
		if(v==EMPTY_ELEM) break;
		bb&=g->get_neighbors(v);
		sol[psol++]=v;
	}

	//*** store solution
	get_result().clear_all_solutions();
	get_result().add_solution(psol, sol);
	get_result().set_LB(psol);
			
	delete [] sol;
	return psol;
}


template<class T>
inline
int Clique<T>::compute_initial_sol (typename T::bb_type& bbs){
	struct compute_initial_sol{};
	return 0;
}


template<>
inline
int Clique<ugraph>::compute_upper_bounds (bitarray& bbs){
//////////////////////
// computes oriented bounds for the subgraph bbs
//
// DELETED!

	return 0;
}


template<class T>
inline
int Clique<T>::compute_upper_bounds (typename T::bb_type& bbs){
	struct this_type_is_not_possible_for_compute_upper_bounds{};
	return 0;	
}

template<class T>
void Clique<T>::initial_expand(func f){
////////////////////
// Unrolling of first level
//
// TODO: simple coloring of each subproblem with vertices sorted in min-width order

	CliqueSort<T> o(*g);
	InitColor<T> cinit(*g);
	res.inc_number_of_steps();
		
	//Loop over neighbor set subproblems
	for(int v=m_size-1; v>=maxno; v--){
		LISTA_BB(0).init_bit(v,g->get_neighbors(v));
				
		//CUT related to size: possibly remove?
		if(LISTA_BB(0).popcn64()<maxno){
			continue;
		}

		//CUT related to color: too expensive?

		//order LISTA_BB by root ordering strategy and simple initial coloring
		LISTA_L(0).index=-1;
		vint new_ord=o.new_subg_order(param.init_order, LISTA_BB(0), (param.init_order==NONE)? gbbs::PLACE_FL : gbbs::PLACE_LF);
		if(new_ord.empty()) return;
		int gdeg=g->max_degree_of_subgraph(LISTA_BB(0));
		for(int i=0; i<new_ord.size(); i++){
			 LISTA_L(0).nodos[++LISTA_L(0).index]=new_ord[i];
			 m_lcol[1][new_ord[i]]=(i<=gdeg)? i+1 : gdeg+1;		//simple initial coloring
		}
		
		//Search
		m_path[0]=v;
		(this->*f)(1,LISTA_BB(0),LISTA_L(0));								
	}
}

template<>
inline void Clique<sparse_ugraph>::initial_expand(func f){
////////////////////
// unrolling of first level

	int v=EMPTY_ELEM;
	KCore<sparse_ugraph> kc(*g);
	InitColor<sparse_ugraph> cinit(*g);
		
	//Loop over neighbor set subproblems
	for(int v=m_size-1; v>=0; v--){
		LISTA_BB(0).init_bit(v,g->get_neighbors(v));
				
		//CUT related to size
		if(LISTA_BB(0).popcn64()<maxno){
			continue;
		}

		//COLOR CUT of this subproblem
		if(cinit.greedyIndependentSetColoring(LISTA_BB(0))<maxno){
		//	cout<<"PODA COLOR SUBPROBLEMA:"<<col<<endl;
			continue;
		}
				
		//kcore computation
		LISTA_BB(0).set_bit(v);								//add bit for kcore analysis only		
		kc.set_subgraph(&LISTA_BB(0));
		kc.kcore(); 

		//kcore graph number cut
		if(kc.get_kcore_number()<maxno){
			//	cout<<"PODA KCORE GRAPH:"<<col<<endl;
			continue;
		}
		
		//KCore cut
		LISTA_L(0).index=-1;
		const vint& kcn=kc.get_kcore_numbers();
		const vint& kcv=kc.get_kcore_ordering();
		for(int i=kcv.size()-1; i>=0; i--){
			if(kcn[kcv[i]]<maxno){
				//KCore cut for the subproblem
				for(int j=i; j>=0; j--){
					LISTA_BB(0).erase_bit(kcv[j]);		//O(logn) operation
				}
				break;
			}else{
				//add to candidate list for expansion
				if(kcv[i]!=v){
					LISTA_L(0).nodos[++LISTA_L(0).index]=kcv[i];
					m_lcol[1][kcv[i]]=kcn[kcv[i]]+1;		
				}
			}
		}
	
//Expansion as in BBMC in minimum width order
		
		LISTA_BB(0).erase_bit(v);
		m_path[0]=v;
		(this->*f)(1,LISTA_BB(0),LISTA_L(0));		//Note: LISTA_L should not be empty: it would have been detected in KCORE-GRAPH CUT
	
// BACKTRACK  from v: vertex already deleted at the beginning of the iterations
	}
}

template<class T>
void Clique<T>::print_filter (ostream& o){
	for(map<int, int>::iterator it= m_filter.begin(); it!=m_filter.end(); ++it){
		o<<"["<<it->first<<","<<it->second<<"]"<<" "; 
	}
	o<<endl;
}

template <class T>
int Clique<T>::set_up_non_unrolled(search_alloc_t info){
////////////////////////
// non unrolled setup configuration.
// 1-memory allocation
// 2-initial lower bound computation based on kcore
// 3-initial upperbound computation based on kcore
	
	PrecisionTimer pt;
	LOG_PRINT("INIT SETUP NON_UNROLLED");
	int ub=param.ub; 
	int lb=param.lb;
	
	
	//initial reordering of adjacency matrix following degeneracy
	if(param.init_order!=NONE && param.isomorphism==false){
		LOG_PRINT("initial ordering----------------");
		CliqueSort<T> o(*g);
		if(param.init_order==MIXED_2 ||  param.init_order==MIXED_4 || param.init_order==MIXED_6 || param.init_order==MIXED_8 || param.init_order==MIXED_10) {
			typename CliqueSort<T>::vpclq lord;
			lord.push_back( pair< init_order_t, gbbs::place_t>(param.init_order, gbbs::PLACE_LF) );
			o.reorder_composite(lord, get_decoder());
		}else if(param.init_order==MIN_WIDTH_COMPOSITE){		/*9/09/16*/	
			typename CliqueSort<T>::vpclq lord;
			lord.push_back( pair< init_order_t, gbbs::place_t>(clqo::MIN_WIDTH_MIN_TIE_STATIC, gbbs::PLACE_FL) );
			lord.push_back( pair< init_order_t, gbbs::place_t>(clqo::MIN_WIDTH, gbbs::PLACE_LF) );
			o.reorder_composite(lord, get_decoder());
		}else if(param.init_order==RLF_SORT_DOLL || param.init_order==RLF_SORT_BBMC){		/*2/10/16: TODO:CHECK*/	
			LOG_INFO("starting RLF_SORT ordering");
			vint col;
			//manually decide if the initial ordering of vertices in the complement graph
			if(o.reorder( o.new_order(param.init_order, gbbs::place_t::PLACE_FL /* not used here*/, &col), get_decoder())==-1){
				LOG_ERROR("set_up_unrolled: error during reordering");
				return -1;
			}
			clqo::init_order_t io;
			gbbs::place_t place;
			if(param.init_order==RLF_SORT_DOLL){
				io=clqo::init_order_t::MAX_WIDTH;
				place=gbbs::place_t::PLACE_FL;
			}else if(param.init_order==RLF_SORT_DOLL){
				io=clqo::init_order_t::MIN_WIDTH;
				place=gbbs::place_t::PLACE_LF;
			}

			//second stage
			if(!col.empty()){
				LOG_INFO("starting ordering inside color classes");
				if(o.reorder(o.new_color_set_order(io,col,place), get_decoder())==-1 ){
					LOG_ERROR("set_up_unrolled: error during RLF_SORT reordering");
					return -1;
				}
			}
			LOG_INFO("-----------------------------------");
		}else if(param.init_order==MIN_WEIGHTED){		
			typename CliqueSort<T>::vpclq lord;
			lord.push_back( pair< init_order_t, gbbs::place_t>(clqo::MAX_ABS, gbbs::PLACE_LF) );
			lord.push_back( pair< init_order_t, gbbs::place_t>(clqo::MIN_WEIGHTED, gbbs::PLACE_FL) );
			o.reorder_composite(lord, get_decoder());
		}else if(param.init_order==MAX_WEIGHTED){			//default choice: max_weight with a max_deg flavour (4/7/17- conception of CliqueWeightedPlus)
			typename CliqueSort<T>::vpclq lord;
			lord.push_back( pair< init_order_t, gbbs::place_t>(clqo::MIN_WIDTH, gbbs::PLACE_LF) );
			lord.push_back( pair< init_order_t, gbbs::place_t>(clqo::MAX_WEIGHTED, gbbs::PLACE_FL) );
			o.reorder_composite(lord, get_decoder());
		}else if(param.init_order==MIN_WEIGHTED_DEG){		
			typename CliqueSort<T>::vpclq lord;
			lord.push_back( pair< init_order_t, gbbs::place_t>(clqo::MAX_ABS, gbbs::PLACE_FL) );
			lord.push_back( pair< init_order_t, gbbs::place_t>(clqo::MIN_WEIGHTED_DEG, gbbs::PLACE_FL) );
			o.reorder_composite(lord, get_decoder());
		}else if(param.init_order==MAX_WEIGHTED_DEG){		
			typename CliqueSort<T>::vpclq lord;
			lord.push_back( pair< init_order_t, gbbs::place_t>(clqo::MAX_ABS, gbbs::PLACE_FL) );
			lord.push_back( pair< init_order_t, gbbs::place_t>(clqo::MAX_WEIGHTED_DEG, gbbs::PLACE_FL) );
			o.reorder_composite(lord, get_decoder());
		}else if(o.reorder( o.new_order(param.init_order, (param.init_order==NONE)? gbbs::PLACE_FL : gbbs::PLACE_LF), get_decoder())==-1){
			LOG_ERROR("set_up_unrolled: error during reordering");
			return -1;
		}

		LOG_PRINT("------------------------------------");
	}
	
	
	//initial bounds
	int sol;
	if((sol=initial_bounds(lb, ub))>0){
		return sol;
	}
	LOG_INFO("w:["<<lb<<","<<ub<<"]");
		
				
	//init search allocation: generalized to weights
	if(g->is_weighted_v()){
			info.size=g->number_of_vertices();				//**TODO- ub would be good here to reduce allocation
	}else info.size=ub;
	if(search_allocation(info)==-1) return -1;
		
	//initial simple coloring (not for weighted graphs-(10/10/16) )
	if(info.is_set(search_alloc_t::ALLOC_COLOR_LABELS) && !g->is_weighted_v() ){
		LOG_PRINT("initial simple coloring----------------");
		InitColor<T> cinit(*g);
		cinit.simpleDegreeColoring(m_lcol[0]);
		LOG_PRINT("--------------------------------------");
		LOG_PRINT("END OF SETUP NON_UNROLLED");
	}

	//updates initial solution for search
	maxno=lb;
	res.set_LB(lb);
	return 0;
}

template <class T>
int Clique<T>::set_up_unrolled(search_alloc_t info){
///////
// set up for the general purpose unrolled case (non sparse graphs, i.e. DIMACS)
// NOTES:
// Similar to the non_unrolled case but without coloring the root graph

	LOG_PRINT("INIT SETUP UNROLLED");
	int ub=param.ub; 
	int lb=param.lb;
	
	//initial ordering
	LOG_PRINT("init ordering----------");
	CliqueSort<T> o(*g);	
	if(o.reorder(o.new_order(param.init_order, (param.init_order==NONE)? gbbs::PLACE_FL : gbbs::PLACE_LF), get_decoder())==-1){
		LOG_ERROR("set_up_unrolled: error during reordering");
		return -1;
	}
	LOG_PRINT("------------------------------------");

	//initial bounds
	int sol;
	if((sol=initial_bounds(lb, ub))>0){
		return sol;
	}
	LOG_INFO("w:("<<lb<<","<<ub<<")");	


	//init search memory allocation
	info.size=ub;
	if(search_allocation(info)==-1) return -1;

	LOG_PRINT("END OF SETUP UNROLLED");

	//updates initial solution for search
	maxno=lb;
	res.set_LB(lb);

	return 0;
}

template<class T>
int Clique<T>::allocate (search_alloc_t info){
/////////////////
// manual allocation of data structures as configured in info
//
// RETURNS -1 if ERROR, 0 if OK

	//allocation
	clear_all();
	info.size=g->number_of_vertices();
	return search_allocation(info);
}

template<class T>
bool Clique<T>::is_clique (typename T::bb_type& bb) const {
////////////////
// TRUE if bitstring bb clique (empty clique is not a clique)
//
// REMARKS: bb should have capacity for the number of vertices of the graph
	
	typename T::bb_type neighbor(g->number_of_vertices());
	if(bb.init_scan(bbo::NON_DESTRUCTIVE)==EMPTY_ELEM) return false;	//empty cliqe
	while(true){
		int v=bb.next_bit();
		if (v==EMPTY_ELEM) break;

		//check neighborhood						***experimental***
		AND(g->get_neighbors(v), bb, neighbor);
		neighbor.set_bit(v);
		if(!(bb==neighbor)) 
					return false; 
						
	}
return true;		//is clique
}


template<class T>
bool Clique<T>::is_clique (vint & v) const {
////////////////
// TRUE if bitstring bb clique (empty clique is not a clique)
//
	if (v.empty()) return false;
	
	//copies the set of vertices to a bitstring with capacity for all vertices
	typename T::bb_type bb(g->number_of_vertices());
	for(vint::iterator it=v.begin(); it!=v.end(); it++){
		 bb.set_bit(*it);
	}

return is_clique(bb);   		
}

template<>
inline void Clique<sparse_ugraph>::paint (int depth){
///////////////////
// Sequential greedy independent set vertex coloring to prune the search tree

	int col=1, kmin=maxno-depth, nBB=EMPTY_ELEM, v=EMPTY_ELEM;					// color labels start at 1	(col)
	LISTA_L(depth).index=EMPTY_ELEM;											//cleans the set fo candidate vertices
	const int DEPTH_PLUS1=depth+1;
	
	//copies list of vertices to color and stores size for fast empty check 
	int pc=LISTA_BB(depth).popcn64();

	//cut on population 
	if(pc<kmin){
		LOG_DEBUG("SIZE CUT-----------------");
		return;
	}

	m_unsel=LISTA_BB(depth);
	while(true){ 
		sparse_bitarray::velem_it it=m_unsel.begin();
		m_sel=m_unsel;
		m_sel.init_scan(bbo::DESTRUCTIVE);										//no need to check if m_sel is empty (it cannot be)
		while(true){
			v=m_sel.next_bit_del_pos(nBB);
			//v=m_sel.next_bit_del(nBB);
			if(v==EMPTY_ELEM) 
				break;
			it=m_unsel.erase_bit(v,it);											//optimization because vertices selected are in order
			if(col>=kmin){  
				LISTA_L(depth).nodos[++LISTA_L(depth).index]=v;
				m_lcol[DEPTH_PLUS1][v]=col;						
			}
			if((--pc)==0) 
						return;
			//m_sel.erase_block(nBB,g.get_neighbors(v));
			m_sel.erase_block_pos(nBB,g->get_neighbors(v));
		}				
	col++;
	}
}

template<class T>
void Clique<T>::filter_heur(int maxno, typename T::bb_type& l_bb , nodelist_t& l_v){
///////////////////////
// KCore filter (experimental)
	
	int vfilter=EMPTY_ELEM;
	if(m_filter.count(maxno))
			 vfilter=m_filter[maxno];
	else return;

	//remove all vertices from bitstring list of vertices
	//l_bb.erase_bit(vfilter, m_size);
	l_bb.clear_bit(vfilter, EMPTY_ELEM);
	
	//update conventional list of vertices
	int v=EMPTY_ELEM, i=0;
	if(l_bb.init_scan(bbo::NON_DESTRUCTIVE)!=EMPTY_ELEM){
		while(true){
			v=l_bb.next_bit();
			if(v==EMPTY_ELEM) break;
			l_v.nodos[i++]=v;
		}
	}

	//sets index of last vertex in the list
	l_v.index=i-1;
}

template<class T>
void Clique<T>::filter_heur_shrink	(int maxno){
///////////////////
// shrinks graph
		
	int level=maxno;
	do{
		if(m_filter.count(level)){
			int new_size=m_filter[level];				//and not: int new_size=m_filter[maxno]-1; which is not complete
			g->shrink_to_fit(new_size);
			m_size=new_size;
			LOG_DEBUG("new size of graph: "<<new_size);
			return;
		}
		level--;
	}while(level>1);
	
	return;
}

template<>
inline
int Clique<sparse_ugraph>::set_up_unrolled(search_alloc_t info){
/////////////////
// set up for the unrolled case (specialization for sparse graphs which is the typical application)
//
// Comments: Compared with standard (non_unrolled) variant:
// 1-Uses initial kcore filter to shrink the graph as much as possible
// 2-uses initial lower bound heuristic optimized for large sparse graphs
		
	PrecisionTimer pt;
	int ub=param.ub; 
	int lb=param.lb;
	LOG_PRINT("INIT SETUP SPARSE UNROLLED--WILL SHRINK INITIAL GRAPH");

	//initial kcore bounds and kcore filter
	//pt.wall_tic();
	KCore<sparse_ugraph> kc(*g);
	int ub_kc, lb_kc, sol;
	if( (sol=initial_bounds(lb, ub, &kc)) >0){
		return sol;
	}
	LOG_INFO("w:("<<lb<<","<<ub<<")");
	//cout<<"[t:"<<pt.wall_toc()<<"]"<<endl;
	
	//Initial order (MWS-kcore based)
	LOG_PRINT("init degeneracy reordering----------------");
	CliqueSort<sparse_ugraph> o(*g);	
	const vint& kco=kc.get_kcore_ordering();
	vint old2new(kco.size());
	int l=0;
	for(vint::const_reverse_iterator it=kco.rbegin(); it!=kco.rend(); ++it){
		old2new[*it]=l++;
	}
		
	LOG_DEBUG("degeneracy reordering: init in place reordering---------------");
	o.reorder_in_place(old2new);	//efficient in space requirements, used for very large sparse graphs
		
	//shrinks graph
	LOG_DEBUG("init graph reduction----------------");
	filter_heur_shrink(lb);
		
	//Init over the new graph (shrinked)
	LOG_PRINT("init search allocation----------------");
	info.size=ub;
	if(search_allocation(info)==-1) return -1;

	LOG_PRINT("END OF SETUP UNROLLED");

	//update search parameters
	maxno=lb;
	res.set_LB(lb);

return 0;
}

#endif
