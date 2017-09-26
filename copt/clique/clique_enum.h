	////////////////////////////////
// clique_enum.h: interface for CliqueEnum class which solves the problem of maximal clique enumeration
//				  
// initial date:10/12/15
// last update: 
// author: pablo san segundo


#ifndef  __CLIQUE_ENUM_H__
#define  __CLIQUE_ENUM_H__

#include "clique.h"
#include "utils/common.h"
#include "../common/common_macros.h"

class CliqueEnum: public Clique<ugraph>{
	
public:
	
	CliqueEnum(ugraph* g, param_t p):Clique<ugraph>(g, p), m_cand(NULL), m_conf(NULL){};
	CliqueEnum(param_t p)			:Clique<ugraph>(p), m_cand(NULL), m_conf(NULL){};
	virtual ~CliqueEnum(){}
	
	virtual int init_bitarrays();	

	//search procedures
	void expand_greedy_conflict_set				(int maxac, bitarray& l_bb , bitarray& l_cand);
	void expand_greedy_conflict_set_X			(int maxac, bitarray& l_bb , bitarray& l_cand);
	void expand_greedy_conflict_set_Xm			(int maxac, bitarray& l_bb , bitarray& l_cand);
	void expand_greedy_conflict_set_XP			(int maxac, bitarray& l_bb , bitarray& l_cand);
	void expand_greedy_conflict_set_XPm			(int maxac, bitarray& l_bb , bitarray& l_cand);
	void expand_greedy_cand_set					(int maxac, bitarray& l_bb , bitarray& l_cand);

	//incompete tests pivot+filter
	void expand_greedy_conflict_set_with_filter (int maxac, bitarray& l_bb , bitarray& l_cand);		//Incomplete!!
	void expand_greedy_cand_set_with_filter		(int maxac, bitarray& l_bb , bitarray& l_cand);		//Incomplete!!

	//test framework
	virtual	int set_up();
	virtual	void run();	
	virtual	void tear_down(){ clear_vertex_sets(); clear_conflicts(); Clique<ugraph>::tear_down();}

private:
	void init_vertex_sets();
	void clear_vertex_sets();
	void init_conflicts();
	void clear_conflicts();

///////////
// data members
	
	//auxiliary data structures
	bitarray* m_cand;					//candidate vertices
	bitarray* m_conf;					//conflicting vertices
	ugraph gc;							//complement graph
};

void CliqueEnum::clear_vertex_sets(){
	if (m_cand){
		delete [] m_cand;
		m_cand=NULL;
	}
}

void CliqueEnum::init_vertex_sets(){
	clear_vertex_sets();
	m_cand=new bitarray[m_size];
	for(int i=0; i<m_size; i++){
		m_cand[i].init(m_size);
	}
}

void CliqueEnum::clear_conflicts(){
	if (m_conf){
		delete [] m_conf;
		m_conf=NULL;
	}
}


void CliqueEnum::init_conflicts(){
	clear_conflicts();
	m_conf=new bitarray[m_size+1];		//for complete graphs
	for(int i=0; i<=m_size; i++){
		m_conf[i].init(m_size);
	}
}

int CliqueEnum::init_bitarrays(){

	Clique<ugraph>::init_bitarrays();
		
	//empty set
	init_vertex_sets();	
	init_conflicts();	
	g->create_complement(gc);

	int lastv=g->number_of_vertices()-1;
	m_cand[0]=gc.get_neighbors(lastv);
	m_cand[0].set_bit(lastv);
		
	return 0;
}

