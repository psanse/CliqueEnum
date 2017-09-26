//common_clq.h: common utilities for clique the project

#ifndef __COMMON_CLQ_H__
#define	__COMMON_CLQ_H__


#include <iostream>
#include <string>
#include "utils/test_analyser.h"
#include "graph/graph.h"

namespace comclq{
	struct range_t{
		//positive intervals used in CSP as MCP
		int vl, vh; 
		range_t(int lh, int rh):vl(lh), vh(rh){}
		range_t():vl(EMPTY_ELEM), vh(EMPTY_ELEM){}
		ostream& print(ostream& o){o<<"["<<vl<<","<<vh<<"]"; return o;}
	};

inline
int analyse_and_clean(TestAnalyser& tAna, ostream& o, TestAnalyser::info_t* info = NULL){
//////////////////////
//analyses data for a test/single repetition
//
// COMMENTS:
// 1-resets analyser 
// 2-outputs to stream

	if(tAna.analyser(info)==-1){
		return -1;
	}else o<<tAna;	

	tAna.clear();
	return 0;
}

template<class Graph_t>
int graph_to_dimacs(Graph_t ug, string filename){
	ofstream f(filename);   
	if(f){
		ug.write_dimacs(f);
		f.close();
		return 0;
	}
	return -1;
}


}//mamespace

#endif
