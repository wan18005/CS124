/***********************************************************************
* Program:
*    Assignment 34, POINTER ARITHMETIC
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*   This program is going to count the letter the user want to find.
*
*    Estimated:  1 hrs   
*    Actual:     1 hrs
*   Use pointer rather than the old way for the countLetters.
*
************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
* This function the letter in that line.
************************************************************************/
int countLetters(char letter , char* text)
{
   int start = 0;
   for (char * a = text; *a; a++)
   {
      if (letter == *a)
         start++;
      
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
   char text[256];
   
   cout << "Enter a letter: ";
   cin >> letter;
   cin.ignore(); // Ignore letter as cin

   
   cout << "Enter text: ";
   cin.getline(text, 256); //grab he whole line for text
   
   int start = countLetters(letter,text);
   
   cout << "Number of '" << letter << "'s: " << start << endl;
   return 0 ;
}