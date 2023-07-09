#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;
#include <vector>
#include <queue>
#include "Sort.h"

int maxElemLength(const vector<int> &v);
int GetDigit(int number, int k);
vector<queue<int> > ItemsToQueues(const vector<int> &L, int k);
vector<int> QueuesToArray(vector<queue<int> > &QA, int numVals);
void RadixSort(vector<int> &L, int numDigits);

int main() {

      vector<int> a;
      a.push_back(1);
      a.push_back(41);
      a.push_back(124);
      cout << maxElemLength(a) << endl;
      
      return 0;
      
}

int maxElemLength(const vector<int> &v) {

      int max = *max_element(v.begin(), v.end());
      int digits = 0;
      while(max != 0) { 
            max /= 10;
            digits++;        
      }
      
      return digits;
      
}

