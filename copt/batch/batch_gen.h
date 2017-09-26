//batch_gen.h: batch for tests which generate instances on the fly

#ifndef __BATCH_GEN_H__
#define __BATCH_GEN_H__


#include "utils/batch.h"
#include "utils/logger.h"
#include "utils/thread.h"
#include "utils/test_analyser.h"
#include "utils/common.h"
#include "utils/file.h"
#include "graph/graph_gen.h"
#include "../clique/clique_types.h"
#include "../common/common_clq.h"

#include <iostream>
#include <string>

using namespace std;

template <class Graph_t, class AlgBase_t>
class BatchCLQGen:public Batch<AlgBase_t, clqo::param_t>{
public:
	int random_test(const string& WRITE_PATH, random_attr_t r, ostream& o, bool weighted=false){
	//////////////////////
	// RETURN VALUE: -1 ERROR, 0 ok
	//
	// extended to weighted case, weights v=v%200 (5/8/17)
		std::string name("");				
		stringstream sstr, sstr_print_data;
		TestAnalyser tAna;					
		bool first_alg;

		//tune slashes for instance path taking into account SO
		std::string wpath(WRITE_PATH);	
		if(!wpath.empty()){
			com::dir::append_slash(wpath);
		}

		o<<PrecisionTimer::local_timestamp();
		for(int tam=r.nLB;tam<=r.nUB;tam+=r.incN) {
			for(double den=r.pLB;den<=r.pUB;den+=r.incP){
				name.clear();
				name="r";
				sstr.str("");
				sstr<<tam<<"_"<<setprecision(4)<<den;
				name+=sstr.str();
				
				for(int rep=0;rep<r.nRep;rep++){
					Graph_t ug;
					RandomGen<Graph_t>::create_ugraph(ug,tam,den);
					if(weighted)
						WeightGen<Graph_t>::create_wgraph(ug, WeightGen<Graph_t>::type_t::WMOD, WMODE_WEIGHTS);
					sstr.str(""); sstr<<rep;
					ug.set_name(name+"_"+sstr.str()+".txt");		//change name appropiately
					stringstream sstr;
					ug.print_data(true,sstr);			
					LOG_WARNING(sstr.str());
					
					//store instance
					if(!wpath.empty()){
						if(comclq::graph_to_dimacs(ug, wpath+ug.get_name())==-1){
							LOG_WARNING("random_test: could not store generated instance");
						}
					}
										
					first_alg=true;
					for(int t=0; t<tests.size(); t++){
						Graph_t ug_test(ug);										//copy required: dif. tests may have diff. ordering strategies
						if(start_test(ug_test, t, first_alg, tAna)==-1){
							LOG_ERROR("random_test: Error in test ");
						}
						if(first_alg) first_alg=false; 
					}
				}//end repetitions
				
				//anlyse all repetions for current instance
				if(comclq::analyse_and_clean(tAna, o)==-1){
					LOG_ERROR("random_test: Error in test analyser");
					return -1;
				}
			}
		}

		return 0;
	}