inline
int CliqueEnum::set_up(){
//////////////
// allocates memory, evaluates initial bounds and determines 
// initial trivial solutions
//
// RETURN VALUE: -1 Error, 0-ok, >0 trivial solution found

	int sol=0;
	res.clear();
	res.set_name(g->get_name());

	//determine allocation info
	search_alloc_t info;								//loads BBMC configuration for search allocation
	info.remove(search_alloc_t::ALLOC_COLOR_SETS);		//for recoloring
	info.remove(search_alloc_t::ALLOC_COLOR_LABELS);
	switch(param.alg){
	case BBMC_EN_GCAND:
	case BBMC_EN_GCONF:
	case BBMC_EN_GCONF_X:
	case BBMC_EN_GCONF_Xm:
	case BBMC_EN_GCONF_XP:
	case BBMC_EN_GCONF_XPm:
	case BBMC_EN_GCONF_FILTER:
	case BBMC_EN_GCAND_FILTER:
	
	
	break;
	default:
		LOG_ERROR("CliqueEnum::setup unknown algorithm");
		return -1;
	}
	
	//actual set_up
	if(param.unrolled){
		LOG_ERROR("CliqueEnum::setup unrolled variant not defined");
		return -1;
	}else{

		//set_up_non_unrolled (manual)
		LOG_PRINT("initial ordering----------------");
		CliqueSort<ugraph> o(*g);
		if(o.reorder(o.new_order(param.init_order, (param.init_order==NONE)? gbbs::PLACE_FL : gbbs::PLACE_LF), get_decoder())==-1){
			LOG_ERROR("CliqueEnum::set_up: error during reordering");
			return -1;
		}
		
		//allocation
		Clique<ugraph>::set_malloc(m_size);
		if(search_allocation(info)==-1) return -1;
		
		res.set_UB(0);	//will store the number of maximal cliques found
	}	
	
	return sol;
}

inline
void CliqueEnum::run(){
	//algorithm
	if(param.unrolled){
		LOG_ERROR("CliqueEnum::run: unrolling not defined for this familiy of algorithms");
		return;
	}else{
		res.tic();
		switch(param.alg){
			case BBMC_EN_GCAND:
			expand_greedy_cand_set(0, Clique<ugraph>::m_bbroot, m_cand[0]);
			break;
		case BBMC_EN_GCONF:
			expand_greedy_conflict_set(0, Clique<ugraph>::m_bbroot, m_cand[0]);
			break;
		case BBMC_EN_GCONF_X:
			expand_greedy_conflict_set_X(0, Clique<ugraph>::m_bbroot, m_cand[0]);
			break;
		case BBMC_EN_GCONF_Xm:
			expand_greedy_conflict_set_Xm(0, Clique<ugraph>::m_bbroot, m_cand[0]);
			break;
		case BBMC_EN_GCONF_XP:
			expand_greedy_conflict_set_XP(0, Clique<ugraph>::m_bbroot, m_cand[0]);
			break;
		case BBMC_EN_GCONF_XPm:
			expand_greedy_conflict_set_XPm(0, Clique<ugraph>::m_bbroot, m_cand[0]);
			break;
		case BBMC_EN_GCONF_FILTER:
			expand_greedy_conflict_set_with_filter(0, Clique<ugraph>::m_bbroot, m_cand[0]);
			break;
		case BBMC_EN_GCAND_FILTER:
			expand_greedy_cand_set_with_filter(0, Clique<ugraph>::m_bbroot, m_cand[0]);
			break;
				
		default:
			LOG_ERROR("CliqueEnum::run-non_unrolled:unknown clique algorithm");
		}

		res.toc();
	}

	//read solution
	LOG_INFO("[w:"<<res.get_upper_bound()<<","<<"t:"<<res.get_user_time()<<"s,"<<"st:"<<res.number_of_steps()<<"]");
}	

