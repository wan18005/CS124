/***********************************************************************
* Program:
*    Assignment 32, STRINGS
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*   This program is going to count the letter the user want to find.
*
*    Estimated:  1 hrs   
*    Actual:     1 hrs
*   My output keep doing 1 so I spend some time on how I fix it.
*
************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
* This function the letter in that line.
************************************************************************/
int countLetters(char letter , char text[])
{
   int start = 0;
   for (int i = 0; text[i]; i++)
   {
      if (text[i] == letter)
      {
         start++;
      }
   }
   return start;
}

/***********************************************************************
* This is the main function it will prompt for letter looking for 
* and also find the letter, display it one the screen.
************************************************************************/
int main()
{
   char letter;
   cout << "Enter a letter: ";
   cin >> letter;
   cin.ignore(); // Ignore letter as cin

   char text[256];
   cout << "Enter text: ";
   cin.getline(text, 256); //grab he whole line for text

   int start = countLetters(letter,text);
   cout << "Number of '" << letter << "'s: " << start << endl;
   return 0 ;
}