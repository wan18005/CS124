/***********************************************************************
* Program:
*    Assignment 30, ARRAY SYNTAX
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*   This program will read 10 grades from a file and display the average. 
*
*    Estimated:  2 hrs   
*    Actual:     3 hrs
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
   
   float averageGrade;

   for (int i = 0; i < num; i++)
   {
         addGrade += grade[i];
   }
   
  averageGrade = addGrade / 10;
   return averageGrade;
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
   
      cout << "Average Grade: " << average << "%" << endl;
   
   return 0; 
}



