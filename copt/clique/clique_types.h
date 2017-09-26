//clique_types.h: specific types for clique algorithms
//date: 13/02/15
//author: pss

#ifndef __CLIQUE_TYPES_H__
#define __CLIQUE_TYPES_H__

#include <iostream>
#include <string>
#include "utils/result.h"
#include "graph/algorithms/decode.h"
#include "graph/algorithms/graph_sort.h"					

using namespace std;
typedef vector<int> vint;

////////////*** possibly remove
#define NUM_ENUM_ALGORITHM		9
#define NUM_ENUM_INIT_PREPROC	3
#define NUM_ENUM_INIT_ORDER		7								//up to, and including, RFL_COND
///////////////////////////////////////

#define CLQ_MAXINT	   0x1FFFFFFF								//my own MAX_INT

#define STORE_SOLUTION			0x0
//#define VIEW_PROGRESS			0x1
#define STRONG_ROOT_COLORING	0x2								//computes tight UBs at the root and CUTS at the root in some variants	(deprecated for cliquesat and cliqueiter-9/6/16)					
//#define ROOT_VERTEX_PROGRESS	0x3
#define ENHANCED_INIT_UB		0x4								//infra-chrom initial bounds
#define AMTS_LB				    0x6								//computes strong initial solution with AMTS heuristic					(deprecated for cliquesat and cliqueiter 9/6/16)
#ifdef AMTS_LB
	#define RESTARTS				50							//changed from 50 in 5/16 -TODO** change to a constant data in clqo
	#define ITERATIONS_PER_RESTART  50000						//changed from 25000 to 50000 in 19/10/2016
#endif

//#ifdef AMTS_LB
//	#define RESTARTS				10							//changed from 50 in 5/16 -TODO** change to a constant data in clqo
//	#define ITERATIONS_PER_RESTART  1000						//changed from 25000 to 50000 in 19/10/2016
//#endif

///////////////
//PRE-PROCESSING
#define EVAL_OF_COLOR_TAIL_IN_RLF_COND		0x50

//////////////
//Test Configuration

#define TESTS_DIMACS				0x7										//switch STRUCTURED (DIMACS, CSP, BHOSLIB,...) / RANDOM 
//#define BENCHMARK_PATH			"C:/Users/i7/Desktop/color"
//#define BENCHMARK_PATH			"C:/Users/pablo/Desktop/"
//#define BENCHMARK_PATH			   "C:/Users/pablo/Desktop/dimacs"	
#define BENCHMARK_PATH				"C:/Users/i7/Desktop/dimacs_w"	
//#define BENCHMARK_PATH			"C:/Users/pablo/Desktop/csp_all"	
//#define BENCHMARK_PATH			"C:/Users/pablo/Desktop/vcp"	
//#define BENCHMARK_PATH			"C:/Users/pablo/Desktop/weighted"

