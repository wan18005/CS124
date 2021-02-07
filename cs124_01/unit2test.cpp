/***********************************************************************
* Program:
*    Test 2, Guessing Game        
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*    This program will generate a random number between 0 to 99 
*     and play a guessing game.
************************************************************************/

#include <iostream>   // for CIN, COUT
#include <ctime>      // for time(), part of the random process
#include <stdlib.h>   // for rand() and srand()
using namespace std;


/**********************************************************************
 * display
 ***********************************************************************/
void display(int guessnumber)
{
   cout << "You guessed it in " << guessnumber << " tries\n";
}


/**********************************************************************
 * Whether the guess in too high or too low
 ***********************************************************************/
bool guessValue(int guess, int answer)
{
   if (guess == answer)
      return true;
   if (guess > answer)
      cout << "Too high" << endl;
   else 
      cout << "Too low" << endl;
   return false;
}

/**********************************************************************
 * Number of guess number.
 ***********************************************************************/
int playGame(int answer)
{
   int guessNumber = 0;
   int guess;
   do
   {
      cout << "What is your guess: ";   
      cin >> guess;
      guessNumber++; 
   }
   while (!guessValue(guess,answer));
   return guessNumber;
}
   
/**********************************************************************
 * Main function
 ***********************************************************************/
int main(int argc, char **argv)
{
   // this code is necessary to set up the random number generator. If
   // your program uses a random number generator, you will need this 
   // code. Otherwise, you can safely delete it.  Note: this must go in main()
   srand(argc == 1 ? time(NULL) : (int)argv[1][1]);
   int guessNumber;
   
   int answer;
   int guessNumer = playGame(answer);
   display(guessNumber);

   return 0;
}
