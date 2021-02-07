    /***********************************************************************
* Program:
*    Project 09, Mad Lib        
*    Brother Clements, CS124
* Author:
*    Yiqi Wang     
* Summary: 
*    My program prompts the user for a mad lib, prompts them to fill 
in the information, and displays the completed mad lib.
*
*    Estimated:  4.0 hrs   
*    Actual:     5.0 hrs
*    The most difficult part was ask question founction the user input into
the mad lib.
************************************************************************/
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

/***********************************************************************
 * This function will display the question for the user to enter the
 * file name 
 * ********************************************************************/
void getFileName(char fileName[256])
{
  
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   cin.ignore();
}


/*****************************************************************
 * This function will ask the questions based on the file the 
 * user chose.
 * **************************************************************/
void askQuestions(char word[32])
{
   if ((word[0] != ':') || !(isalpha(word[1])))
   // serch for ":" and whether the  1 array is a letter
   {
      return; //return nothing  if the word is a token.
   }
   cout << "\t"; 
   // otherwise put a space first
   cout << (char)toupper(word[1]); 
   //change to upper case for the arrary at 1.

   for (int i = 2; word[i] != '\0'; i++)  
   // start at 2 if the word is not a \0 add one
   {
      if (word[i] == '_')      // if the word is a space
         cout << " ";            // cout the sapce
      else
         cout << (char)tolower(word[i]); 
         // change the word input back to lower case
   }

   cout << ": ";  // then cout a :
   cin.getline(word, 32);  // get that word
}

/*********************************************************************
 * This function will read the file and count the words in it.
 * ******************************************************************/
bool readFile(char story[256][32])
{
   int length;
   char fileName[256];
   getFileName(fileName); // get the filename from the first function

   ifstream fin(fileName);   //opening the file.

   if (fin.fail())   // if fail print the following.
   {
      cout << "Unable to open file : "
           << fileName << endl;
      return false;
   }

   for (length = 0; fin >> story[length]; length++)   
   // if success for loop length + 1
   {
      if (story[length][0] == ':') //copying it to the array
         askQuestions(story[length]);  
// do the askquestion function
   }
                                                                            
   return true;  // save it
}

/**********************************************************************
 * Main will ask the other function and make sure the right values are
 * transfered over to the right functions.
 ***********************************************************************/
int main()
{
   char story[256][32] = {'\0'};  // incase we use 256 and 32 for the maximum
   readFile(story);               // read the edited store.
   cout << "Thank you for playing.\n";  //finish first round.  YES!!!
}