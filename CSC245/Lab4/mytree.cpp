#include <iostream>
#include <string>
#include "bst.h"
using namespace std;

int main() {

      BinarySearchTree<int> T(0); 
      
      T.insert(6);
      T.insert(2);
      T.insert(8);
      T.insert(1);
      T.insert(4);
      T.insert(3);
      
      T.postOrder();
      cout << endl;
      
      cout << T.height() << endl;
      cout << endl;
      
      cout << "Balanced?" << " -> " << T.isBalanced() << endl;
      
      T.insert(9);
      
      cout << "Balanced?" << " -> " << T.isBalanced() << endl;
      
     // cout << true << endl;
      
}