//#define BENCHMARK_WEIGHTED_PATH		"C:/Users/pablo/Desktop/dimacs_w"
#define BENCHMARK_WEIGHTED_PATH		"C:/Users/pablo/Desktop/dimacs"
//#define BENCHMARK_WEIGHTED_PATH		"C:/Users/pablo/Desktop/WDP-dimacs/group1"
//#define BENCHMARK_RANDOM_PATH		"C:/Users/pablo/Desktop/random_w"
#define BENCHMARK_RANDOM_PATH		"C:/Users/pablo/Desktop/random_1"
//#define BENCHMARK_RANDOM_PATH		"C:/Users/i7/Desktop/random"
//#define BENCHMARK_RANDOM_PATH		"C:/Users/i7/Desktop/random"
//#define LOG_DIMACS				"C:/Users/i7/Desktop/color.txt"	
#define LOG_DIMACS					"C:/Users/pablo/Desktop/log_dimacs_w.txt"
#define LOG_RANDOM					"C:/Users/pablo/Desktop/log_random_w.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/w_dimacs_20_10_16.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/wd_dimacs_02_11_16.txt"
///#define LOG_DIMACS_POSIX			"/var/www/logs/partition_22_11_16.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/goms_23_11_16.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/enum_color_29_11_16.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/enum_dimacs_09_1_17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/enum_flat_06_1_17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/enum_random_02_1_17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/enum_dsjc_06_1_17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/rdoll_dimacs_28_12_16.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/pmaxsat_frb_29_12_16.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/pmaxsat_keller_29_12_16.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/rdoll_frb_30_12_16.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/pmaxsat_vcp_30_12_16.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/pmaxsat_28_12_16.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/color_maxclq_29_11_16.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/enum_1_1_17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/pmaxsat_dimacs.24h.24.1.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/rdoll_dimacs.24h.24.1.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/bbmcx.miso.noub.24h.08.02.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/bbmcx.mw.noub.brock400.24h.09.02.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/weighted.24h.29.08.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/weighted_imp_overlap.24h.31.08.17.txt"	
//#define LOG_DIMACS_POSIX			"/var/www/logs/weighted_top2_split.1h.5.09.17.txt"	
//#define LOG_DIMACS_POSIX			"/var/www/logs/weighted_top2_split.bug.free.1h.5.09.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/weighted_top2_split.2round.1h.09.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/weighted_top2_split.cov.ord.1h.7.09.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/weighted_top2_split.2r.1h.7.09.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/weighted_imp_pp.1h.7.09.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/weighted_imp.rw.1h.12.09.17.txt"
#define LOG_DIMACS_POSIX			"/var/www/logs/weighted_imp.rw.paint.1h.16.09.17.txt"
//#define LOG_DIMACS_POSIX_WDP		"/var/www/logs/weighted_imp_pp.wdp.1h.08.09.17.txt"
#define LOG_DIMACS_POSIX_WDP		"/var/www/logs/weighted_imp_pp.wdp.1h.16.09.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/weighted_top2_split.pp.1h.5.09.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/bbmcx.mwt.noub.24h.06.02.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/bbmcx.miso.ub.24h.07.02.17.txt"
//#define LOG_DIMACS_POSIX			"/var/www/logs/bbmcx.monotone.mwt.noub.24h.08.02.17.txt"

//#define LOG_RANDOM_POSIX			"/var/www/logs/rand_w_20_10_16.txt"
//#define LOG_RANDOM_POSIX			"/var/www/logs/rand_pmaxsat_dyn_21_12_16.txt"
//#define LOG_RANDOM_POSIX			"/var/www/logs/rand_enum_07_01_17.txt"
//#define LOG_RANDOM_POSIX			"/var/www/logs/rand_bbmcx_miso_02_02_17.txt"
//#define LOG_RANDOM_POSIX			"/var/www/logs/rand_bbmcx.miso.noub.05_02_17.txt"
//#define LOG_RANDOM_POSIX			"/var/www/logs/rand_bbmcx.miso.ub.09_02_17.txt"
//#define LOG_RANDOM_POSIX			"/var/www/logs/weighted_rand.29.08.17.txt"
//#define LOG_RANDOM_POSIX			"/var/www/logs/weighted_rand_sw.02.09.17.txt"
//#define LOG_RANDOM_POSIX			"/var/www/logs/weighted_rand_sw.03.09.17.txt"
#define LOG_RANDOM_POSIX			"/var/www/logs/weighted_rand_final.08.09.17.txt"
//#define LOG_RANDOM_POSIX			"/var/www/logs/weighted_rand_sw.pp.05.09.17.txt"

#define BENCHMARK_PATH_POSIX		"/media/datos/graphs/dimacs_bhosh/"
#define BENCHMARK_PATH_POSIX_WDP	"/media/datos/graphs/winner_determination/WDP-dimacs/all"
//#define BENCHMARK_PATH_POSIX		"/media/datos/graphs/frb_zavalnij/evil-tests/"
//#define BENCHMARK_PATH_POSIX		"/media/datos/graphs/frb_zavalnij/monotone/"
//#define BENCHMARK_PATH_POSIX		"/media/datos/graphs/vcp/"
//#define BENCHMARK_PATH_POSIX		"/media/datos/graphs/color/"
//#define BENCHMARK_PATH_POSIX		"/media/datos/graphs/large_sparse/benchmark/"

