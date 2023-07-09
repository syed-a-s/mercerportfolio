#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main() {

	char *strPtr = new char[50];
	strcpy(strPtr, "Operating Sytem");
	int low = 0;
	for (int i = 0; i < strlen(strPtr); i++)
		if(islower(*(strPtr + i)))
			low++;
	cout << low << endl;	
}

