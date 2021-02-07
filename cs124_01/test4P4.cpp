#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cassert>
using namespace std;

char *getInput(char *text);
int countLetters (char *text);
int countDigits (char *text);
int countSymbols (char *text);
int countSpaces (char *text);
void display(int numLetters, int numDigits, int numSymbols, int numSpaces);

/*
 * main function is to call the other functions.
 */
int main(int argc, char * argv[])
{
   char text[256];
   char *input; // point to argv[]
   int totalLetters = 0;
   int totalDigits = 0;
   int totalSymbols = 0;
   int totalSpaces = 0;
   int count = 0;

   if (argc == 1)
   {
      input = getInput(text);
      int numLetters = countLetters(input);

      totalLetters += numLetters;
      //count the number of digits
      int numDigits = countDigits(input);

      totalDigits += numDigits;
      //count the number of symbols
      int numSymbols = countSymbols(input);

      totalSymbols += numSymbols;
      //count the number of spaces
      int numSpaces = countSpaces(input);

      totalSpaces += numSpaces;
   }

   else
      for (int i = 2; i - 1 < argc; i++)
      {
         input = argv[i - 1];
         count++;

         //count the number of letters
         int numLetters = countLetters(input);

         totalLetters += numLetters;
         //count the number of digits
         int numDigits = countDigits(input);

         totalDigits += numDigits;
         //count the number of symbols
         int numSymbols = countSymbols(input);

         totalSymbols += numSymbols;
         //count the number of spaces

         totalSpaces = count - 1;
      }
   //display the results

   display(totalLetters, totalDigits, totalSymbols, totalSpaces);
   return 0;
}

/*
 * getInput is to get user input.
 */
char *getInput(char *text)
{
   cout << "Please enter a word to check: ";
   cin.getline(text,256);
   return text;
}

/*
 * countLetters
 */
int countLetters (char *text)
{
   int num = 0;
   for (const char *p = text; *p; p++)
      num += (isalpha(*p) ? 1 : 0);
   return num;
}

/*
 * countDigits
 */
int countDigits (char *text)
{
   int num = 0;
   for (const char *p = text; *p; p++)
      num += (isdigit(*p) ? 1 : 0);
   return num;
}

/*
 * countSymbols
 */
int countSymbols (char *text)
{
   int num = 0;
   for (const char *p = text; *p; p++)
      num += (ispunct(*p) ? 1 : 0);
   return num;
}

/*
 * countSpaces
 */
int countSpaces (char *text)
{
   int num = 0;
   for (const char *p = text; *p; p++)
      num += (isspace(*p) ? 1 : 0);
   return num;
}

/*
 * display the result
 */
void display(int numLetters, int numDigits, int numSymbols, int numSpaces)
{
   cout << '\t'
        << filename;

   switch (count)
   {
      case 0:
         cout << " is empty.\n";
         break;
      case 1:
         cout << " has 1 line.\n";
         break;
      default:
         cout << " has " << count << " lines.\n";
   }
}



