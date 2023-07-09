
#include <iostream>                    
#include "linelist.h"

int main() {

    LineList list;
    
    list.insertLine("test");
    list.insertLine("test2");
    list.insertLine("test3");
    list.printList();
    list.moveNextLine();
    list.deleteLine();
    cout << endl;
    list.printList();
    
    return 0;
    
}

 