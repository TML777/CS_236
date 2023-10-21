#include "WeightedGraph.hpp"


int main()
{
    Graph theGraph;
    
    theGraph.newEdge(6, 1, 2);
    theGraph.newEdge(5, 1, 6);
    theGraph.newEdge(10, 2, 3);
    theGraph.newEdge(7, 2, 7);
    theGraph.newEdge(8, 2, 6);
    theGraph.newEdge(8, 3, 4);
    theGraph.newEdge(10, 3, 5);
    theGraph.newEdge(5, 3, 7);
    theGraph.newEdge(8, 4, 5);
    theGraph.newEdge(12, 5, 6);
    theGraph.newEdge(7, 5, 7);
    theGraph.newEdge(7, 6, 7);
    
    theGraph.printMinSpanTree();
    
    
    return 0;
}
