#include "Graph.h"
#include <iostream>

using namespace std;

int main()
{
    AirlineGraph airlines;
    string fileName;
    char stillRunning = 'y';
    int from, to;
    
    cout << "Enter name of network file: ";
    cin >> fileName;
    
    if(!airlines.getAirlines(fileName))
        return 1;
    
    cout << "The Digraph's Adjacency-List Representation: " << endl;
    airlines.printAirlines();
    
    
    while(stillRunning == 'y' || stillRunning == 'Y')
    {
        cout << endl << "Number of start city? ";
        cin >> from;
        cout << "Number of destination? ";
        cin >> to;
        airlines.shortestPath(from, to);
        
        cout << endl << "More (Y or N)? ";
        cin >> stillRunning;
    }
    
    return 0;
}
