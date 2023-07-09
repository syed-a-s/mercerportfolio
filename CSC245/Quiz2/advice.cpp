#include <fstream>
#include <cctype>
#include <iostream>
using namespace std;

#include <string>
#include "stack.h" 

struct AdviceNode
{
  string QorA;      // a question or an answer
  AdviceNode * yes;   // yes branch
  AdviceNode * no;    // no branch

  AdviceNode(const string & s);  // constructor
};

AdviceNode::AdviceNode(const string & s)
: QorA(s),
  yes(NULL),
  no(NULL)
{}

void ReadTree(istream & in, AdviceNode * & T);

bool IsQuestionNode(AdviceNode * T);
// precondition:  T is not NULL
// postcondition: returns true f T points to a question node;
//                otherwise returns false

void GiveAdvice(AdviceNode * T);
// precondition: T is not NULL

bool TracePath(AdviceNode * T, const string & movie,
               Stack<string> & pathStack);
// precondition:  T is not NULL

void ShowPath(const Stack<string> & pathStack);

int main()
{
  string fname;
  cout << "\nEnter filename of advice knowledge base: ";
  cin  >> fname; cin.ignore();

  ifstream treeIn(fname.c_str());

  AdviceNode * T;
  ReadTree(treeIn, T);

  GiveAdvice(T);

  string movie;
  Stack<string> path;


  while(movie != "q"){
    cout << "\nEnter the name of a movie from tree to see path (q to quit): ";
    getline(cin, movie);
    if(movie != "q"){
      path.makeEmpty();                      // Makes path empty
     // TracePath(T, movie, path);             // Puts the path of searched movie into path
      ShowPath(path);                        // Prints the path
    }
  }


  return 0;
}

void ReadTree(istream & in, AdviceNode * & T)
{
  string QA;

  getline(in, QA);
  T = new AdviceNode(QA);
  if(QA[QA.length()-1] != '?'){
    T->yes = NULL;
    T->no  = NULL;
  }
  else{
    ReadTree(in, T->yes);
    ReadTree(in, T->no);
  }
}

bool IsQuestionNode(AdviceNode * T)
// precondition:  T is not NULL
// postcondition: returns true f T points to a question node;
//                otherwise returns false
{
  return (T->QorA[(T->QorA).length()-1] == '?');
}

void GiveAdvice(AdviceNode * T)
{
// 1)  Check to see if T is a Question Node.
// 2)  If it is, print T -> QorA and Input a 'Y' or 'N' (in any case).
//     If 'Y', recursively go left (T -> yes).  Otherwise, recursively go right.
// 3)  If the node is not a Question Node, it is a leaf and answer node.  So, just print T -> QorA.
  
  char choice;

  if(IsQuestionNode(T)){
	  
      cout << T->QorA << " "; 
 	    cin >> choice; cin.ignore();
	  
	     if (choice == 'Y')
		    //go recursively to the left
           GiveAdvice(T->yes);
	     else
		    //go recursively to the right
           GiveAdvice(T->no);
           
  } else { 
  cout << T->QorA << endl;
  }

}



/* bool TracePath(AdviceNode * T, const string & movie,    
               Stack<string> & pathStack)
{
    
    // NULL trees will never have the movie
    if (T == NULL)
          return false;
    // Does the this node have the movie?
    if (T->QorA == movie)
          return true; 
          
    if ( TracePath(T->yes, movie, pathStack) ) 
          return true;
          
    if ( TracePath(T->no, movie, pathStack) )
          return true;
    
    return false;
    
} */



void ShowPath(const Stack<string> & pathStack)
{
  Stack<string> path(pathStack);

  while(!path.isEmpty()){
    cout << path.top() << endl;
    path.pop();
  }
}