#define BENCHMARK_RANDOM_PATH_POSIX	"/media/datos/graphs/random/"

//p-MaxsaT params (switch all flags for best performance of Russian Doll unweighted)
#define TEST_ELIMINATE_FAILED_NODES					0x8					//switch to find one more conflict by proving all nodes are FAILED in a CLAUSE
#define TEST_LOOK_AHEAD_ISETS						0x9
//#define FIVE_ISET_FILTER							0x10				/*alternates between 4 and 5 ndoes in color sets where nodes may be removed */
#ifdef TEST_LOOK_AHEAD_ISETS	
	#define FURTHER_TEST_FAILED_COLOR_SETS			0x11				//switch to involve reduced stack when FAILING CLAUSES
#endif
#ifdef TEST_ELIMINATE_FAILED_NODES
	#define FURTHER_TEST_ELIMINATE_FAILED_NODES		0x12				//switch for involving reduced stack when trying to FAIL all nodes in a CLAUSE
#endif 
#define MAX_SIZE_FAILED_COLOR_SET					2					//size of largest possible FAILED CLAUSE analysed for lookahead inferences (2 is nice for CSP)

//////////////
//Weights
/////////////
#define TEST_WEIGHTED_FAILED_LITERALS				0x30

//russian doll params
#define RDOLL_INC_UB_CUT							0x13
//#define RDOLL_MIN_UB_ON_RETURN					0x14

//weighted clique parameters
//** choose extension W or D for weights in graph in simple_graph.h

///////////////////
//AMTS heuristic (with and without weights)
//IMPORTANT!: if graph is tagged as weighted, AMTS will use the correct weights; if graph is not tagged as weighted, AMTS will create the weights (1)  
//#define WMODE_WEIGHTS								1					//wi=i*mod(WMODE_WEIGHTS)+1, i:1...N , WMODE_WEIGHTS=1 is the unweighted case (1)
#define WMODE_WEIGHTS								200					

class clqo{
//////////////////////
// clqo: specific types for all clique algorithms and root object of the hierarchy

public:
	enum algorithm_t{
		BBMC=0, BBMC_T, BBMCR, BBMCL, BBMCL_T, BBMCL_R, BBMC_W, BBMC_WT, BBMCIT, BBMCIT_L, BBMCITX, BBMCITXR, BBMCITX_L, BBMCITXR_L, BBMCITXR_L_SEQ,   
		BBMC_Iter_Root_Enlarge, BBMC_Iter_Root_Enlarge_Sat_R, BBMCX, BBMCX_L, BBMCXR, BBMCXR_L, BBMCXR_L_SEQ, BBMCD, BBMCD_XR_LN, BBMCNF, BBMCNF_iter,
		BBMC_EN_GCONF, BBMC_EN_GCONF_X, BBMC_EN_GCONF_Xm, BBMC_EN_GCONF_XP, BBMC_EN_GCONF_XPm, BBMC_EN_GCONF_HEUR, BBMC_EN_GCONF_INIT, BBMC_EN_GCONF_GRAPH,
		BBMC_EN_GCONF_GRAPH_X, BBMC_EN_GCONF_GRAPH_XP, BBMC_EN_GCAND, BBMC_EN_GCONF_FILTER, BBMC_EN_GCAND_FILTER, BBMCR_LOOK_AHEAD, BBMC_KMIN, BBMCR_KMIN, BBMCRL_KMIN, BBMCR_KMIN_COMB,
		BBMCR_KMIN_LOOK_AHEAD, BBMC_SORT, BBMC_KMIN_SORT, BBMCR_KMIN_SORT, BBMCR_KMIN_LOOK_AHEAD_SORT, BBMCR_SORT, BBMCR_LOOK_AHEAD_SORT, BBMCR_KMIN_2C, 
		BBMC_OS, BBMCR_KMIN_SORT_2C, BBMCR_KMIN_SORT_3C, BBMC_DOLL_LISTS, BBMCR_DOLL_LISTS, COL, BBMC_DOLL, BBMC_CSP_OPT, BBMCR_DOLL,BBMCR_NOX_DOLL , BBMC_CSP, BBMC_CSP_SUBSET, 
		BBMC_WEIGHTED_BASIC, BBMC_WEIGHTED, BBMC_WEIGHTED_DOUBLE, BBMC_WEIGHTED_SHARED_TESTS, BBMC_WEIGHTED_SHARED_PREPROC, BBMC_WEIGHTED_SHARED_PREPROC_CW,BBMC_WEIGHTED_SHARED_PREPROC_CW_RD,
		BBMC_WEIGHTED_SHARED_REF,  BBMC_WEIGHTED_SHARED_PREPROC_CW_SUPER_WEIGHT, BBMC_WEIGHTED_SHARED_PREPROC_CW_SUPER_WEIGHT_3S, BBMCR_WEIGHTED, BBMCX_WEIGHTED, BBMCR_SAT_WEIGHTED, BBMCL_PLUS};

