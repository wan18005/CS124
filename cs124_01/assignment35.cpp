/***********************************************************************
* Program:
*    Assignment 35, ADVANCED CONDITIONALS
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*   This program will compute the user grade to letter grade.
*
*    Estimated:  2 hrs   
*    Actual:     1 hrs
*   The most hard part is for the grade sign is took  
*   sometimes to not have a A+ and F-. There should be a way to do the 
*   sign but I still do the hard way. 
************************************************************************/
#include <iostream>
using namespace std;

/*****************************************************************
 * This function will find out the letter Grade of the score.
 * **************************************************************/
char computerLetterGrade(int grade)
{
   char letter;
// divided by 10 so it is easier to know the letter Grade.
   switch (grade / 10)
   {  
      case 10:
      case 9:
         letter = 'A';
         break;
      case 8:
         letter = 'B';
         break;
      case 7:
         letter = 'C';
         break;
      case 6:
         letter = 'D';
         break;
      default:
         letter = 'F';
   }
   return letter;
}

/*****************************************************************
 * This function will find out the sign for the letter Grade
 * **************************************************************/
char computeGradeSign(int grade)
{
   char sign;
   switch (grade)
   {
 // any grade end up with 5 or less from 65 to 90 will be "-"
      case 95:
      case 94:
      case 93:
      case 92:
      case 91:
      case 90:
      
     
      case 85:
      case 84:
      case 82:
      case 81:
      case 80:
      
      case 75:
      case 74:
      case 73:
      case 72:
      case 71:
      case 70:
      
      case 65:
      case 64:
      case 63:
      case 62:
      case 61:
      case 60:
         sign = '-';
         break;
      
      // any grade end with 6 or above from 66 to 89 will be "+"
      case 66:
      case 67:
      case 68:
      case 69:
      case 76:
      case 77:
      case 78:
      case 79:
      case 87:
      case 88:
      case 89:
         sign = '+';
         break;
      
      
      default:
         sign = '\n';
   }
   return sign;
}
 
/*****************************************************************
 * This function ask user for the letter grade and will use the 
 * other two function to find out for the letter grade and sign
* **************************************************************/
int main()
{
   int number;

   cout << "Enter number grade: ";
   cin >> number;

   char numLetter = computerLetterGrade(number); 
   char sign =  computeGradeSign(number);

   cout << number << "% is " << numLetter << sign;
// if sign is default it will just cout
   if (sign != '\n')
   {
      cout << endl;   
   }

   return 0;
}