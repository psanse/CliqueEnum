//clique_sort.h: header for CliqueSort implementation, a wrapper to order bit encoded undirected graphs by degree criteria
// date of creation in previous framework: 17/09/14  (authors: pablo san segundo, alvaro lopez)
// last update: 25/11/15
// author: pss

#ifndef __CLIQUE_SORT_H__
#define __CLIQUE_SORT_H__

#include "clique/clique_types.h"
#include "graph/graph.h"
#include "graph/algorithms/decode.h"
#include "graph/algorithms/graph_sort.h"
#include "utils/logger.h"
#include <iostream>
#include <algorithm>

#include <vector>

typedef vector<int> vint;
using namespace gbbs;				//basic enum types for GRAPH sorting algorithms

//////////////////////////
//
// CliqueSort class
// (only for ugraph and sparse_ugraph)
//
////////////////////////////

template <class Graph_t>
class CliqueSort:public GraphSort<Graph_t>, public clqo{
private:
	static const double MIN_DENSITY_FOR_RLF;			//currently > 0.7
	static const double MIN_DENSITY_FOR_CSP_RLF;		//currently > 0.8 (CSP solved as MCP)		
	static const int MAX_SIZE_RLF_SORT= 20000;
	
public:
	typedef vector< pair<init_order_t, place_t> >				vpclq;
	typedef typename vpclq::iterator							vpclq_it;

	CliqueSort					(Graph_t& gout):GraphSort<Graph_t>(gout) {}
		
	vint new_order				(init_order_t, place_t=PLACE_LF, vint* v=NULL /*other info*/);

	vint new_subg_order			(init_order_t, typename Graph_t::bb_type&,  place_t=PLACE_LF);		//not in [OLD_INDEX]=NEW_INDEX format!
	vint new_color_set_order	(init_order_t, vint& cset, place_t=PLACE_LF);						//reorders vertices inside each color set determined by cset (labels start at 1)


	vint new_mixed_order		(int param);	
	
	int reorder_composite		(vpclq&, Decode& d,  ostream* o = NULL);							//includes MAX_WEIGHT option
	int reorder_mixed_init		(int param, Decode& d);												//specific composite (see my Init Sorting paper)

	int eval_order				(vint& order);														//returns an evaluation of current vertex order
};

//////////////////
//static  members
template <class Graph_t>
const double CliqueSort<Graph_t>::MIN_DENSITY_FOR_RLF=0.7;

template <class Graph_t>
const double CliqueSort<Graph_t>::MIN_DENSITY_FOR_CSP_RLF=0.8;

///END STATIC /////////////////

template<class Graph_t>
inline
vint CliqueSort<Graph_t>::new_order (init_order_t  alg, place_t place, vint* p_info){
//////////////////////////
// 
// date of creation: 20/11/15
// author: pss
//
// Computes a new ordering of the vertices of the graph according to alg.
// Examines vertices sin natural order and places them sequentially according to 
// place.
//
// RETURNS: the new ordering in format [OLD_INDEX]= NEW_INDEX or empty array in case of NONE or unknown alg
			
	vint res(GraphSort<Graph_t>::g.number_of_vertices());
		
//////////////////////
// MIN_WIDTH_KCORE specific case
	//check correct place flag
	if(alg==MIN_WIDTH_KCORE){
		if(place==PLACE_FL) LOG_WARNING("CliqueSort<T>::new_order: ignoring incorrect place flag for MIN_WIDTH_KCORE ordering");
		return GraphSort<Graph_t>::new_order(KCORE, PLACE_LF);
	}
///////////////////////
// ALL REMAINING SORTING CRITERIA (excluding RLF variants-see ugraph specialization)
	switch(alg){
	case MIN_WIDTH:
		res=GraphSort<Graph_t>::new_order(MIN_DEG_DEGEN,place);
		break;
	case MAX_WIDTH:
		res=GraphSort<Graph_t>::new_order(MAX_DEG_DEGEN,place);
		break;
	case MIN_WIDTH_MIN_TIE_STATIC:
		res=GraphSort<Graph_t>::new_order(MIN_DEG_DEGEN_TIE_STATIC,place);
		break;
	case clqo::NONE:
		res=GraphSort<Graph_t>::new_order(gbbs::NONE,place);
		break;
	default:
		LOG_ERROR("CliqueSort<T>::create_new_order: unknown ordering strategy");
		vint vempty;
		vempty.swap(res);
	}
	return res;
}

