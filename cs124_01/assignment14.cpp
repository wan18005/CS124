/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  1 hrs   
*    Actual:     1 hrs
*      The hardest part of this program is to put new funciion in the right place, 
       and also close the function properly.
************************************************************************/

#include <iostream>
using namespace std;
void questionPeter();
int responseLord();
/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
int main()
{
  questionPeter();
  responseLord();
   return 0;
}

// ask Peter's question
void questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me, and I forgive him?\n";
   cout << "Till seven times?\n";
}

// the first part of the Lord's response
int responseLord()
{
   int L = 490;
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n" ;
   cout << "times: but, Until " << L << ".\n";
   return L;
}