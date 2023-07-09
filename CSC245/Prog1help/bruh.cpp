#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include "linelist.h"
using namespace std;

int main() {

       ifstream infile("testfile");
       bool a = infile;
       cout << a << endl;
       infile.close();
          
}