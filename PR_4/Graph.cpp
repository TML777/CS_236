#include "Graph.h"
#include <iostream>
#include <fstream>

//NodeStack constructer
NodeStack::NodeStack()
{
    head = nullptr;
    end = nullptr;
}

//NodeStack destructer
NodeStack::~NodeStack()
{
    int number = 0;
    while(number != -1)
    {
        number = pop();
    }
}

//adds new node to the front
void NodeStack::push(int number)
{
    Node* temp = new Node;
    temp->location = number;
    temp->next = head;
    head = temp;
    
    if (end == nullptr)
        end = head;
}

// adds new node to the end
void NodeStack::addToEnd(int number)
{
    Node* temp = new Node;
    temp->location = number;
    temp->next = nullptr;
    
    if(end != nullptr)
        end->next = temp;
    else
        head = temp;
        
    
    end = temp;
}

//removes node from the front and returns value
int NodeStack::pop()
{
    if(head == nullptr)
        return -1;
    
    int number = head->location;
    Node* temp = head;
    head = temp->next;
    delete temp;
    
    if (head == nullptr)
        end = nullptr;
    
    return number;
}


//Gets airlines and destinations from file and creates a graph if file opens correctly returns true else returns false
bool AirlineGraph::getAirlines(string fileName)
{
    ifstream fileIn;
    fileIn.open(fileName);
    
    if(!fileIn.is_open())
    {
        cout << "File did not open :( Ending program." <<endl;
        return false;
    }
    
    string tempName;
    int tempNumConnections, tempConection;
    
    for(int i=0; i<NUM_OF_AIRLINES; i++)
    {
        fileIn >> tempName;
        names[i] = tempName;
        
        fileIn >> tempNumConnections;
        for(int j = 0; j < tempNumConnections; j++)
        {
            fileIn >> tempConection;
            adjMatrix[i][tempConection-1] = true;
        }
    }
    
    fileIn.close();
    
    return true;
}

//prints all airlines and their destinations
void AirlineGraph::printAirlines()
{
    for(int i=0; i<NUM_OF_AIRLINES; i++)
    {
        cout << i+1 << ": " << names[i] << "--";
        for(int j = 0; j < NUM_OF_AIRLINES; j++)
        {
            if(adjMatrix[i][j])
                cout << j+1 << ' ';
        }
        cout << endl;
    }
}

//finds shortest path from one place to another and prints it
void AirlineGraph::shortestPath(int from, int to)
{
    from--;
    to--;
    
    bool found = false, visited[NUM_OF_AIRLINES]{0};
    NodeStack printer, frontier;
    int level = 1, current = from, counter = 1, nextLevelCounter = 0, leveledGraph[NUM_OF_AIRLINES][NUM_OF_AIRLINES]{0};
    
    
    if(from == to)
    {
        printer.push(from);
        found = true;
    }
    else
    {
        leveledGraph[0][current] = true;
        visited[current] = true;
        
        while(!found && current != -1)
        {
            if(current == to)
                found = true;
            else if (counter == 0)
            {
                level++;
                counter = nextLevelCounter;
                nextLevelCounter = 0;
            }
            else
            {
                for(int i =0; i<NUM_OF_AIRLINES; i++)
                {
                    
                    if(!visited[i] && adjMatrix[current][i])
                    {
                        frontier.addToEnd(i);
                        leveledGraph[level][i] = true;
                        visited[i] = true;
                        if(i == to)
                            found = true;
                        nextLevelCounter++;
                    }
                }
                current = frontier.pop();
                counter--;
            }
        }
        
        if(found)
        {
            printer.push(to);
            level--;
            current = to;
            
            while (level>=0)
            {
                if (level == 0)
                {
                    printer.push(from);
                    level--;
                }
                else
                {
                    for(int j = 0; j<NUM_OF_AIRLINES; j++)
                    {
                        if (leveledGraph[level][j] && adjMatrix[j][current])
                        {
                            printer.push(j);
                            current = j;
                            j=NUM_OF_AIRLINES;
                            level--;
                        }
                    }
                }
            }
        }
    }
    
    
    
    if(found)
    {
        printStack(&printer);
        cout << to+1 << ' ' << names[to] << endl;
    }
    else
        cout << "No path exists." << endl;
}

//prints a stack of NodeStack
void AirlineGraph::printStack(NodeStack* shortestPath)
{
    int current = shortestPath->pop();
    while(current != -1)
    {
        cout << current+1 << ' ' << names[current] << "\n|\nv" << endl;
        current = shortestPath->pop();
    }
}
