//graph_map.h: conversions between two isomporphic graphs encoded by GRAPH
//first_date:14/8/17

#ifndef __GRAPH_ISOMORPHISM_MAPPINGS_H__
#define	__GRAPH_ISOMORPHISM_MAPPINGS_H__

#include <iostream>
#include <algorithm>
#include <vector>
#include "../graph.h"
#include "../../utils/logger.h"
#include "../../utils/common.h"

using namespace std;
typedef vector<int> vint;


class GraphMap{
///////////////
//interface	
public:
	enum print_t {L2R=0, R2L, ALL};
	int size()						{return l2r.size();}
	vint get_l2r()					{return l2r;}	
	vint get_r2l()					{return r2l;}	

////////////////
//mapping 
	int map_l2r(int v)const				{return l2r[v]; } 
	int map_r2l(int v)const				{return r2l[v]; } 
	template<class bitstring_t>
	bitstring_t& map_l2r(bitstring_t& bbl, bitstring_t& bbr) const;
	template<class bitstring_t>
	bitstring_t& map_r2l(bitstring_t& bbl, bitstring_t& bbr) const;
	template<class bitstring_array_t>
	bitstring_array_t& map_l2r(bitstring_array_t& bbl, bitstring_array_t& bbr, int from, int to) const;		/* range includes both ends */
	template<class bitstring_array_t>
	bitstring_array_t& map_r2l(bitstring_array_t& bbl, bitstring_array_t& bbr, int from, int to) const;		/* range includes both ends */
////////////////////

	//build driver
	template<class Graph_t>
	int build_mapping(Graph_t&, gbbs::sort_t lhs_s, gbbs::place_t lhs_p, gbbs::sort_t rhs_s, gbbs::place_t rhs_p, 
						string lhs_name="", string rhs_name="");			
	
	//I/O
	ostream& print_mappings(print_t type=ALL, ostream& o=cout);
	ostream& print_names(print_t type=ALL, ostream& o=cout);

protected:
	void init(int NV, int val)		{l2r.assign(NV, val); r2l.assign(NV, val); name_l.clear(); name_r.clear();}
	bool is_consistent();

////////////////
// state
	vint l2r, r2l;					//mapping
	string name_l;
	string name_r;
};

template<class bitstring_t>
inline
bitstring_t& GraphMap::map_l2r(bitstring_t& bbl, bitstring_t& bbr) const{
	bbr.erase_bit();
	bbl.init_scan(bbo::NON_DESTRUCTIVE);
	while(true){
		int v=bbl.next_bit();
		if(v==EMPTY_ELEM) break;
		bbr.set_bit(l2r[v]);
	}
	return bbr;
}

template<class bitstring_t>
inline
bitstring_t& GraphMap::map_r2l(bitstring_t& bbl, bitstring_t& bbr) const{
	bbl.erase_bit();
	bbr.init_scan(bbo::NON_DESTRUCTIVE);
	while(true){
		int v=bbr.next_bit();
		if(v==EMPTY_ELEM) break;
		bbl.set_bit(r2l[v]);
	}
	return bbl;
}

template<class bitstring_array_t>
inline
bitstring_array_t& GraphMap::map_l2r(bitstring_array_t& bbal, bitstring_array_t& bbar, int from, int to) const{
//////////////////
// assumes bbal and bbar are correctly allocated
	for(int c=from; c<=to; c++){
		map_l2r(bbal.pbb[c],bbar.pbb[c]);
	}
	return bbar;
}

template<class bitstring_array_t>
inline
bitstring_array_t& GraphMap::map_r2l(bitstring_array_t& bbal, bitstring_array_t& bbar, int from, int to)const {
//////////////////
// maps a set of bitarrays within range (both ends included)
//
// COMMENTS: no assertion for capacity

	for(int c=from; c<=to; c++){
		map_r2l(bbal.pbb[c],bbar.pbb[c]);
	}
	return bbal;
}

inline
bool GraphMap::is_consistent(){
/////////////////////
// checks all reverse mappings for consistency
	for(int v=0; v<l2r.size(); v++){
		if(v!=r2l[l2r[v]]) return false;
	}
	return true;
}

template<class Graph_t>
inline
int GraphMap::build_mapping(Graph_t& g, gbbs::sort_t slhs, gbbs::place_t plhs, gbbs::sort_t srhs, gbbs::place_t prhs,
							string lhs_name, string rhs_name){
/////////////////////////
// builds mapping between the two different sortings of g
//
// RETURNS 0 ok, -1 Error
//
// COMMENTS: g may be weighted (weights are also ordered)
	
	int NV=g.number_of_vertices();
	vint o2n_lhs, n2o_lhs, o2n_rhs, n2o_rhs;	
	init(NV,EMPTY_ELEM /* -1 */);
		
	//determine sorting lhs
	GraphSort<Graph_t> gol(g);
	o2n_lhs=gol.new_order(slhs, plhs);
	n2o_lhs=Decode::reverse(o2n_lhs);	

	//determine sorting rhs
	GraphSort<Graph_t> gor(g);
	o2n_rhs=gor.new_order(srhs, prhs);
	n2o_rhs=Decode::reverse(o2n_rhs);	

	//determines direct and reverse mappings independently
	for(int v=0; v<NV; v++){
		l2r[v]= o2n_rhs[ n2o_lhs[v] ];				/* l->r */
	}
	for(int v=0; v<NV; v++){
		r2l[v]= o2n_lhs[ n2o_rhs[v] ] ;				/* r->l */
	}

	name_l=lhs_name;
	name_r=rhs_name;
		
	//I/O
	//cout<<"N2O_D"; com::stl::print_collection(n2o_d); cout<<endl;
	//cout<<"O2N_D";com::stl::print_collection(o2n_d); cout<<endl;
	//cout<<"O2N_W";com::stl::print_collection(o2n_w); cout<<endl;
	//cout<<"N2O_W";com::stl::print_collection(n2o_w); cout<<endl;

	if(!is_consistent()){
		LOG_ERROR("bizarre ordering");
		return -1;
	}
	return 0;
}

inline
ostream& GraphMap::print_mappings(print_t type, ostream& o){
	switch(type){
	case L2R:
		com::stl::print_collection(l2r,o);
		break;
	case R2L:
		com::stl::print_collection(r2l,o);
		break;
	case ALL:
		com::stl::print_collection(l2r,o); o<<endl;
		com::stl::print_collection(r2l,o);
		break;
	default:
		LOG_ERROR("GraphMap::print_mappings()-bizarre print type");
	}
	return o;
}

inline
ostream& GraphMap::print_names(print_t type, ostream& o){
	switch(type){
	case L2R:
		o<<"L:"<<name_l;
		break;
	case R2L:
		o<<"R:"<<name_r;
		break;
	case ALL:
		o<<"L:"<<name_l; o<<endl;
		o<<"R:"<<name_r;
		break;
	default:
		LOG_ERROR("GraphMap::print_names()-bizarre print type");
	}
	return o;
}

#endif