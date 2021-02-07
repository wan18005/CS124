/***********************************************************************
* Program:
*    Test 2, ASCII Values
*    Brother Helfrich, CS124
* Author:
*    The Key
* Summary: 
*    This program implement a guessing game where the user tries to
*    guess the ASCII Value for a given character.
*
************************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
* letter grade
************************************************************************/
char letterGrade()
{
   char letter; 
   cout << "Which value would you like to guess: ";
   cin >> letter;
   return letter;
}

/***********************************************************************
* guess value
************************************************************************/
bool guessValue(int guess, char answer)
{
   if (guess == answer)
      return true;
   if (guess > answer)
      cout << "Too high" << endl;
   else
      cout << "Too low" << endl;
   return false;
}

/***********************************************************************
* play game do while
************************************************************************/
int playGame(char answer)
{
   int guessNumber = 0;
   int guess;
   do
   { 
      cout << "What is the value of \'"
         << answer
         << "\'? ";
      cin >> guess;
      guessNumber++;
   }
   while (!guessValue(guess,answer));
   return guessNumber++;
}

/***********************************************************************
* Main
************************************************************************/
int main()
{ 
   char answer = letterGrade();
   int guessNumber = playGame(answer);
   cout << "You got it in "
       << guessNumber
       << " guesses." << endl;
}
