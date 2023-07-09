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
      
      int pos = 0;
      string input, slice;  
      Stack<string> postfix;
      
      try {      
                
            // While there is user input
            while(getline(cin, input)) { 

                  for(pos; pos < input.length(); pos++) {
                        // Process the digits and push onto stack
                        if(isdigit(input[pos])) { 
            
                             /* while(isdigit(input[pos])) { 
                                    slice += input[pos];
                                    pos++;
                              }*/
                              slice += input[pos];
                              postfix.push(slice);    
                        } 
                        slice = "";
            
                        // Process the commands
                        if(isalpha(input[pos])) 
                              isCommand(char(input[pos]), postfix);
            
                        // Process the operators      
                        if(isoper(input[pos]))
                              isOperator(char(input[pos]), postfix);                  
    
                  }  
                  pos = 0;
            }       

      } catch (Underflow obj) { 
            cout << "Exception -- You're Trying to Pop an An Empty Stack!" << endl;
      } catch (Overflow obj) { 
            cout << "Exception -- Your Stack is Full!" << endl;
      } catch (BadIterator obj) { 
            cout << "Exception -- Invalid Operator!" << endl;
      }  
       
      return 0;
      
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
      int first, second, ans; // second operator top = answer 
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
            return false; throw (BadIterator());
}

void PrintStack(Stack<string> &s) {

    if (s.isEmpty())
        return;
    string str = s.top();
    s.pop();
    cout << str << endl;
    PrintStack(s);
    s.push(str);
    
}