	int compare_two_tests(const string& WRITE_PATH, random_attr_t r, clqo::find_t type, ostream& o, bool weighted=false){
	//////////////////////////////
	//compares two tests 
	// 
	// RETURN VALUE: -1 Error, 0 no differences found, 1 differences found
	//
	// COMMENTS: uses WMODE_WEIGHTS value for weighted graph generation (23/08/2017)

		if(this->number_of_tests()!=2) {
			LOG_ERROR("compare_two_tests: incorrect number of tests"<<endl);
			return -1;
		}else if(WRITE_PATH.empty()){
			LOG_ERROR("compare_two_tests: incorrect path to write found instances"<<endl);
			return -1;
		}

		std::string name("");				
		stringstream sstr, sstr_print_data;
		TestAnalyser tAna;					
		bool first_alg;

	
		o<<PrecisionTimer::local_timestamp();
		for(int tam=r.nLB;tam<=r.nUB;tam+=r.incN) {
			for(double den=r.pLB;den<=r.pUB;den+=r.incP){
				name.clear();
				name="r";
				sstr.str("");
				sstr<<tam<<"_"<<setprecision(4)<<den;
				name+=sstr.str();
				
				for(int rep=0;rep<r.nRep;rep++){
					Graph_t ug;
					RandomGen<Graph_t>::create_ugraph(ug,tam,den);
					if(weighted)
						WeightGen<Graph_t>::create_wgraph(ug, WeightGen<Graph_t>::type_t::WMOD, WMODE_WEIGHTS);
					sstr.str(""); sstr<<rep;
					ug.set_name(name+"_"+sstr.str()+".txt");		//change name appropiately
					stringstream sstr;
					ug.print_data(sstr);			
					LOG_WARNING(sstr.str());
					
					bool first_alg=true;
					for(int t=0; t<tests.size(); t++){
						Graph_t ug_test(ug);										//copy required: dif. tests may have diff. ordering strategies
						if(start_test(ug_test, t, first_alg, tAna)==-1){
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
						
							std::string wpath(WRITE_PATH);	
							com::dir::append_slash(wpath);
							if(comclq::graph_to_dimacs(ug, wpath+ug.get_name())==-1){ //copies the original graph without ordering
								LOG_ERROR("different steps: cannot store instance in: "<<wpath+ug.get_name());
							}
							LOG_DEBUG("different steps instance written: "<<wpath+ug.get_name());
							LOG_INFO("press 0 to stop, any other key to continue");
							char c[2];
							cin>>c;
							if(atoi(c)==0){
								return 1;
							}
							
						}
						break;
					case clqo::DIFFERENT_STEPS_FIRST_GREATER:
						if(info.steps_first_greater){
							LOG_WARNING("*******************DIFFERENT STEPS: FIRST ALGORITHM GREATER*****************************");
							LOG_WARNING(ug.get_name());
							LOG_WARNING("****************************************************************************************");
						
							std::string wpath(WRITE_PATH);	
							com::dir::append_slash(wpath);
							if(comclq::graph_to_dimacs(ug, wpath+ug.get_name())==-1){ //copies the original graph without ordering
								LOG_ERROR("different steps, first alg greater: cannot store instance in: "<<wpath+ug.get_name());
							}
							LOG_DEBUG("different steps, first alg greater: instance written: "<<wpath+ug.get_name());
													
														
							LOG_INFO("press 0 to stop, any other key to coninue");
							char c[2];
							cin>>c;
							if(atoi(c)==0){
								return 1;
							}
							
						}
						break;
						case clqo::DIFFERENT_STEPS_FIRST_GREATER_BY_A_FACTOR:
						if(info.steps_first_greater){
							LOG_WARNING("*******************DIFFERENT STEPS: FIRST ALGORITHM GREATER*****************************");
							LOG_WARNING(ug.get_name());
							LOG_WARNING("****************************************************************************************");
						
							std::string wpath(WRITE_PATH);	
							com::dir::append_slash(wpath);
							if(comclq::graph_to_dimacs(ug, wpath+ug.get_name())==-1){ //copies the original graph without ordering
								LOG_ERROR("different steps, first alg greater: cannot store instance in: "<<wpath+ug.get_name());
							}
							LOG_DEBUG("different steps, first alg greater: instance written: "<<wpath+ug.get_name());
													

							//captures a particular RATIO of STEPS
							if((info.steps_lhs/(float)info.steps_rhs)>1.75){
								LOG_INFO("different steps-first alg more than 75% steps");
								cin.get();
							}
							
						}
						break;
					case clqo::DIFFERENT_CLIQUE_SIZE:
						if(!info.same_sol){
							LOG_WARNING("*******************DIFFERENT CLIQUE SIZE***********************");
							LOG_WARNING(ug.get_name());
							LOG_WARNING("***************************************************************");
							
							std::string wpath(WRITE_PATH);	
							com::dir::append_slash(wpath);
							if(comclq::graph_to_dimacs(ug, wpath+ug.get_name())==-1){ //copies the original graph without ordering
								LOG_ERROR("different clique size: cannot store instance in: "<<wpath+ug.get_name());
							}
							LOG_DEBUG("different clique instance writtem: "<<wpath+ug.get_name());
							
							return 1;
						}
						break;
					default:
						LOG_ERROR("comparison test: incorrect comparison strategy");
						return -1;
					}
				
				}//end repetitions 
			}
		}

		return 0;			//no differences found
	}