inline
void CliqueEnum::expand_greedy_conflict_set (int maxac, bitarray& l_bb , bitarray& l_cand){
////////////////////////
// Ordered pivot selection from conflict set if possible 

	const int MAXACPLUS1=maxac+1;
				
	//main loop
	l_cand.init_scan(bbo::NON_DESTRUCTIVE_REVERSE);
	while(true){
				
		////select vertex (in order)
		int v=l_cand.previous_bit();
		if(v==EMPTY_ELEM) break;
				
		
#ifdef ROOT_VERTEX_PROGRESS
		if(maxac==0)
			cout<<"root vertex: "<<v<<endl;
#endif
			
		//child node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));					//optimized when placed second the bitset with higher population
		AND(m_conf[maxac], g->get_neighbors(v), m_conf[MAXACPLUS1]);		//has to be evaluated before the leaf node check

		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(m_conf[MAXACPLUS1].is_empty()){
		
				res.set_UB(res.get_upper_bound()+1);						//increments solution
#ifdef VIEW_PROGRESS
				m_path[maxac]=v;
				stringstream sstr("");
				for(int i=0; i<=maxac; i++){
					sstr<<m_path[i]<<" ";
				}
				LOG_INFO(sstr.str());
#endif
			}

		l_bb.erase_bit(v);
		m_conf[maxac].set_bit(v);
		continue;
		}

		//greedy pivot heuristic: last vertex from conflict set if possible
		int pivot=m_conf[MAXACPLUS1].msbn64();
		if(pivot==EMPTY_ELEM){
			pivot=LISTA_BB(maxac).msbn64();
			AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
			m_cand[MAXACPLUS1].set_bit(pivot);
		}else{
			AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
			//A NAude filter: removed because although it reduces steps the efficiency tradeoff is not good
			//	if(m_cand[MAXACPLUS1].is_empty()){		
			//			LOG_INFO("CAND_EMPTY");
			//		goto next;
			//	}
		}
		
		
			
		///////////////////////////////////////////////////////
		//Branching 

		
		m_path[maxac]=v;		
		res.inc_number_of_steps();
		/*LOG_INFO("vb:"<<v<<" pivot:"<<pivot<<" depth:"<<maxac);
		LOG_INFO("P-SET"); LISTA_BB(maxac).print(); cout<<endl;
		LOG_INFO("X-SET"); m_conf[MAXACPLUS1].print(); cout<<endl;
		LOG_INFO("L-SET"); m_cand[MAXACPLUS1].print(); cout<<endl;*/

		expand_greedy_conflict_set(maxac+1,LISTA_BB(maxac),m_cand[MAXACPLUS1]);  

		/*else{
			LOG_INFO("CAND_EMPTY");
		}*/


		//////////////////////////////////////////////
		// Bactrack (does not delete v from path since it will be overwritten in the same level of search tree)
next:	l_bb.erase_bit(v); 
		m_conf[maxac].set_bit(v);
		
	}// next node

return;		
}

inline
void CliqueEnum::expand_greedy_conflict_set_X (int maxac, bitarray& l_bb , bitarray& l_cand){
////////////////////////
// Best pivot from conflict set. 
// Stable selection based on initial degeneracy ordering

	const int MAXACPLUS1=maxac+1;
				
	//main loop
	l_cand.init_scan(bbo::NON_DESTRUCTIVE_REVERSE);
	while(true){
				
		//select pivot (in order)
		int v=l_cand.previous_bit();
		if(v==EMPTY_ELEM) break;
				
		
#ifdef ROOT_VERTEX_PROGRESS
		if(maxac==0)
			cout<<"root vertex: "<<v<<endl;
#endif
			
		//child node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));					//optimized when place second the bitset with higher population
		AND(m_conf[maxac], g->get_neighbors(v), m_conf[MAXACPLUS1]);		//has to be evaluated before the leaf node check

		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(m_conf[MAXACPLUS1].is_empty()){
		
				res.set_UB(res.get_upper_bound()+1);						//increments solution
#ifdef VIEW_PROGRESS
				m_path[maxac]=v;
				stringstream sstr("");
				for(int i=0; i<=maxac; i++){
					sstr<<m_path[i]<<" ";
				}
				LOG_INFO(sstr.str());
#endif
			}

		l_bb.erase_bit(v);
		m_conf[maxac].set_bit(v);
		continue;
		}


		//max deg X set
		int max_neigh=-1; int neigh; int pivot=EMPTY_ELEM;
		if(m_conf[MAXACPLUS1].init_scan(bbo::NON_DESTRUCTIVE_REVERSE)!=EMPTY_ELEM){
			while(true){
				int v=m_conf[MAXACPLUS1].previous_bit();
				if (v==EMPTY_ELEM) break;

				neigh=g->degree(v,LISTA_BB(maxac));
				if(neigh>max_neigh){
					pivot=v;
					max_neigh=neigh;
				}
			}
		}


		//greedy pivot heuristic: last vertex from conflict set if possible
		//int pivot=m_conf[MAXACPLUS1].msbn64();
		if(pivot==EMPTY_ELEM){
			pivot=LISTA_BB(maxac).msbn64();
			AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
			m_cand[MAXACPLUS1].set_bit(pivot);
		}else{
			AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
		}
			
		///////////////////////////////////////////////////////
		//Branching 
		m_path[maxac]=v;		
		res.inc_number_of_steps();
		expand_greedy_conflict_set_X(maxac+1,LISTA_BB(maxac),m_cand[MAXACPLUS1]);  

		//////////////////////////////////////////////
		// Bactrack (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
		m_conf[maxac].set_bit(v);
		
	}// next node

