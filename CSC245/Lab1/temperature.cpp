#include <iostream>
using namespace std;

      double convert (double value); //function prototype  // unlike java, you have to declare the function first
      
      int main() {
            
            double celcius;
            
            cout << "Please enter a Celsius value: ";
            cin >> celcius;
            
            cout << celcius << " degrees Celsius is " << convert(celcius) << " degrees Fahrenheit" << endl;
            
            return 0;
            
      }
      
      double convert (double tmp) {
      
            return 1.8 * tmp + 32;  
            
      } 
      

