/***********************************************************************
* Program:
*    Project 07, Calendar         
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*    This program will display a calendar
*    
*    Estimated:  4 hrs   
*    Actual:     8 hrs
*    The hard thing compile the program since it is a big project.
*    and also what kind of loop and naming variable is hard,
*    I spent around 1 hour just for checking variable name and fixing
*    variable in the function£¬ while also styling take a lot of time.
************************************************************************/


#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Function getMonth
 * Asking input for the month.
 *********************************************************************/
int getMonth()
{
   int month;
   cout << "Enter a month number: ";
   cin >> month;
   
   
   while (month <= 0 || month > 12)
   {
      cout << "Month must be between 1 and 12." << endl;
      cout << "Enter a month number: ";
      cin >> month;
   }
   return month;
}

/**********************************************************************
 * Function getYears
 * Asking input for the year.
 *********************************************************************/
int getYears()
{
   int year;
   cout << "Enter year: ";
   cin >> year;
   
   while (year <= 1752)
   {
      cout << "Year must be 1753 or later." << endl;
      cout << "Enter year: ";
      cin >> year;
   }
   cout << endl;
   
   return year;
}

/**********************************************************************
 * Function bool leapYearChecker
 * Check whether that year is a leap year or not.
 *********************************************************************/
bool leapYearChecker(int year)
{
   if (year % 4 == 0 && year % 100 != 0)
   {
      return true;
   } 
   else if (year % 400 == 0)
   {
      return true;
   }
   else 
   {
      return false;
   }
}

/**********************************************************************
 * Function computeDayInYear
 * Computes the number of days in that year.
 *********************************************************************/
int computeDayInYear(int year)
{
   bool leap = leapYearChecker(year);
   int numDayInYear;
    
   if (leap == true)
   {
      numDayInYear = 366;
   }
   else
   { 
      numDayInYear = 365;
   }
   return numDayInYear;
}

/**********************************************************************
 * Function computeDayInMonth
 * Computes the number of days in that month.
 *********************************************************************/
int computeDayInMonth(int month,int year)
{
   int daysInMonth;
   bool leap = leapYearChecker(year);
  
   if (month == 1 || month == 3 || month == 5 || month == 7 
      || month == 8 || month == 10 || month == 12 )
   {
      daysInMonth = 31;
   }
   else if (month == 2)
   {
      if (leap == true)
      {
         daysInMonth = 29;
      }
      else 
      {
         daysInMonth = 28;
      }
   }
   else if (month == 4 || month == 6 || month == 9 || month == 11)
   {
      daysInMonth = 30;
   }
   return daysInMonth;
}

/**********************************************************************
 * Function computeOffset
 * Computes the offset.
 *********************************************************************/
int computeOffset(int month, int year)
{
   int numberDay = 0;
   int numberYears = year - 1753;
   
   for (int startYear = 1753; startYear < year; startYear++)
   {
      numberDay += computeDayInYear(startYear);
   }
     
   for ( int startMonth = 1; startMonth < month; startMonth++)
   {
      numberDay += computeDayInMonth(startMonth,year);
   }  
   int offset = numberDay % 7;
   return offset;
}

/**********************************************************************
 * Function displayTable
 * This function will display the calendar
 *********************************************************************/
void displayTable(int numberDay, int offset)
{   
   int week = (offset + 1 ) % 7;
   for ( int w = 0; w <= week; w++)
   {
      cout << "" << setw(4);
   }
  
   for (int m = 1; m <= numberDay; m++)
   {
      cout << setw(4) << m;
      
      week++;
  
      if (week % 7 == 0)
         cout << endl;
   } 
    
   if (week % 7 != 0)
      cout << endl;
}

/**********************************************************************
 * Function display table top
 * This function will display the top part of the calendar.
 *********************************************************************/
void displayTableTop(int month, int year)
{
   if (month == 1)
      cout << "January, " << year;

   else if (month == 2)
   
      cout << "February, " << year;
   
   else if (month == 3)
   
      cout << "March, " << year;
   
   else if (month == 4)
   
      cout << "April, " << year;
   
   else if (month == 5)
   
      cout << "May, " << year;
   
   else if (month == 6)
   
      cout << "June, " << year;
   
   else if (month == 7)
   
      cout << "July, " << year;
   
   else if (month == 8)
   
      cout << "August, " << year;
   
   else if (month == 9)
   
      cout << "September, " << year;
   else if (month == 10)
   
      cout << "October, " << year;
   
   else if (month == 11)
   
      cout << "November, " << year;
   
   else if (month == 12)
   
      cout << "December, " << year;
   
   cout << endl;
   
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
} 

/**********************************************************************
 * Function display
 * Main function for display 
 *********************************************************************/
void display(int month, int year, int offset)
{
   displayTableTop(month,year);
   int numDays = computeDayInMonth(month, year);
   displayTable(numDays,offset);
}

/**********************************************************************
 * Function main
 * Calls all the function.
 *********************************************************************/
int main()
{
   int month = getMonth();
    
   int year = getYears();
    
   int offset = computeOffset(month, year);
    
   display(month,year,offset);
    
   return 0;
}