	enum init_preproc_t	{UB_HEUR=0, HEUR, UB};	
	enum init_order_t	{RLF_COND=0, MIN_WIDTH_MIN_TIE_STATIC, MIN_WIDTH, MAX_WIDTH, MAX_WIDTH_MAX_TIE, MAX_WIDTH_MAX_TIE_STATIC,  MAX_ABS, MIN_WIDTH_KCORE, RLF, NONE, MIN_WIDTH_COMPOSITE, MIXED_2, MIXED_3, MIXED_4, 
		MIXED_5, MIXED_6, MIXED_7, MIXED_8, MIXED_9, MIXED_10, RLF_SORT_DOLL, RLF_SORT_BBMC, MAX_WEIGHTED, MIN_WEIGHTED, MAX_WEIGHTED_DEG, MIN_WEIGHTED_DEG, WEIGHTED_DOUBLE_GRAPH, CSP, CSP_RLF,CSP_FILTER };			//sorting strategies

	//to compare two algorithms
	enum find_t	{ DIFFERENT_CLIQUE_SIZE=0,	DIFFERENT_STEPS,  DIFFERENT_STEPS_FIRST_GREATER, DIFFERENT_STEPS_FIRST_GREATER_BY_A_FACTOR, GREATER_CLIQUE_FIRST, \
		GREATER_CLIQUE_SECOND, 	GREATER_STEPS_FIRST, 	GREATER_STEPS_SECOND  };

	//isomorphism mapping (21/8/17)	
	struct isomap_t{
		pair<gbbs::sort_t, gbbs::place_t> lhs;
		pair<gbbs::sort_t, gbbs::place_t> rhs;
		isomap_t():lhs(pair<gbbs::sort_t, gbbs::place_t>(gbbs::sort_t::MIN_DEG_DEGEN,gbbs::place_t::PLACE_LF)), 
				   rhs(pair<gbbs::sort_t, gbbs::place_t>(gbbs::sort_t::MAX_WEIGHT,gbbs::place_t::PLACE_FL)){}
	};

	//parameter info
	struct param_t{
		param_t():lb(0), ub(CLQ_MAXINT),init_preproc(UB_HEUR), init_order(MIN_WIDTH), alg(BBMC), nThreads(1), tout(0), unrolled(false), isomorphism(false), filename(""){};
		void print(ostream& o=cout){ 
			o<<"\n";
			o<<"lb: "<<lb<<endl;
			o<<"ub: "<<ub<<endl;
			o<<"icol: "<<init_preproc<<endl;
			o<<"iord: "<<init_order<<endl;
			o<<"alg: "<<alg<<endl;
			o<<"unrolled: "<<unrolled<<endl;
			o<<"nThreads: "<<nThreads<<endl;
			o<<"time_out: "<<tout<<endl;
			o<<"filename: "<<filename<<endl;
			//*** TODO: represent boolean parameters ***
		}
		void print_algorithm(ostream& o=cout){
			switch(alg){
			case 0:
				o<<"BBMC algorithm selected"<<endl;
				break;
			case 1:
				o<<"BBMC_T algorithm selected"<<endl;
				break;
			case 2:
				o<<"BBMCR algorithm selected"<<endl;
				break;
			case 3:
				o<<"BBMCL algorithm selected"<<endl;
				break;
			case 4:
				o<<"BBMCL_T algorithm selected"<<endl;
				break;
			case 5:
				o<<"BBMCL_R algorithm selected"<<endl;
				break;
			case 6:
				o<<"BBMC_W algorithm selected"<<endl;
				break;
			case 7:
				o<<"BBMC_WT algorithm selected"<<endl;
				break;
			default:
				o<<"non-reference algorithm selected"<<endl;
			}
		}

