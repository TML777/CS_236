#include "WeightedGraph.hpp"
#include <iostream>

using namespace std;

void merge(int[], int, int);


//EdgeList constructer
EdgeList::EdgeList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

//EdgeList destructer
EdgeList::~EdgeList()
{
    clearList(head);
    head = nullptr;
    tail = nullptr;
    length = 0;
}

//ands new node to list
void EdgeList::addToList(int newWeight, int newFrom, int newTo)
{
    EdgeListNode* temp = new EdgeListNode;
    temp->weight = newWeight;
    temp->from = newFrom;
    temp->to = newTo;
    if(head!= nullptr)
    {
        temp->previous = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        head = temp;
        tail = temp;
    }
    length++;
}

//clears the list
void EdgeList::clearList(EdgeListNode* current)
{
    if(current != nullptr)
    {
        clearList(current->next);
        delete current;
    }
}

//returns length of the list
int EdgeList::getLength() const
{
    return length;
}

//returns the edge with the minium wheight and removes it from the list
EdgeListNode* EdgeList::getMinWeightEdge()
{
    if(head == nullptr)
        return nullptr;
    else
    {
        EdgeListNode* current = head->next, *found = head;
        
        while(current != nullptr)
        {
            if(found->weight>current->weight)
            {
                found = current;
            }
            current = current->next;
        }
        
        if(found != head)
            found->previous->next = found->next;
        else
            head = found->next;
        if(found!= tail)
            found->next->previous = found->previous;
        else
            tail = tail->previous;
        
        length--;
        found->next = nullptr;
        found->previous = nullptr;
        return found;
    }
}

//removes the first edge from the list
EdgeListNode* EdgeList::pop()
{
    if(head == nullptr)
        return head;
    
    EdgeListNode* temp = head;
    
    head = head->next;
    temp->next = nullptr;
    
    if(head == nullptr)
        tail = nullptr;
    else
        head->previous = nullptr;

    length--;
    
    return temp;
}





//ands new edge to the matrix
void Graph::newEdge(int weight, int from, int to)
{
    edgeMatrix[from-1][to-1] = weight;
    edgeMatrix[to-1][from-1] = weight;
}

//returns an EdgeList containing of all edges
EdgeList Graph::getAllEdges() const
{
    EdgeList list;
    
    for(int i = 0; i<NUM_OF_VERTECIES; i++)
    {
        for(int j = i; j<NUM_OF_VERTECIES; j++)
        {
            if(edgeMatrix[i][j] != 0)
                list.addToList(edgeMatrix[i][j], i, j);
        }
    }
    return list;
}

//retursn an EdgeList containing the edges for a minimum spanning tree
EdgeList Graph::minSpanningTree()
{
    EdgeList allEdges = this->getAllEdges();
    EdgeList minTree;
    EdgeListNode *nextNode;
    int vertexArray[NUM_OF_VERTECIES];
    int fromVertex, toVertex, length;
    
    for(int i = 0; i<NUM_OF_VERTECIES; i++)
        vertexArray[i] = i;
    length = NUM_OF_VERTECIES;
    
    while(length>1 && allEdges.getLength()> 0)
    {
        nextNode = allEdges.getMinWeightEdge();
        fromVertex = nextNode->from;
        toVertex = nextNode->to;
        
        if(vertexArray[fromVertex] != vertexArray[toVertex])
        {
            minTree.addToList(nextNode->weight, nextNode->from, nextNode->to);
            merge(vertexArray, fromVertex, toVertex);
            length--;
        }
        
        
        delete nextNode;
    }
    
    return minTree;
}

//prints the minimum spanning tree
void Graph::printMinSpanTree()
{
    EdgeList tree = minSpanningTree();
    EdgeListNode* current;
    int totalWeight = 0;
    
    cout << "Finding MST using Kruskal's Algorithm" << endl
        << "Edges of MST are:" << endl;
    
    while(tree.getLength()>0)
    {
        current = tree.pop();
        cout << current->from+1 << " - " << current->to+1 << " = " << current->weight << endl;
       
        totalWeight += current->weight;
        
        delete current;
    }
    
    cout << endl << "Weight of MST is " << totalWeight << endl;

}


//sets all the the numbers in vertexArray that equal vertexArray[toVertex] to vertexArray[vertexArray]
void merge(int vertexArray[NUM_OF_VERTECIES], int fromVertex, int toVertex)
{
    int temp = vertexArray[toVertex];
    for(int i = 0; i< NUM_OF_VERTECIES; i++)
        if(vertexArray[i] == temp)
            vertexArray[i] = vertexArray[fromVertex];
}
