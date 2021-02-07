//expressions


#include <iostream>
#include <iomanip>

using namespace std;




int main()
{
  
   float FahrenheitDegree;
   cout.setf(ios::fixed);
   cout.precision(0);
   
   cout << "Please enter Fahrenheit degrees: ";
   cin >> FahrenheitDegree;
   
   
   int f = FahrenheitDegree;
   float C = 5.0 / 9 * (f - 32); 
   cout << "Celsius: " << C << endl;

   return 0;
}