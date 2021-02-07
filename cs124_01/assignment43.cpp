/***********************************************************************
* Program:
*    Assignment 43, COMMAND LINE
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*    This program will convert the feet to meter 
* after a.out command line.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*      There is nothing hard for this assignment.
************************************************************************/
#include <string>       // for using string
#include <cstdlib>      // the library for atof()
#include <iostream>      // the library for atof()
using namespace std;

/**********************************************************************
 * MAIN
 ***********************************************************************/
int main(int argc, char ** argv)
{
   char meter[] = "0.3048";  // var meter for 1 feet to 1 meter
   cout.setf(ios::fixed);     // no scientific notation
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(1);         // show two decimals 
   
   for (int i = 1 ; i < argc; i++)   
   //assume smaller than the number after the a.out 
   //in this case words argv[3]
   {
      cout << atof(argv[i])   // atof is to convert a string to a float
         << " feet is "          
         << atof(meter) *  atof(argv[i])   // meter * the number a.out number
         << " meters"           
         << endl; 
   }

   return 0;
}