return;		
}


inline
void CliqueEnum::expand_greedy_conflict_set_Xm (int maxac, bitarray& l_bb , bitarray& l_cand){
////////////////////////
// Best pivot from conflict set. Stable selection based on initial degeneracy ordering
// Optimization in [Naude 15] based on minimizing the number of pivot neighbor vertices non adjacent to Pset

	const int MAXACPLUS1=maxac+1;
				
	//main loop
	l_cand.init_scan(bbo::NON_DESTRUCTIVE_REVERSE);
	while(true){
				
		//select pivot (in order)
		int v=l_cand.previous_bit();
		if(v==EMPTY_ELEM) break;
				
		
#ifdef ROOT_VERTEX_PROGRESS
		if(maxac==0)
			cout<<"root vertex: "<<v<<endl;
#endif
			
		//child node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));					//optimized when place second the bitset with higher population
		AND(m_conf[maxac], g->get_neighbors(v), m_conf[MAXACPLUS1]);		//has to be evaluated before the leaf node check

		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(m_conf[MAXACPLUS1].is_empty()){
		
				res.set_UB(res.get_upper_bound()+1);						//increments solution
#ifdef VIEW_PROGRESS
				m_path[maxac]=v;
				stringstream sstr("");
				for(int i=0; i<=maxac; i++){
					sstr<<m_path[i]<<" ";
				}
				LOG_INFO(sstr.str());
#endif
			}

		l_bb.erase_bit(v);
		m_conf[maxac].set_bit(v);
		continue;
		}

		//max deg X set computed as minimum deg in complement graph
		//this allows to cut search if degree exceeds the best number found so far [Naude 15]
		int min_neigh=CLQ_MAXINT; int neigh=0; int pivot=EMPTY_ELEM;
		if(m_conf[MAXACPLUS1].init_scan(bbo::NON_DESTRUCTIVE_REVERSE)!=EMPTY_ELEM){
			while(true){
				int v=m_conf[MAXACPLUS1].previous_bit();
				if (v==EMPTY_ELEM) break;

				neigh=gc.degree(v, min_neigh, LISTA_BB(maxac));
				if(neigh<min_neigh){
					pivot=v;
					min_neigh=neigh;
				}
			}
		}
		
		//greedy pivot heuristic: last vertex from conflict set if possible
		//int pivot=m_conf[MAXACPLUS1].msbn64();
		if(pivot==EMPTY_ELEM){
			pivot=LISTA_BB(maxac).msbn64();
			AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
			m_cand[MAXACPLUS1].set_bit(pivot);
		}else{
			AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
		}
			
		///////////////////////////////////////////////////////
		//Branching 
		m_path[maxac]=v;		
		res.inc_number_of_steps();
		expand_greedy_conflict_set_Xm(maxac+1,LISTA_BB(maxac),m_cand[MAXACPLUS1]);  

		//////////////////////////////////////////////
		// Bactrack (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
		m_conf[maxac].set_bit(v);
		
	}// next node

