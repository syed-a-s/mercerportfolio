#include <iostream>
#include <string>
using namespace std;

int main() { 

	/*int* ptr = new int;         
  int var = 3;      
  ptr = &var; 
  int &ref = var;
  
  var++;            // everything should be 4 now
  
  cout << "Ref is " << ref << endl;
  cout << "var is " << var << endl;
  cout << "Value in ptr is " << *ptr << endl;
  cout << "Address of ptr " << ptr << endl;
  cout << "Address of ref " << &ref << endl;
  cout << "Address of var " << &var << endl;*/
  
  struct LineNode { 
    string info;
    LineNode *next;
    LineNode *back;
  };
  
  LineNode *line = new LineNode;
  LineNode *line2 = new LineNode;
  
  line->info = "top";
  line2->info = "bottom";
  
  line->next = line2;
  line->back = NULL;
  line2->next = NULL;
  line2->back = line;
  
  cout << line->info << endl;
  cout << line->next->info << endl;
  
  LineNode *line3 = new LineNode;
  line3 = line;
  
  while (line3 != NULL)
      { 
          cout << line3->info << endl;
          line3 = line3->next;
      }

}


