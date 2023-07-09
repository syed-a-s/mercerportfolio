#include <iostream>
#include <fstream>
using namespace std;
#include "BinarySearchTree.h"

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


int main() { 

      BNode nf = {"ZZZ", -1};
      BinarySearchTree<BNode> bt(nf);
      
      //When word not found
      string word = "ZZZ"; int line_found = 1;
      BNode bN = {word, line_found};
      
      BNode result = bt.find(bN);
      
      if(result.word == "ZZZ")
            bt.insert(bN);
            
      ofstream outfile ("notfound.txt");
      bt.printTree(outfile);
      
      return 0;
      
} 