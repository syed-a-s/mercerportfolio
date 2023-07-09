#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream> 
using namespace std;
#include "HashTable.h"
#include "BinarySearchTree.h"

void clrs();

// The setup
void dict(HashTable &D);
string openFile(char *argv[]);
void menu(string word, int lineNum);

//The various actions
void addWord(char *argv[], string newWord);
void ignoreWord();
void go();
void suggest(string word); //might be better as value returning 

// Add the not found word into a text file
void notFound();

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
            dict(D);
      
            ////////////////////////////
      
            // Open the file from the command line
            string fileText;
            fileText = openFile(argv);
      
            ////////////////////////////
            
            // The Spellchecker
            string word; int lineNum = 1; char choice;
            stringstream ss(fileText);
            while(ss >> word) {
                  
                  clrs();

                  if(D.find(word)) {
                        //Do nothing 
                  } else { 
                        
                        menu(word, lineNum);
                        cin >> choice;
                        int check = -1; 
                        while(check == -1) { 
                  
                              switch(choice) { 
            
                                    case 'a':
                                         // addWord()
                                          check = 0;
                                          break;
                                    case 'i':
                                          check = 0;
                                          break;
                                    case 'g':
                                          go(); check = 0;
                                          break;
                                    case 's':
                                          check = 0;
                                          break;
                                    case 'q':
                                          cout << "\n\tExiting the Program...\n" << endl; 
                                          check = 0;
                                          exit(0);
                                          break;
                                    default : 
                                          cout << "\tInvalid Input - Try Again\n" << endl; 
                                          break;
                                                             
                              }
                              cout << "\tSelection : ";
                              cin >> choice;  
                        }
                  }
              }
              
            ////////////////////////////
            
      } else { 
            cout << "\tNo Filename given -- Program Exiting" << endl;
            exit(1);
      }
      
}

// Clear Screen
void clrs() { 
      cout << "\033[2J\033[1;1H";
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

// Pre : The method will take an opened file
// Post : The text from the file will be converted to a string and return it 
string openFile(char *argv[]) { 

      ifstream infile(argv[1]);
      string n, text; 

      while(getline(infile, n)) {
            text = text + " " + n;
      }
      
      infile.close();
      
      return text;
      
}

//-------The actions that can be done-------//

/*void addWord(char *argv[], string newWord); { 

      
}
void ignoreWord();*/
void go() { 
      return;
}
void suggest(string word) {

  string wordN = "";
	for (int i = 0;  i < word.length()-1;  i++)
	{
		wordN += word.substr(0, i);
		wordN += word[i+1];
		wordN += word[i];
		wordN += word.substr(i+2);
		cout << wordN << endl;
		wordN = "";
   }
  
} 

// Post : Append the word to the end of the dictionary
void notFound() { 

      ofstream outfile;
      outfile.open("dict.txt", std::ios_base::app);
      outfile << "saadat" << endl;
      outfile.close();
      
}