#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream> 
#include <algorithm>
using namespace std;
#include "HashTable.h"
#include "BinarySearchTree.h"

// Clear Screen
void clrs();

// The setup
void junk(string &word);
void dict(HashTable &D);
void menu(string word, int lineNum); 

// Some of the actions
void addWord(string newWord, HashTable &D);
string suggest(string word, HashTable &D); 

// Node used to store word and its corresponding line number
struct BNode {
      string word;
      int lineNum;
      bool operator < (BNode otherStruct) const {
            return ( word < otherStruct.word );
      }
};

typedef BinarySearchTree<BNode> BST;
ostream & operator << (ostream & out, BNode & temp) { 
      out << temp.word << " " << temp.lineNum;
      return out;
}

int main(int argc, char *argv[]) { 

      if(argc > 1) {  
            
            clrs();
            // Initialize the dictionary
            HashTable D(500);
            HashTable ignored(50);
            dict(D);

            ////////////////////////////
            
            // BST and BNode 
            BNode nf = {"ZZZ", -1};
            BinarySearchTree<BNode> bt(nf);
      
            // Open the file from the command line
            ifstream infile(argv[1]);

            ////////////////////////////
            
            // The Spellchecker
            string line; int lineNum = 1; char choice;
            
            while(getline(infile, line)) { 
            
                  clrs();
                         
                  stringstream ss(line);
                  string word;
                  
                  while(ss >> word) { 
                  
                        junk(word);
                        transform(word.begin(), word.end(), word.begin(), ::tolower);
                        
                        if(D.find(word) || word == "" || ignored.find(word)) { 
                              // Do Nothing
                        } else { 
                        
                              menu(word, lineNum);
                              
                              // Write this word into notfound.txt
                              BNode bN = {word, lineNum};
                              BNode result = bt.find(bN);
                              
                              if(result.word == "ZZZ")
                                    bt.insert(bN);
                                    
                              ofstream outfile("notfound.txt");
                              bt.printTree(outfile);
                              
                              ////////////////////////////////////
                              
                              cin >> choice;
                              int check = -1; 
                              while(check == -1) { 
                                    string suggested;
                                    switch(choice) { 
            
                                          case 'a':
                                                addWord(word, D);
                                                check = 0;
                                                break;
                                          case 'i':
                                                ignored.insert(word);
                                                check = 0;
                                                break;
                                          case 'g':
                                                check = 0;
                                                break;
                                          case 's':
                                                suggested = suggest(word, D); 
                                                if(suggested == "") { 
                                                      cout << "\n\tNo Suggested Spellings Found in Dictionary\n" << endl;
                                                      cout << "\tWhat would you like to do instead?";
                                                      cin >> choice; 
                                                } else { 
                                                      cout << "\n\tSuggested Spelling : " << suggested << "\n" << endl;
                                                      cout << "\tPlease Hit Return to Continue...";
                                                      cin.ignore(); cin.get(); 
                                                      check = 0;
                                                }
                                                break;
                                          case 'q':
                                                cout << "\n\tExiting the Program...\n" << endl; 
                                                check = 0;
                                                exit(0);
                                                break;
                                          default : 
                                                cout << "\tInvalid Input - Try Again\n" << endl; 
                                                cout << "\tSelection : ";
                                                cin >> choice;
                                                break;
                                                             
                                    }
                              }
                              clrs();  
                          }
                  }
                  lineNum++; 
            }
      } else { 
              cout << "\tNo Filename given -- Program Exiting" << endl;
              exit(1);
      }
      
}

// Clear Screen
void clrs() { 
      cout << "\033[2J\033[1;1H";
}

// Pre : Is a string
// Post : Remove characters not needed for the program
void junk(string &word) { 

      for(int i = 0; i < word.size(); i++) { 
      
          if(ispunct(word[i]) || isdigit(word[i]))  
                word.erase(i--, 1);
       
       }  
      
}

// Post : The HashTable will be filled with words from dict.txt
void dict(HashTable &D) {

      ifstream infile("dict.txt");
      
      string newWord;      
      while(getline(infile, newWord)) {
            D.insert(newWord);
      }
      
      infile.close();
      
}

// Post : Prints menu with the current word and the line number it is in
void menu(string word, int lineNum) { 

      cout << "\t!@#$%^&*(){}  THE SPELL CHECKER PROGRAM  !@#$%^&*(){}\n" << endl;
      cout << "\t" << word << " On Line " << lineNum << " Was Not Found In Dictionary\n" << endl;
      cout << "\ta) Add the Word To Dictionary" << endl;
      cout << "\ti) Ignore Word, and Skip Future References" << endl;
      cout << "\tg) Go on to Next Word" << endl;
      cout << "\ts) Search for a Suggested Spelling" << endl;
      cout << "\tq) Quit Spell Checking File\n" << endl;
      cout << "\tSelection : ";
      
}          

//-------The actions that can be done-------//

// Post : The word will be added into dict.txt. It will also be added to the hashtable 
// used during the span of this program
void addWord(string newWord, HashTable &D) { 
      
      ofstream outfile("dict.txt", ios_base::app);
      outfile << newWord << endl;
      outfile.close();  
      
      D.insert(newWord);
      
}

// Post : Returns a suggested word IF that word is found in the hashtable/dictionary
string suggest(string word, HashTable &D) {

  string wordN = "", suggested;
	for (int i = 0;  i < word.length()-1;  i++)
	{
		wordN += word.substr(0, i);
		wordN += word[i+1];
		wordN += word[i];
		wordN += word.substr(i+2);
    if(D.find(wordN))
        suggested = wordN;
		wordN = "";
   }
  return suggested;
}          
        
