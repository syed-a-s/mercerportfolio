#include <iostream>
#include <queue>
using namespace std;

void insert(priority_queue<string> &pq);
void print(priority_queue<string> pq);
string NAMES[] = {"Bob", "James", "Maddie", "Ryan", "Alex", "Dylan", "Maria", "Johan", "Max", "Jordan"};

int main() { 

      priority_queue<string> pq;

      print(pq);
      
      return 0;

}

void insert(priority_queue<string> &pq) { 
      
      pq.push(NAMES[0]);
      pq.push(NAMES[1]);
      pq.push(NAMES[2]);
      pq.push(NAMES[3]);
      pq.push(NAMES[4]);
      pq.push(NAMES[5]);
      pq.push(NAMES[6]);
      pq.push(NAMES[7]);
      pq.push(NAMES[8]);
      pq.push(NAMES[9]);

}

void print(priority_queue<string> pq) { 

      priority_queue<string> temp = pq;
      while(!temp.empty()) { 
          cout << temp.top() << " ";
          temp.pop();
      }
      cout << endl;
      
}