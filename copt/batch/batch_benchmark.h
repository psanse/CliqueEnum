//batch_benchmark.h: batch for dimacs tests which generate instances on the fly

#ifndef __BATCH_BENCHMARK_H__
#define __BATCH_BENCHMARK_H__

#include "utils/batch.h"
#include "utils/logger.h"
#include "utils/thread.h"
#include "utils/test_analyser.h"
#include "graph/graph_gen.h"
#include "../clique/clique_types.h"
#include "../common/common_clq.h"

#include <iostream>
#include <string>

using namespace std;


template <class Graph_t, class AlgBase_t>
class BatchCLQBk:public Batch<AlgBase_t, clqo::param_t>{
public:
	template <class Benchmark_t>
	int benchmark_test(Benchmark_t& b, ostream& o, int nRep=1, bool weighted=false ){		//tests have already been added with proper configuration params, benchmark is loaded
		TestAnalyser tAna;										
		bool first_alg;												//true--> first test/repetition, false: same test/repetition diff. alg

		o<<PrecisionTimer::local_timestamp();

		vector<string> names=b.getArrayOfFilenames();
		for(int i=0; i<names.size(); i++){							//loops over all graphs
			
			//create the graph
			Graph_t ug(names[i]);
			if(ug.number_of_vertices()==0){
				LOG_ERROR("benchmark_test: "<<names[i]<<"<<not found");
				continue;
			}	

			//generate weights in case it doesn´t have (23/8/17)
			if(weighted && !ug.is_weighted_v()){
				WeightGen<Graph_t>::create_wgraph(ug, WeightGen<Graph_t>::type_t::WMOD, WMODE_WEIGHTS);
			}
					

			stringstream sstr;
			ug.print_data(true, sstr);			
			LOG_WARNING(sstr.str());										

			int bk_lb=b.get_Value(names[i]);
			
			for(int r=0; r<nRep; r++){
				first_alg=true;
				for(int t=0; t<tests.size(); t++){
					Graph_t ug_test(ug);										//copy required: dif. tests may have diff. ordering strategies
					if(start_test(ug_test, t, first_alg, tAna, bk_lb)==-1){
						LOG_ERROR("benchmark_test: Error in test ");
					}
					if(first_alg) first_alg=false; 
				}//next alg
			}
			
			//analysis of results for current graph
			if(comclq::analyse_and_clean(tAna, o)==-1){
				LOG_ERROR("benchmark_test: Error in test analyser");
				return -1;
			}

		}//next graph

		return 0;
	}

	template <class Benchmark_t>
	int complement_benchmark_test(Benchmark_t& b, ostream& o, int nRep=1){	//solves problem for complement graph
		TestAnalyser tAna;										
		bool first_alg;												//true--> first test/repetition, false: same test/repetition diff. alg

		o<<PrecisionTimer::local_timestamp();

		vector<string> names=b.getArrayOfFilenames();
		for(int i=0; i<names.size(); i++){							//loops over all graphs
			
			//create the graph
			Graph_t ug(names[i]);
			Graph_t ugc;
			ug.create_complement(ugc);
			ugc.set_name(ug.get_name());
			
			if(ugc.number_of_vertices()==0){
				LOG_ERROR("benchmark_test: "<<names[i]<<"<<not found");
				continue;
			}			

			stringstream sstr;
			ugc.print_data(true, sstr);			
			LOG_WARNING(sstr.str());										

			int bk_lb=b.get_Value(names[i]);
			
			for(int r=0; r<nRep; r++){
				first_alg=true;
				for(int t=0; t<tests.size(); t++){
					Graph_t ug_test(ugc);										//copy required: dif. tests may have diff. ordering strategies
					if(start_test(ug_test, t, first_alg, tAna, bk_lb)==-1){
						LOG_ERROR("benchmark_test: Error in test ");
					}
					if(first_alg) first_alg=false; 
				}//next alg
			}
			
			//analysis of results for current graph
			if(comclq::analyse_and_clean(tAna, o)==-1){
				LOG_ERROR("benchmark_test: Error in test analyser");
				return -1;
			}

		}//next graph

		return 0;
	}



	int random_test(const string& PATH, random_attr_t r, ostream& o, bool weighted=false){
	//PATH may have slash at the end or not 

		std::string name("");				
		std::string path(PATH);	
		stringstream sstr, sstr_print_data;
		TestAnalyser tAna;					
		bool first_alg;

		//create full filename taking into account SO
		com::dir::append_slash(path);

		o<<PrecisionTimer::local_timestamp();
		for(int tam=r.nLB;tam<=r.nUB;tam+=r.incN) {
			for(double den=r.pLB;den<=r.pUB;den+=r.incP){
				name=path;
				name+="r";
				sstr.str("");
				sstr<<tam<<"_"<<den;
				name+=sstr.str();
				
				for(int rep=0;rep<r.nRep;rep++){
					sstr.str(""); sstr<<rep;
					Graph_t ug(name+"_"+sstr.str()+".txt");							//READS BBDD *** CHECK
					stringstream sstr;
					ug.print_data(true,sstr);			
					LOG_WARNING(sstr.str());

					//generate weights in case it doesn´t have (23/8/17)
					if(weighted && !ug.is_weighted_v()){
						WeightGen<Graph_t>::create_wgraph(ug, WeightGen<Graph_t>::type_t::WMOD, WMODE_WEIGHTS);
					}
					
					first_alg=true;
					for(int t=0; t<tests.size(); t++){
						Graph_t ug_test(ug);										//copy required: dif. tests may have diff. ordering strategies
						if(start_test(ug_test, t, first_alg, tAna)==-1){
							LOG_ERROR("benchmark_test: Error in test ");
						}
						if(first_alg) first_alg=false; 
					}
				}
				
				if(comclq::analyse_and_clean(tAna, o)==-1){
					LOG_ERROR("benchmark_test: Error in test analyser");
					return -1;
				}
			}
		}

		return 0;
	}

