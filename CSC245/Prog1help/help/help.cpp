#include <iostream>
#include <string>
#include "linelist.h"
using namespace std;

int main() {

      LineList list;
      string newLine;
      list.insertLine("test");
      list.insertLine("test2");
      list.insertLine("test3");
      getline(cin, newLine);
      list.insertLine(newLine);
      list.printList();
      
      return 0;

}
