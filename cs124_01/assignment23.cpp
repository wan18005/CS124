#include <iostream>
#include <iomanip>
using namespace std;

// input  
int getNumber()
{
cout << "What multiples are we adding? ";
int number;
cin >> number;
return number;
}

// loop
int addMultiples(int multiple)
{
   int start = 0;
   int end = 100;

    for (int count = multiple; count < 100; count += multiple)
{
     start += count;
}

    return start;
}
// display function
void display(int multiple, int start)
{
 cout << "The sum of multiples of "
      << multiple
      << " less than 100 are: "
      << start
      << endl;
   return;
}

// main function 
int main()
{
  int multiple = getNumber();
  int start = addMultiples(multiple);
  
  display(multiple,start);
  
  return 0;
}