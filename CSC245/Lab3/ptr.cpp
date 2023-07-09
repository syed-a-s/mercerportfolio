
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

struct RecType {   
    int age;
    float weight;
    char gender;    
};
      
int main() {
      
    int num = 5;
    int *intPtr = NULL;   
    intPtr = &num;
    *intPtr = *intPtr * 10;
    cout <<"\tintPtr points to : \t\t\t" << *intPtr << endl;
          
    RecType *recPtr = new RecType;
    recPtr->age = 25;
    recPtr->weight = 190; 
    recPtr->gender = 'M';
    recPtr->age = recPtr->age + 5;
    cout << "\tThree Fields Pointed to by recPtr : \t" << recPtr->age << " " << recPtr->weight << " " << recPtr->gender << endl;
    delete recPtr;
    recPtr = NULL; 

    char *strPtr = new char[50];
    strcpy (strPtr, "Operating Systems");
    cout << "\tstrPtr points to :\t\t\t" << strPtr << endl;
    int lowerCase = 0;
    for(int i = 0; i <= strlen(strPtr); i++){   
	if(islower(*(strPtr + i)))
	     lowerCase++;
    }
    cout << "\tNumber of lower case letters :\t\t" << lowerCase << endl;  
    cout << "\tPrinting strPtr after adding 10 :\t" << strPtr + 10 << endl;
    strPtr - 10;
    delete strPtr;

    return 0;

}
