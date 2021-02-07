/***********************************************************************
* Program:
*    Project 02, Monthly Budget          
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*    This program will ask you for your budget income and expenditures.
*    Then for how much you actually made and spent. 
*    The program will then display a report:
*    Of whether the users are on target to meet their financial goals.
*    Estimated:  2 hrs   
*    Actual:     1.5 hrs
*    The hard thing is to know how much space,it was needed between 
*    each aisle of the table.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * The main() Function in C++ is the entry point of the program.
 * It us the point at which the program is started.
 ***********************************************************************/
int main()
{
   float income;
   float budgetedExpenses;
   float actualExpenses;
   float taxes;
   float tithe;
   float otherExpenses;
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
  //Track of monthly budget
   cout << "This program keeps track of your monthly budget\n"; 
   cout << "Please enter the following:\n";
   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetedExpenses;
   cout << "\tYour actual living expenses: ";
   cin >> actualExpenses;
   cout << "\tYour actual taxes withheld: ";
   cin >> taxes; 
   cout << "\tYour actual tithe offerings: ";
   cin >> tithe;
   cout << "\tYour actual other expenses: ";
   cin >> otherExpenses;
   cout << endl;
   cout << "The following is a report on your monthly expenses" << endl;
   cout << "\tItem" << setw(24) << "Budget" << setw(16) << "Actual" << endl;
   cout << "\t=============== =============== ===============" << endl; 
   cout << "\tIncome" << setw(11) << "$" << setw(11) << income << setw(5) 
      << "$" << setw(11) << income << endl;
   cout << "\tTaxes" << setw(12) << "$" << setw(11) << 0.00 << setw(5) 
      << "$" << setw(11) << taxes << endl;
   cout << "\tTithing" << setw(10) << "$" << setw(11) << 0.00 << setw(5) 
      << "$" << setw(11) << tithe << endl;
   cout << "\tLiving" << setw(11) << "$" << setw(11) << budgetedExpenses 
      << setw(5) << "$" << setw(11) << actualExpenses << endl;
   cout << "\tOther" << setw(12) << "$" << setw(11) << 0.00 << setw(5) 
      << "$" << setw(11) << otherExpenses << endl;
   cout << "\t=============== =============== ===============" << endl;
   cout << "\tDifference" << setw(7) << "$" << setw(11) << 0.00 << setw(5) 
      << "$" << setw(11) << 0.00 << endl;
   return 0;
}
