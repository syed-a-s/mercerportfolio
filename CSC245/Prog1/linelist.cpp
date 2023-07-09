
#include <iostream>
#include "linelist.h"

LineList::LineList() { 

    LineNode *line = new LineNode;
    LineNode *line2 = new LineNode;
    
    line->info = topMessage;
    currLine = line;
    currLineNum = 0; // Unfortunately, I had to change this to 0 to make my program better
    length = 0;
    line2->info = bottomMessage;
    currLine->back = NULL;
    currLine->next = line2;
    line2->back = line;
    line2->next = NULL;
    
}

void LineList::goToTop() {
    // Post : Advances currLine to line 1 
    while (currLine->info != topMessage) 
        currLine = currLine->back;
    
    currLine = currLine->next;
    currLineNum = 1; 
}

void LineList::goToBottom() {
    // Post : Advances currLine to last line 
    while (currLine->info != bottomMessage)  
        currLine = currLine->next;
    
    currLine = currLine->back;
    currLineNum = length;
} 

void LineList::insertLine (string newLine) {

    // Post : newLine has been inserted after the current line
	  LineNode *line = new LineNode;
	  line->info = newLine;
	  line->back = currLine;
	  line->next = currLine->next;
	
	  currLine->next->back = line;
	  currLine->next = line;
	  currLine = currLine->next;
	  currLineNum++; length++;
     
}

void LineList::deleteLine() {

    // Post : deletes the current line leaving currentline
    //        pointing to line following
    if ((currLine->info != topMessage) 
        && (currLine->info != bottomMessage)) {
   	    LineNode *line = currLine;

	  currLine->next->back = currLine->back;
	  currLine->back->next = currLine->next;
	  currLine = currLine->next;

	  delete line;

	  if (currLineNum == length)
		    currLineNum--;
            
    length--;

	  if (currLine->info == topMessage)
		    currLine = currLine->next;
	
	  if (currLine->info == bottomMessage)
		    currLine = currLine->back;
   
    } 
    
}

void LineList::printList() { 

    LineNode *temp = new LineNode;
    temp = currLine;
    int lineNum = 1;
    
    while(temp->info != topMessage)
          temp = temp->back;
    temp = temp->next;
    
    while (temp->info != bottomMessage) {
            cout << lineNum << "> " << temp->info << endl;
            temp = temp->next;
            lineNum++;
    }
    
}

void LineList::moveNextLine() { 
    
    // Post : Advances currLine (unless already at last line)
    if (currLine->info != bottomMessage) { 
          if (currLine->info != bottomMessage) { 
                currLine = currLine->next;
                currLineNum++;
          }
    }
    
}

void LineList::movePrevLine() {
    
    // Post : Advances currLine (unless already at last line)
    if (currLine->info != topMessage) { 
          if (currLine->info != topMessage) { 
                currLine = currLine->back;
                currLineNum--;
          }
    }
    
} 

int LineList::getCurrLineNum() const { 
    return currLineNum ;
}

int LineList::getLength() const {
    return length;
}

string LineList::getCurrLine() const { 
    return currLine->info;
}
