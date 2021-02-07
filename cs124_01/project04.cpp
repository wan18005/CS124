/***********************************************************************
* Program:
*    Project 04, Monthly Budget          
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*    This program will ask you for your budget income and expenditures.
*    Then for how much you actually made and spent. 
*    The program will then display a report:
*    Of whether the users are on target to meet their financial goals.
*    Estimated:  1 hrs   
*    Actual:     1 hrs
*    The hard thing is to style the project. As I spend most of the time 
*    in styling.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;



/**********************************************************************
 * The main() Function in C++ is the entry point of the program.
 * It us the point at which the program is started.
***********************************************************************/
double getIncome(float income)
{
   cout << "\tYour monthly income: ";
   cin >> income;
   return income;
}

/**********************************************************************
 * The getBudgetLiving() function.
 * will simply display the input budget for living.
***********************************************************************/
double getBudgetLiving(float budgetLiving)
{
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;
   return budgetLiving;
} 

/**********************************************************************
 * The getActualLiving() function.
 * will display the input of actual living cost.
***********************************************************************/
double getActualLiving(float actualLiving)
{ 
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;
   return actualLiving;
}

/**********************************************************************
 * The getActualTax() function.
 * will display the input of actual tax.
***********************************************************************/
double getActualTax(float actualTax)
{
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTax;
   return actualTax;
}

/**********************************************************************
 * The getActualTithing() function.
 * will display the input of actual tithing.
***********************************************************************/
double getActualTithing(float actualTithing)
{
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing;
   return actualTithing;
}

/**********************************************************************
 * The getActualOther() function.
 * will display the input of actual other.
***********************************************************************/
double getActualOther(float actualOther)
{ 
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;
   return actualOther;
}



/**********************************************************************
 * This function.
 * will calculate whether user in full tithe payer or not.
***********************************************************************/
double computeTithing(double income)
{  
   double budgetTithing = income * 0.1; 
   
   return budgetTithing;
   
}

/**********************************************************************
 * The computeTax() function.
 * will do nothing right now.
***********************************************************************/
double computeTax(float monthlyIncome)
{
   float yearlyIncome = monthlyIncome * 12;
   float yearlyTax;
   
   if (yearlyIncome >= 0 && yearlyIncome < 15100)
      yearlyTax = yearlyIncome * 0.10;
   
     
   else if ( yearlyIncome >= 15100 && yearlyIncome < 61300)
      yearlyTax = 1510 + 0.15 * (yearlyIncome - 15100);
      
   else if ( yearlyIncome >= 61300 && yearlyIncome < 123700)
      yearlyTax = 8440 + 0.25 * (yearlyIncome - 61300);
      
   else if ( yearlyIncome >= 123700 && yearlyIncome < 188450)
      yearlyTax = 24040 + 0.28 * (yearlyIncome - 123700);
      
   else if ( yearlyIncome >= 188450 && yearlyIncome < 336550)
      yearlyTax = 42170 + 0.33 * (yearlyIncome - 188450);
      
   else if ( yearlyIncome >= 336500)
      yearlyTax = 91043 + 0.35 * (yearlyIncome - 336550);
  
   float monthlyTax = yearlyTax / 12;
   
   return monthlyTax;
}      

/**********************************************************************
 * The display() function.
 * will display everything as an output.
***********************************************************************/
float display (double income, double budgetLiving,
   double actualTax, double actualTithing,
   double actualLiving, double actualOther)
   
{
   double monthlyIncome = income;
   double budgetTax = computeTax(monthlyIncome);
   double budgetTithing = computeTithing(income);
   double budgetOther = income - budgetTax - budgetTithing - budgetLiving;
   double actualDifference = income - actualTax - actualTithing 
      - actualLiving - actualOther;
   double budgetDifference = 0;
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << endl;
   cout << "The following is a report on your monthly expenses" << endl;
   cout << "\tItem" << setw(24) << "Budget" << setw(16) << "Actual" << endl;
   cout << "\t=============== =============== ===============" << endl; 
   cout << "\tIncome" << setw(11) << "$" << setw(11) << income << setw(5) 
      << "$" << setw(11) << income << endl;
   cout << "\tTaxes" << setw(12) 
      << "$" << setw(11) << budgetTax << setw(5) 
      << "$" << setw(11) << actualTax << endl;
   cout << "\tTithing" << setw(10) << "$" << setw(11) 
         << budgetTithing << setw(5) 
      << "$" << setw(11) << actualTithing << endl;
   cout << "\tLiving" << setw(11) << "$" << setw(11) << budgetLiving
      << setw(5) << "$" << setw(11) << actualLiving << endl;
   cout << "\tOther" << setw(12) << "$" << setw(11) 
         << budgetOther << setw(5) 
      << "$" << setw(11) << actualOther << endl;
   cout << "\t=============== =============== ===============" << endl;
   cout << "\tDifference" << setw(7) << "$" << setw(11) 
         << budgetDifference << setw(5) 
      << "$" << setw(11) 
      << actualDifference 
      << endl;
   
}

/**********************************************************************
 * The main() Function in C++ is the entry point of the program.
 * It us the point at which the program is started.
***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);


   cout << "This program keeps track of your monthly budget" << endl;
   cout << "Please enter the following:" << endl;

   float income = getIncome(income);
   float budgetLiving = getBudgetLiving(budgetLiving);
   float actualLiving = getActualLiving(actualLiving);
   float actualTax = getActualTax(actualTax);
   float actualTithing = getActualTithing(actualTithing);
   float actualOther = getActualOther(actualOther);

   display (income,budgetLiving,actualTax,
         actualTithing,actualLiving,actualOther);
   return 0 ;
}