	int run_single_instance(string filename, ostream& o, bool weighted=false){
	/////////////////
	// tests for a single instance

		TestAnalyser tAna;	
		Graph_t ug(filename);											//***check consistency
		stringstream sstr;
		ug.print_data(true, sstr);			
		LOG_WARNING(sstr.str());

		//generate weights in case it doesn´t have (23/8/17)
		if(weighted && !ug.is_weighted_v()){
			WeightGen<Graph_t>::create_wgraph(ug, WeightGen<Graph_t>::type_t::WMOD, WMODE_WEIGHTS);
		}
		
		o<<PrecisionTimer::local_timestamp();
		bool first_alg=true;
		for(int t=0; t<tests.size(); t++){
			Graph_t ug_test(ug);										//copy required: dif. tests may have diff. ordering strategies
			if(start_test(ug_test, t, first_alg, tAna)==-1){
				LOG_ERROR("benchmark_test: Error in test ");
			}
			if(first_alg) first_alg=false; 
		}

		if(comclq::analyse_and_clean(tAna, o)==-1){
			LOG_ERROR("benchmark_test: Error in test analyser");
			return -1;
		}

		return 0;
	}
			
	vint run_single_instance(Graph_t& ug, ostream& o){
	/////////////////
	// runs single_instance (single test mode) 
	// returns solution (or EMPTY if ERROR)
	//
	// Remarks: does not change input graph ug (copies the graph first)
	
		TestAnalyser tAna;							
		stringstream sstr;
		ug.print_data(true, sstr);			
		LOG_WARNING(sstr.str());
		if(tests.size()>1){
			LOG_ERROR("benchmark_test: only one test is possible");
			return vint();
		}
		
		o<<PrecisionTimer::local_timestamp();
		Graph_t ug_test(ug);													//copy required: dif. tests may have diff. ordering strategies
		if(start_test(ug_test, 0, true, tAna)==-1){
			LOG_ERROR("benchmark_test: Error in test ");
			return vint();
		}
				
		if(comclq::analyse_and_clean(tAna, o)==-1){
			LOG_ERROR("benchmark_test: Error in test analyser");
			return vint();
		}
		
		return	Batch<AlgBase_t, clqo::param_t>::get_test(0)->decode_first_solution();		
	}



	template <class Benchmark_t>
	int compare_two_tests(Benchmark_t& b, clqo::find_t type, ostream& o){
	///////////////////////
	// compares two tests and stops when type is not consistent
	//
	// REMARKS
	// 1-Once found an inconsistency tests will not continue
	// 2-Repetition of the same instance is not allowed

		if(this->number_of_tests()!=2){
			LOG_ERROR("compare_two_tests: Error in the number of tests");
			return -1;
		}

		TestAnalyser tAna;	
		
		o<<PrecisionTimer::local_timestamp();
		vector<string> names=b.getArrayOfFilenames();
		for(int i=0; i<names.size(); i++){							//loops over all graphs
						
			//create the graph
			Graph_t ug(names[i]);
			stringstream sstr;
			ug.print_data(true, sstr);			
			LOG_WARNING(sstr.str());										

			int bk_lb=b.get_Value(names[i]);
						

			bool first_alg=true;
			for(int t=0; t<tests.size(); t++){
				Graph_t ug_test(ug);										//copy required: dif. tests may have diff. ordering strategies
				if(start_test(ug_test, t, first_alg, tAna, bk_lb)==-1){
					LOG_ERROR("benchmark_test: Error in test ");
				}
				first_alg=false; 
			}

			//analyse
			TestAnalyser::info_t info;
			if(comclq::analyse_and_clean(tAna,o, &info)==-1){
				LOG_ERROR("benchmark_test: Error in test analyser");
				return -1;
			}

			switch(type){
			case clqo::DIFFERENT_STEPS:
				if(!info.same_steps){
					LOG_WARNING("*******************DIFFERENT STEPS*****************************");
					LOG_WARNING(ug.get_name());
					LOG_WARNING("***************************************************************");
					return 1;
				}
				break;
			case clqo::DIFFERENT_CLIQUE_SIZE:
				if(!info.same_sol){
					LOG_WARNING("*******************DIFFERENT CLIQUE SIZE***********************");
					LOG_WARNING(ug.get_name());
					LOG_WARNING("***************************************************************");
					return 1;
				}
				break;
			}
		}//next instance
		
		return 0;
	}

private:
	using  Batch<AlgBase_t, clqo::param_t>::tests;

	int start_test(Graph_t& g,  int test_id, bool first_alg, TestAnalyser& tAna, int lb=0){
	///////////////////////
	// Launches single test (test_id) as a thread and adds results to analyser

		//**TODO- preprocess graph in place here (i.e. initial sorting for all tests)
		
		tests[test_id]->set_graph(&g);

		//updates instance bounds if appropiate
		tests[test_id]->clear_ubound();											//***at the moment not using upper bound info
		if(lb>0)
			tests[test_id]->get_param().lb=lb;

		int res=tests[test_id]->set_up();
	
		if(res==-1 || res>0){ 
			if(res>0)
				tAna.add_test(first_alg, tests[test_id]->get_result());			//adds setup result of trivial sol
			return res;															//error or trivial solution found
		}

		//launch thread
		Thread<AlgBase_t, void>::Start(&AlgBase_t::run, tests[test_id], tests[test_id]->get_param().tout*1000);
		
		//configure tests
		tests[test_id]->tear_down();
		tAna.add_test(first_alg, tests[test_id]->get_result());
		return res;
	}
};


#endif