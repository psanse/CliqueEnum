//graph_func.h: header for general purpose algorithms related to graphs
//date of creation: 07/3/17
//last update: 12/3/17
//authors: pss

#ifndef __GRAPH_FUNC_H__
#define __GRAPH_FUNC_H__

#include "../graph.h"
#include "../kcore.h"
#include "filter_graph_sort_type.h"			//Template Graph_t reduced to undirected types
#include "utils/logger.h"
#include "utils/common.h"
#include <iostream>
#include <algorithm>


using namespace std;

namespace gfunc{
	
	template<class Graph_t> 
	bool is_iset(Graph_t& g, typename Graph_t::bb_type& bb){
	/////////////////
	// TRUE if subgraph bb is and independent set
	//
	// COMMENTS: /* Not optimized for all graph types */

		bitarray neighbor(g.number_of_vertices());
		if(bb.init_scan(bbo::NON_DESTRUCTIVE)==EMPTY_ELEM) return false;	//empty cliqe
		while(true){
			int v=bb.next_bit();
			if (v==EMPTY_ELEM) break;

			//check neighborhood						
			AND(g.get_neighbors(v), bb, neighbor);
			if(!neighbor.is_empty())
					return false;
			 
		}
		return true;
	}

	template<class Graph_t> 
	bool is_clique(Graph_t& g, typename Graph_t::bb_type& bb){
	/////////////////
	// TRUE if subgraph bb is a clique
	//
	// COMMENTS: /* Not optimized for all graph types */
	//
	// /* TODO-CHECK: SIZE OF BB=1

		bitarray neighbor(g.number_of_vertices());
		if(bb.init_scan(bbo::NON_DESTRUCTIVE)==EMPTY_ELEM) return false;	//empty cliqe
		while(true){
			int v=bb.next_bit();
			if (v==EMPTY_ELEM) break;

			//check neighborhood						
			AND(g.get_neighbors(v), bb, neighbor);
			neighbor.set_bit(v);
			if(!(bb==neighbor)) 
					return false; 
		}
		return true;
	}
	
	template<class Graph_t> 
	bool is_clique(Graph_t& g, vint& lv){
	/////////////////
	// TRUE if subgraph bb is a clique
	// 
	// COMMENTS:
	//  I. implemented with unrolling for early condition detection
	//  II. the bad part is the initial construction of a bitstring from lv
	//	/* Not optimized for all graph types */

		if(lv.empty()) return false;
		else if(lv.size()==1) return true;
		typename Graph_t::bb_type ref(lv, g.number_of_vertices());

		for(vint::iterator it=lv.begin(); it!=lv.end(); it++){
			int v=*it;
			typename Graph_t::bb_type& neigh=g.get_neighbors(v);			
			ref.erase_bit(v);												//to compare only neighbors of v
			
			//check neighborhood-unroll
			for(int nBB=0; nBB<neigh.number_of_bitblocks(); nBB++){
				BITBOARD aux=ref.get_bitboard(nBB)& neigh.get_bitboard(nBB);
				if(aux!=ref.get_bitboard(nBB))
					return false;
			}

			ref.set_bit(v);													//resets context

			//without unrolling
			/*AND(g.get_neighbors(v), bb, neighbor);
			neighbor.set_bit(v);
			if(!(bb==neighbor)) 
			return false; */

		}

		return true;
	}

	template<class Graph_t> 
	bool is_clique(Graph_t& g, int* lv, int size){
	/////////////////
	// TRUE if subgraph bb is a clique (C-ARRAY INTERFACE)
	// 
	// COMMENTS:
	//  I. implemented with unrolling for early condition detection
	//  II. the bad part is the initial construction of a bitstring from lv
	//	/* Not optimized for all graph types */

		if(size<=0) return false;
		else if(size==1) return true;
		typename Graph_t::bb_type ref(g.number_of_vertices());
		for(int i=0; i<size; i++){
			ref.set_bit(lv[i]);
		}
	
		for(int i=0; i<size; i++){
			int v=lv[i];
			typename Graph_t::bb_type& neigh=g.get_neighbors(v);			
			ref.erase_bit(v);												//to compare only neighbors of v
			
			//check neighborhood-unroll
			for(int nBB=0; nBB<neigh.number_of_bitblocks(); nBB++){
				BITBOARD aux=ref.get_bitboard(nBB)& neigh.get_bitboard(nBB);
				if(aux!=ref.get_bitboard(nBB))
					return false;
			}

			ref.set_bit(v);													//resets context

			//without unrolling
			/*AND(g.get_neighbors(v), bb, neighbor);
			neighbor.set_bit(v);
			if(!(bb==neighbor)) 
			return false; */

		}

		return true;
	}
	
}

#endif