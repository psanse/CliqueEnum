#include "./clique/clique_types.h"
#include "tclap/CmdLine.h"

#include <iostream>

using namespace std;
using namespace TCLAP;


class input{
public:
	input(int argc_o, char** argv_o):argc(argc_o),argv(argv_o){
		
		for(int i=0; i<NUM_ENUM_INIT_PREPROC; i++)
					allowed_init_preproc.push_back(i);
		
		set_allowed_algorithms();
		for(int i=0; i<allowed_algorithms.size(); i++)
					allowed_algorithms_constraints.push_back(i);

		for(int i=0; i<NUM_ENUM_INIT_ORDER; i++)
					allowed_init_order.push_back(i) ;
		
		set_cmd_message();
	}
		
	clqo::param_t parse(){
		clqo::param_t p;
		try{
			CmdLine cmd(cmd_message, ' ', "1.0");
						
			ValueArg<int> lbArg("l","lower_bound","initial solution", false, 0,"int");
			cmd.add( lbArg);
			ValueArg<int> ubArg("u","upper_bound","initial upper bound", false, CLQ_MAXINT,"int");
			cmd.add( ubArg);

			ValuesConstraint<int> allowedColors(allowed_init_preproc);
			ValueArg<int> ippArg("p","init_preproc","initial preprocessing strategy", false, 0, &allowedColors);
			cmd.add( ippArg);

			ValuesConstraint<int> allowedSorting(allowed_init_order);
			ValueArg<int> iordArg("o","init_ord","initial sorting strategy", false, 0, &allowedSorting);		 //default RLF_COND
			cmd.add( iordArg);

			ValuesConstraint<int> allowedAlg(allowed_algorithms_constraints);
			ValueArg<int> algArg("a","algorithm","concrete algorithmic variant to run", false, 0, &allowedAlg);	 //default BBMC
			cmd.add( algArg);
					
			ValueArg<string> fileArg("f","filename","name of graph", true, "NO FILE","string");
			cmd.add( fileArg );

			SwitchArg unroll("r", "unrolling", "do loop unrolling", false);
			cmd.add( unroll);

			ValueArg<int> threadsArg("x","threads","number of threads", false, 1, "int");
			cmd.add( threadsArg);

			ValueArg<int> toutArg("t","timeout","time limit", false, 0, "int");
			cmd.add( toutArg);

			//parsing
			cmd.parse( argc, argv );

			//reading input
			p.lb=lbArg.getValue();
			p.ub=ubArg.getValue();
			p.init_preproc=(clqo::init_preproc_t)ippArg.getValue();
			p.init_order=(clqo::init_order_t)iordArg.getValue();
			p.alg=(clqo::algorithm_t)allowed_algorithms[algArg.getValue()];
			p.unrolled=unroll.getValue();
			p.nThreads=threadsArg.getValue();
			p.tout=toutArg.getValue();
			p.filename=fileArg.getValue();
					
		}catch(ArgException &e) {
			cerr << "error: " << e.error() << " for arg " << e.argId() << endl;
		}
		return p;
	}

protected:
	void set_cmd_message(){
		cmd_message.clear();
		cmd_message.assign("ALGORITHMS (-a): ");
		stringstream sstr;
		for(int i=0; i<allowed_algorithms.size(); i++){
			switch(allowed_algorithms[i]){
			case clqo::algorithm_t::BBMC:
				sstr.str("");
				sstr.clear();
				sstr<<i;
				cmd_message+=(sstr.str()+"-BBMC ");
				break;
			/*case clqo::algorithm_t::BBMC_T:
				cmd_message+="1-BBMC_T ";
				break;*/
			case clqo::algorithm_t::BBMCR:
				sstr.str("");
				sstr.clear();
				sstr<<i;
				cmd_message+=(sstr.str()+"-BBMCR ");
				break;
			case clqo::algorithm_t::BBMCL_R:
				sstr.str("");
				sstr.clear();
				sstr<<i;
				cmd_message+=(sstr.str()+"-BBMCL ");
				break;
			/*case clqo::algorithm_t::BBMCL_T:
				cmd_message+="4-BBMCL_T ";
				break;*/
			/*case clqo::algorithm_t::BBMCL_R:
				cmd_message+="5-BBMCL_R ";
				break;*/
		/*	case clqo::algorithm_t::BBMC_W:
				sstr.str("");
				sstr.clear();
				sstr<<i;
				cmd_message+=(sstr.str()+"-BBMC_W ");
				break;
			case clqo::algorithm_t::BBMC_WT:
				sstr.str("");
				sstr.clear();
				sstr<<i;
				cmd_message+=(sstr.str()+"-BBMC_WT ");
				break;*/
			case clqo::algorithm_t::BBMCXR:
				sstr.str("");
				sstr.clear();
				sstr<<i;
				cmd_message+=(sstr.str()+"-BBMCXR ");
				break;
			}
		}
	//initial order
		cmd_message.append("\n INITIAL ORDER (-o): ");
		for(int i=0; i<allowed_init_order.size(); i++){
			switch(allowed_init_order[i]){
			case clqo::init_order_t::RLF_COND:
				cmd_message+="0-rlf vs. min-deg-last ";
				break;
			case clqo::init_order_t::MIN_WIDTH_MIN_TIE_STATIC:
				cmd_message+="1-min-deg-last with support tiebreak ";
				break;
			case clqo::init_order_t::MIN_WIDTH:
				cmd_message+="2-min-deg-last ";
				break;
			case clqo::init_order_t::MAX_WIDTH:
				cmd_message+="3-max-deg-last ";
				break;
			case clqo::init_order_t::MIN_WIDTH_KCORE:
				cmd_message+="4-kcore ";
				break;
			case clqo::init_order_t::RLF:
				cmd_message+="5-rlf ";
				break;
			case clqo::init_order_t::NONE:
				cmd_message+="6-none ";
				break;
			}
		}

	//initial preprocessing
		cmd_message.append("\n INITIAL PREPROCESSING (-p): ");
		for(int i=0; i<allowed_init_preproc.size(); i++){
			switch(allowed_init_preproc[i]){
			case clqo::init_preproc_t::UB_HEUR:
				cmd_message+="0-heur + infrachrom_UB ";
				break;
			case clqo::init_preproc_t::HEUR:
				cmd_message+="1-heur ";
				break;
			case clqo::init_preproc_t::UB:
				cmd_message+="2-infrachrom_UB ";
				break;
			}
		}
		
	}

	void set_allowed_algorithms();
	
private:
	int argc;
	char** argv;
	vector<int> allowed_init_order;
	vector<int> allowed_init_preproc;
	vector<int> allowed_algorithms;						/* maps-[INDEX]-->[clqo::algorithm_t]*/
	vector<int> allowed_algorithms_constraints;			/* index values to map real algorithms */
	string cmd_message;
};



inline 
void input::set_allowed_algorithms(){
////////////////////
// maps the valid algorithms for the run()
//
	allowed_algorithms.push_back(clqo::algorithm_t::BBMC);
	allowed_algorithms.push_back(clqo::algorithm_t::BBMCR);
	allowed_algorithms.push_back(clqo::algorithm_t::BBMCL_R);
	allowed_algorithms.push_back(clqo::algorithm_t::BBMCXR);

}

