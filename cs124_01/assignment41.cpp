/***********************************************************************
* Program:
*    Assignment 41, ALLOCATING MEMORY 
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*   This program will compute the user grade to letter grade.
*
*    Estimated:  1 hrs   
*    Actual:     3 hrs
* 
************************************************************************/

#include <iostream>
using namespace std;

/*****************************************************************
 * This function will get the size of we are going to use
 * **************************************************************/
int getNumberOfCharacters()
{
   int size;
   cout << "Number of characters: ";
   cin >> size;
   return size;
}

/*****************************************************************
 * This function will display and do the allocate the data
 * Then it will get the prompt for the text
 * **************************************************************/
void display(int size, char* pText)
{
   if (pText == NULL)   // if pText is not vaild
   {
      cout << "Allocation failure!" << endl;   // allocation fail
   }
   
   else
   {
      cout << "Enter Text: ";      // prompt user to enter text
      cin.ignore();                
      cin.getline(pText, size + 1 ); // add one to the string
      cout << "Text: " << pText << endl;  //print it our
      delete [] pText;   //delete the line of pText
   }
}

/*****************************************************************
 * This is the main function it will run both function
 * **************************************************************/
int main()
{
   int size = getNumberOfCharacters();  
   char* pText = new(nothrow) char[size] ;
   display(size,pText);  
   return 0;
}