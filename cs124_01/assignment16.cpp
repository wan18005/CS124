#include <iostream>
#include <iomanip>
using namespace std;
int income;
int TB;

int computeTax(int income)
{
  
  if (income >= 0 && income < 15100)
  TB = 10;
     
  else if ( income > 15100 && income < 61300)
  TB = 15;
      
  else if ( income > 61300 && income < 123700)
  TB = 25;
      
  else if ( income > 123700 && income < 188450)
  TB = 28;
      
  else if ( income > 188450 && income < 336500)
  TB = 33;
      
  else if ( income > 336500)
  TB = 35;
  return TB;
}

int main ()
{


  cout << "Income: ";
  cin >> income; 
  cout << "Your tax bracket is " << computeTax(income) << "%" << endl;
  return 0;
   
} 