template<>
inline
vint CliqueSort<ugraph>::new_order (init_order_t  alg_in, place_t place, vint* vcol){
//////////////////////////
// 
// date of creation (refactored from earlier code): 22/11/15
// author: pss
//
// Specialization for RLF variants, for ugraph type only
// (includes degree based sorting as well)
//
// REMARKS: RLF based orderings used default MAXWIDTH in complement graph
//
	bool is_good=false;
//	InitColorSort cs(g);
	init_order_t alg=alg_in;
	

	
	const int NV=g.number_of_vertices();
	

///////////////////////
// ALL REMAINING SORTING CRITERIA

///////////
//variables for RLF_COND
	int eval_rlf, eval_rlf1, min_eval;
	int eval_degsort;
	vint degsort;
	vint res(NV);
	stringstream sstr("");
		
/////////////////////////////
	switch(alg){
			
	case MIN_WIDTH:
		return(this->GraphSort<ugraph>::new_order(MIN_DEG_DEGEN,place));
	case MAX_WIDTH:
		return(this->GraphSort<ugraph>::new_order(MAX_DEG_DEGEN,place));
	case MIN_WIDTH_MIN_TIE_STATIC:
		return(this->GraphSort<ugraph>::new_order(MIN_DEG_DEGEN_TIE_STATIC,place));
	case MAX_WIDTH_MAX_TIE_STATIC:
		return(this->GraphSort<ugraph>::new_order(MAX_DEG_DEGEN_TIE_STATIC,place));
	case MAX_WIDTH_MAX_TIE:		//on the fly computation of support
		return(this->GraphSort<ugraph>::new_order(MAX_DEG_DEGEN_TIE,place));
	case clqo::NONE:
		return(this->GraphSort<ugraph>::new_order(gbbs::NONE,place));
		break;

	default:
		LOG_ERROR("CliqueSort<ugraph>::new_order: unknown ordering strategy");
		vint vempty;
		return vempty;
		
	}

	return res;			//RLF variant orderings
}

template<class Graph_t>
inline
vint  CliqueSort<Graph_t>::new_subg_order (init_order_t alg, typename Graph_t::bb_type& sg,  place_t place){
////////////////
// A translator of enum types

	switch(alg){
	case MIN_WIDTH:
		return (this->GraphSort<Graph_t>::new_subg_order(MIN_DEG_DEGEN, sg, place));
	case MAX_WIDTH:
		return (this->GraphSort<Graph_t>::new_subg_order(MAX_DEG_DEGEN, sg, place));
	case MIN_WIDTH_MIN_TIE_STATIC:
		return (this->GraphSort<Graph_t>::new_subg_order(MIN_DEG_DEGEN_TIE_STATIC, sg, place));
	case clqo::NONE:
		return (this->GraphSort<Graph_t>::new_subg_order(gbbs::NONE, sg, place));


	default:
		LOG_ERROR("CliqueSort<T>::new_subg_order: unknown ordering strategy");
	}

	vint vempty;
	return vempty;
}


template<class Graph_t>
inline
vint  CliqueSort<Graph_t>::new_color_set_order (init_order_t alg, vint& cset, place_t place){
	struct this_template_should_not_be_created{};
	vint vempty;
	return vempty;
}

