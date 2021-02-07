/***********************************************************************
* Program:
*    Assignment 31, DESIGN
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*   This program is a modify version of assignment 3.0.
*
*    Estimated:  2 hrs   
*    Actual:     2 hrs
*   The averageGrade function will be the hardest part in this assignment.
*
************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
* This function will prompt user for the grade 10 times.
************************************************************************/
int getGrade(int grade[],int num)
{
   for (int i = 0; i < num; i++ )
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> grade[i];
   }
}

/***********************************************************************
* This function will find the average for the 10 grades.
* Then it will pass by to main.
************************************************************************/
int averageGrade(int grade[],int num)
{
   int addGrade = 0;

   for (int i = 0; i < num; i++)
   {
      if (grade[i] == -1)
      {
         addGrade += 0;
      }
      else 
         addGrade += grade[i];
   }
   
   for (int j = 0 ; j < num; j++)
   {
      if (grade[j] == -1)
         num = num - 1;
   }
   
   int average = 0;
   if (addGrade > 0)
   {
      average = addGrade / num;
      return average;
   }
   else 
      return - 1;
   
}

/***********************************************************************
* This function is the main function.
* It will display the output for the acerage grades.
************************************************************************/
int main()
{
   int numGrade = 10;
   int grade[numGrade];
   
   getGrade(grade, numGrade);
   int average = averageGrade(grade,numGrade);
   if (average > -1)
      cout << "Average Grade: " << average << "%" << endl;
   else
      cout << "Average Grade: " << "---%" << endl;
   return 0; 
}



