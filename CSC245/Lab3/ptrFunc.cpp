#include <iostream>
#include <string>
using namespace std;

bool equalsVal(double &ptr1, double &ptr2);
bool equalsAddy(double *ptr1, double *ptr2);

int main() {

	double *ptr1 = new double;
	double *ptr2 = new double;

	// Upon declaration
  cout << "Upon declaration" << endl;
	cout << "Equal Value? " << equalsVal(*ptr1, *ptr2) << endl;
	cout << "Equal Address? " << equalsAddy(ptr1, ptr2) << endl;

	// Sharing the same address 
	*ptr1 = 5;
	ptr2 = ptr1;
  cout << endl << "Sharing the same address" << endl;
	cout << "Equal Value? " << equalsVal(*ptr1, *ptr2) << endl;
	cout << "Equal Address? " << equalsAddy(ptr1, ptr2) << endl;
 
  // Same Value but different addresses
  ptr2 = new double;
  *ptr1 = 12;
  *ptr2 = 12;
  cout << endl << "Same value but different addresses " << endl;
 	cout << "Equal Value? " << equalsVal(*ptr1, *ptr2) << endl;
	cout << "Equal Address? " << equalsAddy(ptr1, ptr2) << endl;
 
	return 0;	

}

bool equalsVal(double &ptr1, double &ptr2) { 
	return ptr1 == ptr2;
}

bool equalsAddy(double *ptr1, double *ptr2) { 
	return ptr1 == ptr2;
}