template<>
inline
vint  CliqueSort<ugraph>::new_color_set_order (init_order_t alg, vint& cset, place_t place){
/////////////////////////
// A color set specification: [x]=y || <x> is the color label, <y> the size of the color set Cx 
// first update: 29/9/16
//
// RETURNS: an ordering in the usual form O[OLD_INDEX]=NEW_INDEX or empty set if ERROR
//
//REMARKS: color labels MUST start at 1
	
	const int NV=g.number_of_vertices();
	bitarray bbfrom(NV);						//each color set
	bitarray bbref(NV);							//subgraph union of color sets

	//current initial order
	vint ord;
	for(int i=0; i<NV; i++){
		ord.push_back(i);
	}
		
	//main loop
	int start=0;
	for(int i=1; i<cset.size(); i++){		/* color labels start at 1*/
		int cs=cset[i];
		bbfrom.erase_bit();
		bbref.erase_bit();
		
		bbfrom.set_bit(start, start+cs-1);
		bbref.set_bit(0,start+cs-1);
		
		if(GraphSort<ugraph>::change_order(bbfrom, bbref, ord, 
							(alg==clqo::init_order_t::MIN_WIDTH)? gbbs::pick_t::PICK_MINFL : gbbs::pick_t::PICK_MAXFL,
								place, true)==-1){	
			vint myv;
			ord.swap(myv);		
			return ord;					//error
		}
		start+=cs;
	}

	return ord;							//ok
}


template<class Graph_t>
inline
int CliqueSort<Graph_t>::reorder_composite (vpclq& lord , Decode& d,  ostream* o ){
//////////////////
// iterates over the list of clique sorting algorithms and reorders the graph accordingly.
// Stores in decoder each change in format [NEW_INDEX]=OLD_INDEX for a later decoding
//
// RETURNS -1 if ERROR, 0 if OK

	for(vpclq_it it=lord.begin(); it!=lord.end(); it++){
		pair<init_order_t, place_t> ord=*it;

		//sort
		switch(ord.first){
		case MIN_WIDTH:
			GraphSort<Graph_t>::reorder(GraphSort<Graph_t>::new_order(MIN_DEG_DEGEN,ord.second),d,o);
			break;
		case MAX_WIDTH:
			GraphSort<Graph_t>::reorder(GraphSort<Graph_t>::new_order(MAX_DEG_DEGEN,ord.second),d,o);
			break;
		case MIN_WIDTH_MIN_TIE_STATIC:
			GraphSort<Graph_t>::reorder(GraphSort<Graph_t>::new_order(MIN_DEG_DEGEN_TIE_STATIC,ord.second),d,o);
			break;
		case clqo::NONE:
			GraphSort<Graph_t>::reorder(GraphSort<Graph_t>::new_order(gbbs::NONE,ord.second),d,o);
			break;

		//*** others 

		default:
			LOG_WARNING("CliqueSort<Graph_t>::reorder_composite: unknown ordering strategy. Current sorting discarded");
		}
	}
	
	return 0;		//OK
}

template<>
inline
int CliqueSort<ugraph>::reorder_mixed_init	(int param, Decode& d ){
///////////////////
// composite ordering
// 1-MIN_MIN_WIDTH_MIN_TIE_STATIC
// 2-ordering of a fraction (param) of initial vertices, non-degenerate
	
	GraphSort<ugraph>::reorder(new_order(MIN_WIDTH_MIN_TIE_STATIC,PLACE_LF), d);
	GraphSort<ugraph>::reorder(new_mixed_order(param),d);
			
	return 0;		//OK
}