	int find_property(const string& WRITE_PATH, random_attr_t r){
	//Searches for a specific property triggered by an internal condition
	//(customize internal flag of Result)
	//
	// RETURN VALUE: -1 ERROR, 0 property found, 1 property not found
		if(this->number_of_tests()!=1) {
			LOG_ERROR("find_property: not single test"<<endl);
			return -1;
		}else if(WRITE_PATH.empty()){
			LOG_ERROR("find_property: incorrect path to write found instances"<<endl);
			return -1;
		}

		std::string name("");				
		stringstream sstr, sstr_print_data;
		TestAnalyser tAna;					
		bool first_alg;

		
		for(int tam=r.nLB;tam<=r.nUB;tam+=r.incN) {
			for(double den=r.pLB;den<=r.pUB;den+=r.incP){
				name.clear();
				name="r";
				sstr.str("");
				sstr<<tam<<"_"<<setprecision(4)<<den;
				name+=sstr.str();
				
				for(int rep=0;rep<r.nRep;rep++){
					Graph_t ug;
					RandomGen<Graph_t>::create_ugraph(ug,tam,den);
					sstr.str(""); sstr<<rep;
					ug.set_name(name+"_"+sstr.str()+".txt");		//change name appropiately
					stringstream sstr;
					ug.print_data(sstr);			
					LOG_WARNING(sstr.str());

					//launches test
					tests[0]->set_graph(&ug);
					tests[0]->clear_bounds();

					int res=tests[0]->set_up();
					if(res==-1 || res>0) continue;			//error or trivial solution found
					
					//launch thread
					Thread<AlgBase_t, void>::Start(&AlgBase_t::run, tests[0], tests[0]->get_param().tout*1000);

					//configure tests
					tests[0]->tear_down();
														
					//check internals
					if( tests[0]->get_result().get_flag() ){
						LOG_WARNING("*******************PROPERTY_FOUND*****************************");
						std::string wpath(WRITE_PATH);	
						com::dir::append_slash(wpath);
						if(comclq::graph_to_dimacs(ug, wpath+ug.get_name())==-1){ //copies the original graph without ordering
							LOG_ERROR("find_property: cannot store instance in: "<<wpath+ug.get_name());
						}
						LOG_DEBUG("instance written: "<<wpath+ug.get_name());

						cout<<"press 1 to end comparison: any other key to continue"<<endl;
						char c;	cin>>c;	if(c=='1') return 0;	//property found
					}
				}
			}
		}
		return 1; //property not found 
	}

private:

	using  Batch<AlgBase_t, clqo::param_t>::tests;
	
	int start_test(Graph_t& g, int test_id, bool first_alg, TestAnalyser& tAna, int lb=0){
	///////////////////////
	// Launches single test (test_id) as a thread and adds results to analyser
		int res=0;
		tests[test_id]->set_graph(&g);

		//updates instance bounds if appropiate
		tests[test_id]->clear_ubound();				//***at the moment not using upper bound info
		if(lb>0)
			tests[test_id]->get_param().lb=lb;

		res=tests[test_id]->set_up();
		if(res==-1 || res>0){ 
			if(res>0)
				tAna.add_test(first_alg, tests[test_id]->get_result());
			return res;														//error or trivial solution found
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