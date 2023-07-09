
#include <iostream>
#include <string>
#include <fstream>
#include "linelist.h"

int main() { 

    LineList list;
    list.insertLine("test");
    list.insertLine("test2");
    list.insertLine("test3");
    list.printList();
    char choice;
    bool check = true;
    string newLine;
    string line;
          
    while (check) { 

          cout << list.getCurrLineNum() << "> ";
          std::cin >> choice;
                       
          switch(choice) { 

                case 'I':
                    cout << list.getCurrLineNum() << "> ";
                    cin.ignore();
                    getline (cin, newLine);
                    list.insertLine(newLine); 
                    break;
                case 'D':
                    list.deleteLine();
                    break;
                case 'L':
                    list.printList();
                    break;
                case 'P':
                    list.movePrevLine();
                    break;
                case 'N':
                    list.moveNextLine();
                    break;
                case 'E':
                    check = false; 
                    break;
                default :
                    choice = ' '; break;
                    
          } 
          
    } 
    
    return 0;
    
}