template<>
inline
int CliqueSort<ugraph>::reorder_composite (vpclq& lord , Decode& d,  ostream* o ){
//////////////////
// iterates over the list of clique sorting algorithms and reorders the graph accordingly.
// Stores in decoder each change in format [NEW_INDEX]=OLD_INDEX for a later decoding
//
// RETURNS -1 if ERROR, 0 if OK

	d.clear();
//	InitColorSort cs(g);
	vint order;
	bool is_good=false;

	for(vpclq_it it=lord.begin(); it!=lord.end(); it++){
		pair<init_order_t, place_t> ord=*it;

		//sort
		switch(ord.first){
		case MIN_WIDTH:
			GraphSort<ugraph>::reorder(GraphSort<ugraph>::new_order(MIN_DEG_DEGEN,ord.second),d,o);
			break;
		case MAX_WIDTH:
			GraphSort<ugraph>::reorder(GraphSort<ugraph>::new_order(MAX_DEG_DEGEN,ord.second),d,o);
			break;
		case MAX_ABS:
			GraphSort<ugraph>::reorder(GraphSort<ugraph>::new_order(MAX_DEG_ABS,ord.second),d,o);
			break;
		case MIN_WIDTH_MIN_TIE_STATIC:
			GraphSort<ugraph>::reorder(GraphSort<ugraph>::new_order(MIN_DEG_DEGEN_TIE_STATIC,ord.second),d,o);
			break;
		case MAX_WEIGHTED:
			GraphSort<ugraph>::reorder(GraphSort<ugraph>::new_order(MAX_WEIGHT,ord.second),d,o);
			break;
		case MIN_WEIGHTED:
			GraphSort<ugraph>::reorder(GraphSort<ugraph>::new_order(MIN_WEIGHT,ord.second),d,o);
			break;
		case MAX_WEIGHTED_DEG:
			GraphSort<ugraph>::reorder(GraphSort<ugraph>::new_order(MAX_WEIGHT_DEG,ord.second),d,o);
			break;
		case MIN_WEIGHTED_DEG:
			GraphSort<ugraph>::reorder(GraphSort<ugraph>::new_order(MIN_WEIGHT_DEG,ord.second),d,o);
			break;
		case clqo::NONE:
			GraphSort<ugraph>::reorder(GraphSort<ugraph>::new_order(gbbs::NONE,ord.second),d,o);
			break;
		
		

		case MIXED_2:
			reorder_mixed_init(2,d);
			break;
		case MIXED_3:
			reorder_mixed_init(3,d);
			break;
		case MIXED_4:
			reorder_mixed_init(4,d);
			break;
		case MIXED_5:
			reorder_mixed_init(5,d);
			break;
		case MIXED_6:
			reorder_mixed_init(6,d);
			break;
		case MIXED_7:
			reorder_mixed_init(7,d);
			break;
		case MIXED_8:
			reorder_mixed_init(8,d);
			break;
		case MIXED_9:
			reorder_mixed_init(9,d);
			break;
		case MIXED_10:
			reorder_mixed_init(10,d);
			break;
	
		default:
			LOG_WARNING("CliqueSort<Graph_t>::reorder_composite: unknown ordering strategy. Current sorting discarded");
		}
	}
	
	return 0;		//OK
}


template<class Graph_t>
inline
vint CliqueSort<Graph_t>::new_mixed_order(int param){
///////////////////////
// Reordering of a fraction of the initial vertices wrt to non-degenerate properties
// in V 
// PARAMS: param ranges [2 (half the vertices of V) to 10 (a tenth of the vertices of V)]

	int NV=GraphSort<Graph_t>::g.number_of_vertices();
	bitarray sg(NV);
	bitarray sgV(NV);
	int nVsort=max<int>(1,GraphSort<Graph_t>::g.number_of_vertices()/param);
	sg.set_bit(0, nVsort);
	sgV.set_bit(0, NV-1);

	return (GraphSort<Graph_t>::new_order(sg, sgV, PICK_MAXFL, PLACE_FL, false));
}

template<class Graph_t>
inline
int CliqueSort<Graph_t>::eval_order (vint& order){
///////////////////
// Evaluates an initial order of vertices for clique based  on
// the maximum infra-chrom bound of all oriented subproblems
// date: 9/12/15
//
// REMARKS: Could also use the biggest subproblem (hanging from the last vertex)	

	Graph_t g1(GraphSort<Graph_t>::g);

	//reorders
	CliqueSort cs(g1);
	if(cs.reorder(order)==-1){
		LOG_ERROR("CliqueSort<ugraph>::eval_order()-Impossible to evaluate the ordering");
		return -1;
	}

	//evaluates the ordering according to infra-chrom bounds for all subproblems
	InitColorUB cub(g1);
	return(cub.eval_init_order());
}


#endif