return;		
}
inline
void CliqueEnum::expand_greedy_conflict_set_XP (int maxac, bitarray& l_bb , bitarray& l_cand){
////////////////////////
// Best pivot: Tomita pivot selection. Stable choice, vertices are taken as ordered by degeneracy initially 

	const int MAXACPLUS1=maxac+1;
				
	//main loop
	l_cand.init_scan(bbo::NON_DESTRUCTIVE_REVERSE);
	while(true){
				
		//select pivot (in order)
		int v=l_cand.previous_bit();
		if(v==EMPTY_ELEM) break;
				
		
#ifdef ROOT_VERTEX_PROGRESS
		if(maxac==0)
			cout<<"root vertex: "<<v<<endl;
#endif
			
		//child node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));					//optimized when place second the bitset with higher population
		AND(m_conf[maxac], g->get_neighbors(v), m_conf[MAXACPLUS1]);		//has to be evaluated before the leaf node check

		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(m_conf[MAXACPLUS1].is_empty()){
		
				res.set_UB(res.get_upper_bound()+1);						//increments solution
#ifdef VIEW_PROGRESS
				m_path[maxac]=v;
				stringstream sstr("");
				for(int i=0; i<=maxac; i++){
					sstr<<m_path[i]<<" ";
				}
				LOG_INFO(sstr.str());
#endif
			}

		l_bb.erase_bit(v);
		m_conf[maxac].set_bit(v);
		continue;
		}


		//max deg X set
		int max_neigh=-1; int neigh; int pivot=EMPTY_ELEM;
		if(m_conf[MAXACPLUS1].init_scan(bbo::NON_DESTRUCTIVE_REVERSE)!=EMPTY_ELEM){
			while(true){
				int v=m_conf[MAXACPLUS1].previous_bit();
				if (v==EMPTY_ELEM) break;

				neigh=g->degree(v,LISTA_BB(maxac));
				if(neigh>max_neigh){
					pivot=v;
					max_neigh=neigh;
					
				}
			}
		}

		//max deg P set
		bool is_used_P=false;
		if(LISTA_BB(maxac).init_scan(bbo::NON_DESTRUCTIVE_REVERSE)!=EMPTY_ELEM){
			while(true){
				int v=LISTA_BB(maxac).previous_bit();
				if (v==EMPTY_ELEM) break;

				neigh=g->degree(v,LISTA_BB(maxac));
				if(neigh>max_neigh){
					pivot=v;
					max_neigh=neigh;
					is_used_P=true;
				}
			}
		}


		//greedy pivot heuristic: last vertex from conflict set if possible
		AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
		if(is_used_P){
			m_cand[MAXACPLUS1].set_bit(pivot);
		}
	
		///////////////////////////////////////////////////////
		//Branching 
		m_path[maxac]=v;		
		res.inc_number_of_steps();
		/*LOG_INFO("vb:"<<v<<" pivot:"<<pivot<<" depth:"<<maxac);
		LOG_INFO("P-SET"); LISTA_BB(maxac).print(); cout<<endl;
		LOG_INFO("X-SET"); m_conf[MAXACPLUS1].print(); cout<<endl;
		LOG_INFO("L-SET"); m_cand[MAXACPLUS1].print(); cout<<endl;*/
		expand_greedy_conflict_set_XP(maxac+1,LISTA_BB(maxac),m_cand[MAXACPLUS1]);  

		//////////////////////////////////////////////
		// Bactrack (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
		m_conf[maxac].set_bit(v);
		
	}// next node

return;		
}

