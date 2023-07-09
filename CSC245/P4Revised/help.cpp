#include <algorithm>
#include <vector> 
using namespace std;
#include "HashTable.h"
#include "graph.h"
bool allTrue(bool mark[], int numCities);
int main() { 
       
  bool mark[4];
  for(int i = 0; i < 4; i++)
        mark[i] = true; 
  cout << allTrue(mark, 4) << endl;

	return 0;

}

bool allTrue(bool mark[], int numCities) { 

      for(int i = 0; i < numCities; i++) { 
            if(!mark[i]) { 
                  return false;
            }
      }
      
      return true;
      
}


