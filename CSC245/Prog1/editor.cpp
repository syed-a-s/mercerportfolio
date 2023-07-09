
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "linelist.h"

void saveLines(char *argv[], LineList &l);

int main(int argc, char *argvp[]) { 

    // Checks if user put file name
    if (argc > 1) { 
          
          // All variables for program
          ifstream infile(argvp[1]); 
          LineList list;                                            
          char choice; string newLine;
                      
          // Reads file and puts string into the line editor 
          while(getline(infile, newLine)) {
                list.insertLine(newLine);
          }
         
          // The Line Editor 
          list.printList();
                      
          while (choice != 'E') { 

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
                            saveLines(argvp, list);
                            infile.close(); 
                            break;
                      default :
                            break;
                    
                }
          }
    
    // Error message if user did not put a file name          
    } else { 
          cout << "Please run with a text file." << endl;
          exit(1);
    }
    
}

void saveLines(char *argv[], LineList &l) { 

      ofstream outfile;
      string filename = argv[1];
      
      outfile.open(filename.c_str());
      l.goToTop();
      
      for (int i = 1; i <= l.getLength(); i++) { 
            outfile << l.getCurrLine() << endl;
            l.moveNextLine();
      }
      
      outfile.close();
      
}






