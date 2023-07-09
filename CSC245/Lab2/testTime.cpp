
using namespace std;
#include "time.h"

void print(Time t[]);

int main() {

      Time myTime(9,30,0);
      myTime.Write();
      myTime.WriteAmPm();
      
      myTime.Set(8,0,0);
      myTime.WriteAmPm();
      myTime.Mealtime();
      
      Time Schedules[10];
      print(Schedules);
      
      return 0;
      
}

void print(Time t[]) {

      for (int i = 0; i < sizeof(t); i++) {
          t[i].Set(11, 0, 0);
          t[i].WriteAmPm();
      }
          
}

// There are 11 destructors called because there were 11 objects created by creating myTime 
// and an array of Schedule size 10

