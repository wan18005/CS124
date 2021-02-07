/***********************************************************************
* Program:
*    Practice 43, Title Case
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*    
************************************************************************/

#include <iostream> // cin and out
#include <iomanip>
#include <fstream>   // for IFSTREAM
#include <cstdlib>
#include <cassert>
#include <cctype>     // for TOUPPER() and TOLOWER()
using namespace std;


void getFilename(char *fileName);
void readText(const char *fileName, char *text);
void convertToTitleCase(char *text);




/*******************************************
 * GET FILENAME
 * Fetch the filename
 ******************************************/
void getFilename(char *fileName)
{
   cout << "Please enter the filename: ";
   cin  >> fileName;
}

/*******************************************
 * READ TEXT
 * Read the line of text from fileName and put 
 * it in a string 
 *******************************************/
void readText(const char *fileName, char *text)
{
   // open the file
   ifstream fin(fileName);
   if (fin.fail())
   {
      text[0] = '\0'; // empty string
      return;
   }

   // read the data
   fin.getline(text, 256);
   
   // close the file
   fin.close();
}

/*****************************************
 * CONVERT TO TITLE CASE
 * Conver the passed text into title case.  This
 * means every letter following a space will be
 * made uppercase.  Don't forget to capitalize
 * the first letter of the string also!
 *****************************************/
void convertToTitleCase(char *text)
{
   // capitalize the first character
   bool capitalize = true;

   // walk through all the characters in the string
   for (; *text; text++)
   {
      // if we are a letter (or digit...)
      if (*text != ' ')
      {
         // capitalize if we need to
         if (capitalize)
            *text = toupper(*text);
         else
            *text = tolower(*text);

         // everything after the first letter in the word is lowercase
         capitalize = false;
      }
      else
         capitalize = true;
   }
}

/**********************************************************************
 * MAIN
 * Hold the data and call the functions
 ***********************************************************************/
int main()
{
   // get text
   char fileName[256];
   getFilename(fileName);
   char text[256];
   readText(fileName, text);

   // convert the text
   convertToTitleCase(text);

   // display the results
   if (*text)
      cout << text << endl;
   else
      cout << "The file is empty\n";
   
   return 0;
}