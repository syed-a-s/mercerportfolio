
#include <iostream>
#include <string> 
using namespace std;

const int SIZE = 100;

struct DateType {
	string month;
	int day;
	int year;
};

// Insert EventType definition HERE
struct EventType {
  string place;
  DateType date;
};

void PrintStruct (DateType Holiday);
void AssignMonth (EventType Dates[]);

int main() {
	DateType Holiday = (DateType){.month = "September", .day = 2, .year = 2020};
  EventType Dates[SIZE];
	PrintStruct (Holiday);
	AssignMonth (Dates);
	return 0;
}

void PrintStruct (DateType Holiday) {
	// pre  : Holiday is intialized with three field values
	// post : Function prints date of Holiday in form mm dd, yy
 cout << Holiday.month <<" " << Holiday.day <<", " << Holiday.year << "\n"; 
 
}

void AssignMonth (EventType Dates[]) {
	// pre  : none 
	// post : The month field of every date record in array is assigned a month 
  for(int i = 0; sizeof(Dates); i++)
    Dates[i].date.month = "September"; 

}
