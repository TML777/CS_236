#ifndef WeightedGraph_hpp
#define WeightedGraph_hpp


const int NUM_OF_VERTECIES = 7;              /// Number of variables, if another variable added only number that needs to change is this


//and edge node for a list
struct EdgeListNode
{
    int weight, from, to;
    EdgeListNode* next = nullptr, *previous = nullptr;
};

//list of edges
class EdgeList
{
private:
    EdgeListNode* head, *tail;
    int length;
public:
    EdgeList();
    ~EdgeList();
    void addToList(int, int, int);
    void clearList(EdgeListNode*);
    int getLength()const;
    EdgeListNode* getMinWeightEdge();
    EdgeListNode* pop();
};

//graph with and matrix for edges
class Graph
{
private:
    int edgeMatrix [NUM_OF_VERTECIES][NUM_OF_VERTECIES] {0};
public:
    void newEdge(int, int, int);
    EdgeList getAllEdges() const;
    EdgeList minSpanningTree();
    void printMinSpanTree();
};


#endif
