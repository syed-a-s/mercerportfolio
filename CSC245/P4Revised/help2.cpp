#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;
#include "graph.h"
#include "stack.h"
#include "HashTable.h"

void BuildGraph(Graph<string> &Flights,HashTable<string> &Cities, int &numCities);;
void DFS(Graph<string> &Flights, Queue<string> &FlightsQ);

const string notFound = "ZZZ";

int main() { 

      Graph<string> Flights; int numVertices;
      Queue<string> FlightsQ;

      HashTable<string> Cities(notFound, 50);
      BuildGraph(Flights, Cities, numVertices);  
      
      string startVertex; bool check = true;
      while(check) { 
      
            cout << "\t\tPlease enter your starting vetex : ";
            cin >> startVertex; cin.ignore(); cout << endl;
            
            if(Cities.find(startVertex) == startVertex) { 
                  check = false;
            } else { 
                  cout << "Vertex not found - Try again" << endl;
            }

      }
          
      return 0;
      
}

void BuildGraph(Graph<string> &Flights, HashTable<string> &Cities, int &numVertices) {

      ifstream infile;
      infile.open("ginfile1.dat");
      string origin, destination, line; int trip_length; 
      
      while(getline(infile, line)) { 
      
            stringstream ss(line);
            getline(ss, origin, ';');
            getline(ss, destination, ';');
            ss >> trip_length;
            
            if((Cities.find(origin) != origin)) 
                  { Flights.AddVertex(origin); Cities.insert(origin); numVertices++;} 
            if((Cities.find(destination) != destination)) 
                  { Flights.AddVertex(destination); Cities.insert(destination); numVertices++;}
                  
            Flights.AddEdge(origin, destination, trip_length);
            
      }   
      
      infile.close();          

}

