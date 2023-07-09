#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "stack.h"
using namespace std;

void PrintStack(Stack<string> &s);
void isCommand(char cmd, Stack<string> &s);
void isOperator(char op, Stack<string> &s);
bool isoper(char check);

int main() { 
      
      string input, slice; int test = 0;
      Stack<string> s;      
      getline(cin, input);
     
      try {  
      for(test; test < input.length(); test++) { 
            
            // Process the digits and push onto stack
            if(isdigit(input[test]) || input[test] == '_') { 
            
                  while(isdigit(input[test]) || input[test] == '_') { 
                        slice += input[test];
                        test++;
                  }
                  s.push(slice);    
            }
            slice = "";
            
            // Process the commands
            if(isalpha(input[test])) 
                  isCommand(char(input[test]), s);
            
            // Process the operators      
            if(isoper(input[test]))
                  isOperator(char(input[test]), s);
            
      }
      } catch (BadIterator obj) { 
            cout << "Exception -- Invalid Operator!" << endl;
      }  
     
}

void isCommand(char cmd, Stack<string> &s) { 

      int first, second;
      string swapA, swapB, dupe;
      try { 
            switch(tolower(cmd)) { 
      
                  case 'p' :
                        cout << s.top() << endl;
                        break;
                  case 'n' :
                        cout << s.topAndPop();
                        break;
                  case 'f' :
                        PrintStack(s);
                        break;
                  case 'c' :
                        s.makeEmpty();
                  case 'd' :
                        dupe = s.top();
                        s.push(dupe);
                        break;
                  case 'r' :
                        swapB = s.topAndPop();
                        swapA = s.topAndPop();
                        s.push(swapB);
                        s.push(swapA);
                        break;
                  default  :
                        throw DataError();
            
            }
      } catch (DataError obj) { 
            cout << "Exception -- Command not understood!" << endl;
      }        
}

void isOperator(char op, Stack<string> &s) { 

      string answer;
      int first, second, ans; // second operator top = answers 
      stringstream ss;

      try { 
            switch(op) { 
      
                  case '+' :
                       first = atoi((s.topAndPop()).c_str());
                       second = atoi((s.topAndPop()).c_str());
                       ans = second + first;
                       ss << ans;
                       ss >> answer;
                       s.push(answer);
                       break;
                  case '-' :
                       first = atoi((s.topAndPop()).c_str());
                       second = atoi((s.topAndPop()).c_str());
                       ans = second - first;
                       ss << ans;
                       ss >> answer;
                       s.push(answer);
                       break;
                  case '*' :
                       first = atoi((s.topAndPop()).c_str());
                       second = atoi((s.topAndPop()).c_str());
                       ans = second * first;
                       ss << ans;
                       ss >> answer;
                       s.push(answer);
                       break;            
                  case '/' :
                       first = atoi((s.topAndPop()).c_str());
                       second = atoi((s.topAndPop()).c_str());
                       if (first == 0)
                             throw DivisionByZero();
                       else { 
                           ans = second / first;
                           ss << ans;
                           ss >> answer;
                           s.push(answer);
                       }
                       break;           
                  case '%' :
                       first = atoi((s.topAndPop()).c_str());
                       second = atoi((s.topAndPop()).c_str());
                       ans = second % first;
                       ss << ans;
                       ss >> answer;
                       s.push(answer);
                       break;                 
                       
            }
      } catch (DivisionByZero obj) { 
            cout << "Exception -- Cannot Divide by Zero!" << endl;
      } 
} 

bool isoper(char check) { 

      if(check == '+')
            return true;
      else if(check == '-')
            return true;
      else if(check == '*')
            return true;
      else if(check == '/')
            return true;
      else if(check == '%')
            return true;
      else   
            return false; 
            throw (BadIterator());
}

void PrintStack(Stack<string> &s) {

    if (s.isEmpty())
        return;
    string x = s.top();
    s.pop();
    cout << x << ' ';
    PrintStack(s);
    s.push(x);
    
}



