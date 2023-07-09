#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include "stack.h"
using namespace std;

void PrintStack(Stack<string> &s);

int main() { 
     
      Stack<string> s;
      s.push("1"); s.push("1"); s.push("1"); s.push("1"); s.push("1");
      PrintStack(s);
      s.makeEmpty();
      PrintStack(s);

}

void PrintStack(Stack<string> &s)
{
    // If stack is empty
    if (s.isEmpty())
        return;
 
// Extract top of the stack
    string x = s.top();
 
    // Pop the top element
    s.pop();
 
    // Print the current top
    // of the stack i.e., x
    cout << x << endl;
 
    // Proceed to print
// remaining stack
    PrintStack(s);
 
    // Push the element back
    s.push(x);
}