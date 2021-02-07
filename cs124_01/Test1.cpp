/*********************************************************
* Program:     
*    Test 1,
*    Brother {Cook, Comeau, Helfrich, Lilya, Unsicker, Phair}, CS124
* Author:
*    your name
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS
***************************************************************/

#include <iostream>
using namespace std;

float getGPA()
{
float GPA;
cout << "What is your GPA? ";
cin >> GPA;
return GPA;
}

void display(float GPA)
{
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(1);

cout << "Your GPA is " << GPA << endl;

return;
}


int main()
{
float gpa;

gpa = getGPA();

display(gpa);

return 0 ;
} 