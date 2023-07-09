
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
          char choice; string newLine; bool check = true;
          
          // Try to read the lines in the file
         /* try { 
                
                if (!infile) { 
                    throw 1;
                } else { */
                      
                      // Reads file and puts string into the line editor 
                      while(getline(infile, newLine)) {
                          list.insertLine(newLine);
                      }
                      
                      // The Line Editor 
                      list.printList();
                      
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
                                      saveLines(argvp, list);
                                      infile.close(); 
                                      break;
                                  default :
                                      choice = ' '; break;
                    
                            }
                      }
                  /*}
                  
          }
          catch (int e) { 
                cout << "No text in file" << endl;
                infile.close();
                exit(e);  
          }*/
    
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






