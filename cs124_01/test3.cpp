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


char name[256];
char firstName[256];

int main()
{

char name[256];
char firstName[256];


cout << "What is your professor's name: ";
cin >> name;
cout << "What is your first name: ";
cin >> firstName;
cout << "\t" << firstName << ", you are taking Br. " << name 
<< "'s class" << " \"CS124\"." << endl;  
return 0;
}