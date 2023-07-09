#include <iostream>
#include <cmath>
#include "BinaryHeap.h"
using namespace std;

int help(int array[], int size);
void printArray(int array[], int s);

int main() { 
      
      BinaryHeap<char> PQ(50);
      
      for(char ch = 'A'; ch <= 'J'; ch++)
            PQ.insert(ch);
      
      PQ.printArray();
      PQ.deleteMin();
      PQ.deleteMin();
      PQ.deleteMin();
      PQ.printArray();
      
      BinaryHeap<int> ok(50);
      
      ok.insert(10);
      ok.insert(12); 
      ok.insert(1); 
      ok.insert(14); 
      ok.insert(6); 
      ok.insert(5); 
      ok.insert(8); 
      ok.insert(15); 
      ok.insert(3); 
      ok.insert(9); 
      ok.insert(7); 
      ok.insert(4); 
      ok.insert(11); 
      ok.insert(13); 
      ok.insert(2); 
      
      ok.printArray();  
      
      BinaryHeap<int> num(50);
      num.insert(42);  
      num.insert(43); 
      num.insert(23); 
      num.insert(65); 
      num.insert(53); 
      num.insert(79); 
      num.insert(72); 
      num.insert(34); 
      num.printArray();
           
      return 0; 
}

int help(int array[], int size) { 
         int loc = 0;
         int maxLoc = loc; int max;
         while (loc <= size) { 
         
               if (array[maxLoc] > array[loc]) 
                     return array[maxLoc];
                     
               if (array[maxLoc] < array[loc])  
                     return array[loc];
                     
               loc++; 
                      
         } 
         
}

void printArray(int array[], int size) { 

      for(int i = 0; i <= size; i++)
            cout << array[i] << " ";
      cout << endl;
}