inline
void CliqueEnum::expand_greedy_conflict_set_XPm (int maxac, bitarray& l_bb , bitarray& l_cand){
////////////////////////
// Best pivot: Tomita pivot selection. Stable choice, vertices are taken as ordered by degeneracy initially 
// Optimization which computes the heuristic by minimizing the number of neighbor vertices of each pivot
// in the conflict set.

	const int MAXACPLUS1=maxac+1;
				
	//main loop
	l_cand.init_scan(bbo::NON_DESTRUCTIVE_REVERSE);
	while(true){
				
		//select pivot (in order)
		int v=l_cand.previous_bit();
		if(v==EMPTY_ELEM) break;
				
		
#ifdef ROOT_VERTEX_PROGRESS
		if(maxac==0)
			cout<<"root vertex: "<<v<<endl;
#endif
			
		//child node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));					//optimized when place second the bitset with higher population
		AND(m_conf[maxac], g->get_neighbors(v), m_conf[MAXACPLUS1]);		//has to be evaluated before the leaf node check

		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(m_conf[MAXACPLUS1].is_empty()){
		
				res.set_UB(res.get_upper_bound()+1);						//increments solution
#ifdef VIEW_PROGRESS
				m_path[maxac]=v;
				stringstream sstr("");
				for(int i=0; i<=maxac; i++){
					sstr<<m_path[i]<<" ";
				}
				LOG_INFO(sstr.str());
#endif
			}

		l_bb.erase_bit(v);
		m_conf[maxac].set_bit(v);
		continue;
		}


		//max deg X set by minimizing number of conflicts of pivots
		int min_neigh=CLQ_MAXINT; int neigh=0; int pivot=EMPTY_ELEM;
		if(m_conf[MAXACPLUS1].init_scan(bbo::NON_DESTRUCTIVE_REVERSE)!=EMPTY_ELEM){
			while(true){
				int v=m_conf[MAXACPLUS1].previous_bit();
				if (v==EMPTY_ELEM) break;

				neigh=gc.degree(v, min_neigh, LISTA_BB(maxac));
				if(neigh<min_neigh){
					pivot=v;
					min_neigh=neigh;
					
				}
			}
		}

		//max deg P set by minimizing number of conflicts of pivots
		bool is_used_P=false;
		if(LISTA_BB(maxac).init_scan(bbo::NON_DESTRUCTIVE_REVERSE)!=EMPTY_ELEM){
			while(true){
				int v=LISTA_BB(maxac).previous_bit();
				if (v==EMPTY_ELEM) break;

				neigh=gc.degree(v, min_neigh, LISTA_BB(maxac));
				if(neigh<min_neigh){
					pivot=v;
					min_neigh=neigh;
					is_used_P=true;
				}
			}
		}


		//greedy pivot heuristic: last vertex from conflict set if possible
		AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
		if(is_used_P){
			m_cand[MAXACPLUS1].set_bit(pivot);
		}
	
			
		///////////////////////////////////////////////////////
		//Branching 
		m_path[maxac]=v;		
		res.inc_number_of_steps();
		expand_greedy_conflict_set_XPm(maxac+1,LISTA_BB(maxac),m_cand[MAXACPLUS1]);  

		//////////////////////////////////////////////
		// Bactrack (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
		m_conf[maxac].set_bit(v);
		
	}// next node

return;		
}

void CliqueEnum::expand_greedy_cand_set (int maxac, bitarray& l_bb , bitarray& l_cand){
////////////////////////
// Ordered pivot selection from candidate set 

	const int MAXACPLUS1=maxac+1;
					
	//main loop
	l_cand.init_scan(bbo::NON_DESTRUCTIVE_REVERSE);
	while(true){
				
		//select pivot (in order)
		int v=l_cand.previous_bit();
		if(v==EMPTY_ELEM) break;
		
#ifdef ROOT_VERTEX_PROGRESS
		if(maxac==0)
			cout<<"root vertex: "<<v<<endl;
#endif
			
		//childnNode generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));					//optimized when place second the bitset with higher population
		AND(m_conf[maxac], g->get_neighbors(v), m_conf[MAXACPLUS1]);		//has to be evaluated before the leaf node check

		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(m_conf[MAXACPLUS1].is_empty()){
		
				res.set_UB(res.get_upper_bound()+1);						//increments solution
#ifdef VIEW_PROGRESS
				m_path[maxac]=v;
				stringstream sstr("");
				for(int i=0; i<=maxac; i++){
					sstr<<m_path[i]<<" ";
				}
				LOG_INFO(sstr.str());
#endif
			}

		l_bb.erase_bit(v);
		m_conf[maxac].set_bit(v);
		continue;
		}
				
		//greedy pivoting: last vertex from candidate set
		int pivot=LISTA_BB(maxac).msbn64();
		AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
		m_cand[MAXACPLUS1].set_bit(pivot);
			
		///////////////////////////////////////////////////////
		//Branching
		m_path[maxac]=v;
		res.inc_number_of_steps();
		expand_greedy_cand_set(maxac+1,LISTA_BB(maxac),m_cand[MAXACPLUS1]);  

		//////////////////////////////////////////////
		// Backtrack (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
		m_conf[maxac].set_bit(v);

	}// next node

