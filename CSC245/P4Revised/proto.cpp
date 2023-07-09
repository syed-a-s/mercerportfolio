#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;
#include "graph.h"
#include "HashTable.h"

void clrs();
void BuildGraph(Graph<string> &Flights, char *argv[], HashTable<string> &Cities, int &numCities);
void Menu(Graph<string> &Flights, HashTable<string> &Cities, int &numCities);
void PreOrder(Graph<string> &Flights);
void Dijkstra(Graph<string> &Flights);
bool checkCycle(Graph<string> &Flights);
void printCycle(Graph<string> &Flights);

const string notFound = "ZZZ";
      
int main(int argc, char *argv[]) {

      if(argc > 1) { 
            
            Graph<string> Flights; int numCities;
            Queue<string> FlightsQ;
            HashTable<string> Cities(notFound, 50);
            
            BuildGraph(Flights, argv, Cities, numCities);
            Menu(Flights, Cities, numCities);

      } else { 
              cout << "\tNo Filename given -- Program Exiting" << endl;
              exit(1);
      }
      
}

//Clear screen
void clrs() { 
      cout << "\033[2J\033[1;1H";
}

// Pre : An empty graph
// Post : A graph that is built from the  file from the command line. 
//        The num of Cities is also counted
void BuildGraph(Graph<string> &Flights, char *argv[], HashTable<string> &Cities, int &numVertices) {

      ifstream infile;
      infile.open(argv[1]);
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

/////////////////////// THE PROGRAM ///////////////////////

void Menu(Graph<string> &Flights, HashTable<string> &Cities, int &numCities) { 
      
      clrs();
      cout << "\t\t^^^^^^^^^^^^^^^^ DIJKSTRA'S ALGORITHM ^^^^^^^^^^^^^^^^\n" << endl; 
      cout << "\t\tA Weighted Graph has been built for these " << numCities << " Cities : \n" << endl;
      
      //////////////////////
      PreOrder
      //////////////////////
      
      bool check = true; string startVertex; 
      while(check) { 
      
            cout << "\t\tPlease enter your starting vetex : ";
            cin >> startVertex; cin.ignore(); cout << endl;
            
            if(Cities.find(startVertex) == startVertex) { 
                  check = false;
            } else { 
                  cout << "Vertex not found - Try again" << endl;
            }

      }
      
      cout << "\t\t------------------------------------------------------------------" << endl;
      
      cout << "\t\t\tVertex\t\tDistance\t\tPrevious\n" << endl;
      
      //////////////////////////////
      
      /////////////////////////////
      
      cout << "\t\t------------------------------------------------------------------" << endl;
      


}

////////////////////////// END ////////////////////////////

/*// The functions of the program

// Post : Print the Cities in the graph in Preorder
void PreOrder(Graph<string> &Flights){

}

//Post : Prints the summary table for the greedy algorihm 
void Dijkstra(Graph<string> &Flights){

}

//Post : Returns true or false depending whether the graph has a cycle or not
bool checkCycle(Graph<string> &Flights) {

}

// Post : Print cycles if there are any
void printCycle(Graph<string> &Flights) { 

      if(checkCycle) { 
            cout << "\t\t\t\t\tThe graph contains a cycle" << endl;
            cout << "\t\t\tThe Cycle is : " << endl;
            cout << "\t\t\tVertex
      
}*/