		int lb;										//initial solution (lower bound)
		int ub;										//initial upper bound (may be used for reduced initial allocation)
		init_preproc_t init_preproc;				//inital preprocessing (heur for LB, color or infrachrom for UB)
		init_order_t init_order;				    //initial sorting strategy
		algorithm_t alg;						    //concrete variant
		bool unrolled;								//TRUE: initial loop unrolling
		int nThreads;
		int tout;									//seconds
		string filename;

		bool isomorphism;							//TRUE: uses isomorphic graphs: one for enumeration, one for bounding. init_order should start with MAP_XXX (20/8/17)
		isomap_t iso_map;							//Glhs, Grhs isomorphisms (DEFAULT MIN_DEG_DEGEN, MAX_WEIGHT). Currently only for max weighted clique
	};

	//search allocation info
	struct search_alloc_t {
		enum {ALLOC_BITARRAYS=0x01, ALLOC_NODELISTS=0x02, ALLOC_COLOR_LABELS=0x04, ALLOC_OTHERS=0x08,  ALLOC_COLOR_SETS=0x10};
		search_alloc_t():size(0), mem(ALLOC_BITARRAYS | ALLOC_NODELISTS | ALLOC_COLOR_LABELS | ALLOC_OTHERS ){}		//basic configuration for BBMC
		void set(int prop){mem|=prop;}
		void remove (int prop){mem &=~ prop;}
		void clear(){mem=0; size=0;}
		bool is_set(int prop){ return mem & prop;}
		int size;									//connected with bounds, not necessarily the number of vertices
		unsigned int mem;							//extra requirements as OR (ALLOC_DEF(fixed) | COLOR_SETS etc.)
	};

protected:
	clqo(){}										/* no instances */										
};


///////////////////
//
// CLQParam: different parameters required by all clique algorithms
//
//////////////////
class CLQParam: public clqo{
public:
	static int is_trivial_sol 	(int lb , int ub){ if((lb>=ub) && (lb!=0)) {return lb;} else return 0;}
		
	void set_param				(param_t p)	{param=p;}
	param_t& get_param			()			{return param;}
	const param_t& get_param	()    const {return param;}
	const Result& get_result	()	  const {return res;}
	Result& get_result			()			{return res;}

	void clear_bounds			()			{param.lb=0; param.ub=CLQ_MAXINT;}
	void clear_ubound			()			{param.ub=CLQ_MAXINT;}
	void clear_lbound			()			{param.lb=0;}

	//decoding
	void clear_decode			()			{d.clear();}	
	vint decode_first_solution	()			{return d.decode_list(res.get_first_solution());}
	vector<vint> decode_all		();				
	Decode&	get_decoder			()			{return d;}

protected:
	CLQParam					(param_t p):param(p){}

////////////////
// data
	param_t param;
	Result	res;					//stores alg info
	Decode  d;						//decodes solution from initial ordering
};


inline
vector<vint> CLQParam::decode_all(){
//////////////
// decodes all solutions (15/11/16)
	
	vector<vint> sol=res.get_all_solutions();
	vector<vint> dec_res;
	for(int i=0; i<sol.size(); i++){
		dec_res.push_back(d.decode_list(sol[i]));
	}


	return dec_res;
}

#endif 