return;		
}

void CliqueEnum::expand_greedy_cand_set_with_filter (int maxac, bitarray& l_bb , bitarray& l_cand){
////////////////////////
// Ordered pivot selection from candidate set 
// Filters vertices from candidate set which are neighbors to the first expanded vertex
// date of creation: 9/1/15
//
// COMMENTS: Filtering + pivoting heuristic is INCOMPLETE (the screen output lines have been left)  

	const int MAXACPLUS1=maxac+1;
	for(int i=0; i<maxac; i++){
		cout<<m_path[i]<<" ";
	}
	l_bb.print();
	cout<<endl;
				
	//takes as filter vertex the first vertex that is not the pivot (i.e. the second vertex)
	l_cand.init_scan(bbo::NON_DESTRUCTIVE_REVERSE);
	int filter_vertex=l_cand.previous_bit();
	if(filter_vertex!=EMPTY_ELEM){
		filter_vertex=l_cand.previous_bit();
	}

	//main loop
	l_cand.init_scan(bbo::NON_DESTRUCTIVE_REVERSE);
	while(true){
				
		//select pivot (in order)
		int v=l_cand.previous_bit();
		if(v==EMPTY_ELEM) break;
		
#ifdef ROOT_VERTEX_PROGRESS
		if(maxac==0)
			cout<<"root vertex: "<<v<<endl;
#endif
			
		//childnNode generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));					//optimized when place second the bitset with higher population
		AND(m_conf[maxac], g->get_neighbors(v), m_conf[MAXACPLUS1]);		//has to be evaluated before the leaf node check

		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(m_conf[MAXACPLUS1].is_empty()){
		
				res.set_UB(res.get_upper_bound()+1);						//increments solution
#ifdef VIEW_PROGRESS
				m_path[maxac]=v;
				stringstream sstr("");
				for(int i=0; i<=maxac; i++){
					sstr<<m_path[i]<<" ";
				}
				LOG_INFO(sstr.str());
#endif
			}

		l_bb.erase_bit(v);
		m_conf[maxac].set_bit(v);
		continue;
		}
				
		//greedy pivoting: last vertex from candidate set
		int pivot=LISTA_BB(maxac).msbn64();
		AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
		m_cand[MAXACPLUS1].set_bit(pivot);
		if(filter_vertex!=EMPTY_ELEM && g->get_neighbors(filter_vertex).is_bit(v)){
			m_cand[MAXACPLUS1].print();
			m_cand[MAXACPLUS1].erase_bit(g->get_neighbors(filter_vertex));
			cout<<"depth:"<<maxac<<" v: "<<v<<" pivot: "<<pivot<<" filtered by: "<<filter_vertex<<" ";
			m_cand[MAXACPLUS1].print(); cout<<endl;
		}

			
		///////////////////////////////////////////////////////
		//Branching
		m_path[maxac]=v;
		res.inc_number_of_steps();
		expand_greedy_cand_set_with_filter(maxac+1,LISTA_BB(maxac),m_cand[MAXACPLUS1]);  

		//////////////////////////////////////////////
		// Backtrack (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
		m_conf[maxac].set_bit(v);

	}// next node

