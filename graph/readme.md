
GRAPH library for bit-encoded graphs
===================

GRAPH is a currenty a  small  C++ library which uses a bitwise encoding of graphs. At the heart of GRAPH is BITSCAN, an efficient library to manage bit strings. 

The library has been tested in Windows and Linux.  It is distributed under the conditions in *legal.txt*

BUILDING GRAPHS
-------------------------------
GRAPH currently distinguishes 4 different types of graph objects:

- `graph`: for simple graphs
- `ugraph`: specialization of `graph` for undirected graphs
- `sparse_graph`: for sparse simple graphs
- `sparse_ugraph`: specialization of `sparse_graph` for sparse undirected graphs
 
To build a graph from scratch an empty graph the cardinality is passed to the constructor. Here is a simple example:

    #include "<path>/graph/graph.h"
    //...
    
    graph g(3);						//creates an empty simple graph with 100 vertices
    g.add_edge(0,1);				//configures the edges
	g.add_edge(0,2);
	g.add_edge(1,2);


Notice that Graph always adds directed edges, so this is not actually a 3-clique. If a 3-clique is what you need you should call the *make\_bidirected* function.
   
    g.make_bidirected()				//creates a 3-clique

A better option would have been to use the class Ugraph from the beginning to build the clique:
   
    ugraph g(3);					//creates an empty simple graph with 100 vertices
	g.add_edge(0,1);				//configures edges (symmetrical)
	g.add_edge(0,2);
	g.add_edge(1,2);

EDITING GRAPHS
-------------------------------

Edges may be added or deleted in constant time (*remove\_edge* member function) for simple graphs (in the case of sparse graphs complexity increases because it takes logarithmic time to find an edge). Removing vertices is possible as well (member function *remove\_vertices*) but requires memory allocation. Currently GRAPH does not support adding new vertices (the graph order should be passed to the constructor). Here is a trivial example:
   
    graph g(3);						//creates an empty graph with 100 vertices
	g.add_edge(0,1);				//configures the edges
	g.add_edge(0,2);
	g.add_edge(1,2);
	g.remove_edge(0,1);
	g.remove_edge(0,2);
	g.remove_edge(1,2);
    if(g.is_empty()) cout<<"empty graph"<<endl;	 //outputs the message on the screen

    
EXTERNAL SOURCES
-------------------------------

Currently version GRAPH reads simple undirected unweighted graphs in ASCII DIMACS, Matrix Market Exchange and Edge list formats. A few examples of undirected graphs in different formats may be found in tha *data* folder of the block. To load a graph from file simply pass the appropiate filename to the constructor:
    
    graph g("foo-filename");	


COMPATIBILITY
-------------------------------

GRAPH has been tested in Windows 64-bit OS and Linux OS. Please note that a 64-bit OS is mandatory becase of the BITSCAN dependency.

Acknowledgements
-------------------------------

This research has been partially funded by the Spanish Ministry of Economy and Competitiveness (MINECO),  grants DPI 2010-21247-C02-01 and DPI 2014-53525-C3-1-R.

