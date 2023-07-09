#include <iostream>
#include <fstream>
using namespace std;

int main() { 

      char letter;
      ifstream infile;
      ofstream outfile;
      infile.open("help.dat");
      outfile.open("newFile.dat");
      
      infile.get(letter);
      while(infile) { 
            while(letter != '\n') {
                  cout << letter;
                  outfile << letter;
                  infile.get(letter);
            }
            infile.get(letter);
            outfile << endl;
            cout << endl;
      }
        
      infile.close();
      outfile.close();
      return 0;
}





