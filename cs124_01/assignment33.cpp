/***********************************************************************
* Program:
*    Assignment 33, Pointers
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*    This program will find who will paid for the date
*
*    Estimated:  1hrs   
*    Actual:     2 hrs
*      The most hard part is the to know which number to use pointer and 
        which to reference.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Get how much money Sam has.
 ***********************************************************************/
float getSam()
{
   float balance;
   cout << "What is Sam's balance? ";
   cin >> balance;
   return balance;
}

/**********************************************************************
 * Get how much money Sue has.
 ***********************************************************************/
float getSue()
{
   float balance;
   cout << "What is Sue's balance? ";
   cin >> balance;
   return balance;
}

/**********************************************************************
 * This function will ask for the amount use for Sam and Sue's date
 * Then it will pointer to an account.
 ***********************************************************************/
void date(float *pAccount)
{
   cout << "Cost of the date:" << endl;

   float dinner;
   float movie;
   float iceCream;
// all the cost
   cout << "\tDinner:    ";
   cin >> dinner;

   cout << "\tMovie:     ";
   cin >> movie;

   cout << "\tIce cream: ";
   cin >> iceCream;
// add all the cost
   float total = dinner + movie + iceCream;
// cost will subtract from the original balance;
   *pAccount -= total;
}

/**********************************************************************
 * This is the main function.
 * Here we will reference from the date function to see who will paid
 * for this date.
 ***********************************************************************/
int main()
{
   float sam = getSam();
   float sue = getSue();
   float* richAccount;

// assign pointer to the person with the most money
   if (sam > sue)
   {
      richAccount = &sam;
   }
   else 
      richAccount = &sue;
// update balance for sue and sam
   date(richAccount);
// print out the balance
   cout << "Sam's balance: $" << sam << endl;
   cout << "Sue's balance: $" << sue << endl;
   return 0;
}