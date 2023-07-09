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

void addWord(char *argv[], string word);

int main(int argc, char *argv[]) { 

      ifstream infile(argv[1]);
      ofstream outfile(argv[1], ios_base::app);
      
      outfile << "i added this" << endl;
      
      outfile.close();
      

      return 0;
      
}

void addWord(char *argv[], string word) { 

      ofstream outfile(argv[1], ios_base::app);
      outfile << word << endl;
      outfile.close();
      
}

