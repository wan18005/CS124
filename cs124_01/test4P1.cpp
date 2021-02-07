/***********************************************************************
* Program:
*    Practice 41, Count Digits
*    Brother Helfrich, CS124
* Author:
*    Yiqi Wang
* Summary: 
*    Count the number of digits in a given string.  The string could come
*    as a command line parameter or from a prompt
************************************************************************/

#include <iostream>
using namespace std;



/**********************************************************************
 * MAIN:
 * What Main should do: parse the command line, hold the data, and
 * delegate the work to other functions
 ***********************************************************************/
int main(int argc, char **argv)
{
   // get the user input
   char text[256];  // only used when I need to prompt the user
   char *input;     // point to argv[1] or tetxt
   switch (argc)
   {
      case 1:
         input = getInput(text);
         break;
      case 2:
         input = argv[1];
         break;
      default:
         cout << "Error: Unexpected number of command line parameters.\n"
              << "\tUsage: " << argv[0] << " [word]\n";
         return 1;
   }

   // count the number of digits
   int numDigits = countDigits(input);
   
   // display the results
   display(numDigits);
   
   return 0;
}

/*******************************************************
 * GET INPUT
 * Prompt the user for input, put the results in text.
 * Also return the value of text to make this easier
 * for the caller
 *******************************************************/
char *getInput(char *text)
{
   cout << "Please enter a word to check: ";
   cin  >> text;
   return text;
}

/***************************************************
 * COUNT DIGITS
 * Count the number of digits in text and return
 * the results
 **************************************************/
int countDigits(const char *text)
{
   int num = 0;

   // loop through the string
   for (const char *p = text; *p; p++)
      num += (*p >= '0' && *p <= '9');  // could also use isdigit()
   // ************** one possibility **************
   // num += (isdigit(*p) ? 1 : 0);
   // ************** another way...  **************
   // if (isdigit(*p))
   //    num++;

   return num;
}

/********************************************
 * DISPLAY
 * Display the results, handling all three
 * tenses: empty, singular, and plural
 *******************************************/
void  display(int numDigits)
{
   switch (numDigits)
   {
      case 0:
         cout << "There are no digits.\n";
         break;
      case 1:
         cout << "There is 1 digit.\n";
         break;
      default:
         cout << "There are "
              << numDigits
              << " digits.\n";
   }
   
   return;
}
