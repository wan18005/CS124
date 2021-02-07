
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  float income;
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout <<"\tYour monthly income: ";
  cin  >> income; 
  cout << "Your income is: $" << setw(9) << income <<endl;
  }