return;		

}

void CliqueEnum::expand_greedy_conflict_set_with_filter (int maxac, bitarray& l_bb , bitarray& l_cand){
////////////////////////
// Ordered pivot selection from conflict set if possible 
// Filters vertices from candidate set which are neighbors to the first expanded vertex
// date of creation: 3/1/15
//
// COMMENTS: Filtering + pivoting heuristic is INCOMPLETE (the screen output lines have been left)  

	const int MAXACPLUS1=maxac+1;
	for(int i=0; i<maxac; i++){
		cout<<m_path[i]<<" ";
	}
	l_bb.print();
	cout<<endl;

	//takes as filter vertex the first vertex
	l_cand.init_scan(bbo::NON_DESTRUCTIVE_REVERSE);
	int filter_vertex=l_cand.previous_bit();
				
	//main loop
	l_cand.init_scan(bbo::NON_DESTRUCTIVE_REVERSE);
	while(true){
				
		//select pivot (in order)
		int v=l_cand.previous_bit();
		if(v==EMPTY_ELEM) break;
				
		
#ifdef ROOT_VERTEX_PROGRESS
		if(maxac==0)
			cout<<"root vertex: "<<v<<endl;
#endif
			
		//child node generation by masking
		AND(g->get_neighbors(v), l_bb, LISTA_BB(maxac));					//optimized when place second the bitset with higher population
		AND(m_conf[maxac], g->get_neighbors(v), m_conf[MAXACPLUS1]);		//has to be evaluated before the leaf node check

		//Leaf node: updates incumbent if necessary
		if( LISTA_BB(maxac).is_empty()){
			if(m_conf[MAXACPLUS1].is_empty()){
		
				res.set_UB(res.get_upper_bound()+1);						//increments solution
#ifdef VIEW_PROGRESS
				m_path[maxac]=v;
				stringstream sstr("");
				for(int i=0; i<=maxac; i++){
					sstr<<m_path[i]<<" ";
				}
				LOG_INFO(sstr.str());
#endif
			}

		l_bb.erase_bit(v);
		m_conf[maxac].set_bit(v);
		continue;
		}

		//greedy pivoting: pivot from conflict set (if possible)
		int pivot=m_conf[MAXACPLUS1].msbn64();
		if(pivot==EMPTY_ELEM){ 
			//conflict set empty: take pivot from P set (no filtering)
			pivot=LISTA_BB(maxac).msbn64();
			AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
			m_cand[MAXACPLUS1].set_bit(pivot);
			/*if(filter_vertex!=EMPTY_ELEM && g->get_neighbors(filter_vertex).is_bit(v)){
				m_cand[MAXACPLUS1].erase_bit(g->get_neighbors(filter_vertex));
				LOG_INFO("FILTER");
			}*/
		}else{
			//pivot from conflict set X
			AND(gc.get_neighbors(pivot), LISTA_BB(maxac), m_cand[MAXACPLUS1]);
			if(filter_vertex!=EMPTY_ELEM && g->get_neighbors(filter_vertex).is_bit(v)){
				m_cand[MAXACPLUS1].print();
				m_cand[MAXACPLUS1].erase_bit(g->get_neighbors(filter_vertex));
				cout<<"depth:"<<maxac<<" v: "<<v<<" pivot: "<<pivot<<" filtered by: "<<filter_vertex<<" ";
				m_cand[MAXACPLUS1].print(); cout<<endl;
			}
			
		}
			
///////////////////////////////////////////////////////
// BRANCHING

		//sets path
		m_path[maxac]=v;	
		res.inc_number_of_steps();
		expand_greedy_conflict_set_with_filter(maxac+1,LISTA_BB(maxac),m_cand[MAXACPLUS1]);  

		//////////////////////////////////////////////
		// Backtrack (does not delete v from path since it will be overwritten in the same level of search tree)
		l_bb.erase_bit(v); 
		m_conf[maxac].set_bit(v);
	
	}// next node

return;		
}

#endif
