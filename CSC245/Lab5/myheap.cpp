#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main() { 

      BinaryHeap<char> PQ(50);
      
      for(char ch = 'A'; ch <= 'J'; ch++)
            PQ.insert(ch);
      
      PQ.deleteMin();
      cout << "Printing Left Subtree of the Root of Heap : "; PQ.printLtSubtree(); cout << endl;
      
      cout << "Height of Heap is : " << PQ.Height() << endl;
      
      cout << "Maximum Value of the Heap is : " << PQ.findMax() << endl;
      
     // cout << "The Leaves of the Heap are : " << PQ.printLeaves() << endl;
     
                        
      return 0;
      
}
