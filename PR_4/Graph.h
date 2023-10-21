#ifndef Graph_h
#define Graph_h

#include <string>

using namespace std;

const int NUM_OF_AIRLINES = 8;                  /// Number of airlines, if another city added only number that needs to change is this

//a stack node with integer and pointer to next node
struct Node
{
    int location;
    Node* next = nullptr;
};

//Node stack used for both ques and stacks
class NodeStack
{
private:
    Node* head;
    Node* end;
public:
    NodeStack();
    ~NodeStack();
    void push(int);
    void addToEnd(int);
    int pop();
};

//actual airline graph
class AirlineGraph
{
private:
    bool adjMatrix [NUM_OF_AIRLINES][NUM_OF_AIRLINES] {0};
    string names[NUM_OF_AIRLINES];
public:
    bool getAirlines(string);
    void printAirlines();
    void shortestPath(int,int);
    void printStack(NodeStack*);
};

#endif
