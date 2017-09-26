//published_alg.cpp : contains the one and only main.cpp
//
// date of creation: 25/9/17


#include <iostream> 
#include "utils/prec_timer.h"
#include "utils/file.h"
#include "utils/logger.h"
#include "../batch/batch_benchmark.h"
#include "../clique/clique.h"
#include "../input.h"												//uses TCLAP lib to parse command line
#include "../clique/clique_enum.h"

using namespace std;

//////////////
// GreedyBB release for COR publishing (requested by reviewer)
// date: 25/09/2017// 

int main(int argc, char** argv){

	BatchCLQBk< ugraph, Clique<ugraph> > batch;
	input io(argc, argv);
	clqo::param_t p=io.parse();																
	Logger::SetInformationLevel(LOGGER_INFO);			
	LOG_INFO("GreedyBB release for research purposes (25/09/17)" );
				
	p.unrolled=false ;
	p.init_order=clqo::MAX_WIDTH;							
	p.alg = clqo::BBMC_EN_GCONF;	
	p.init_preproc=clqo::UB;
	batch.add_test<CliqueEnum>(p);
	
			
	//configure parameters for all tests
	batch.run_single_instance(p.filename, cout);
	
	cout<<"--------------------------------------------"<<endl;
}

