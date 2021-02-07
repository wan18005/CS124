    /***********************************************************************
* Program:
*    Project 10, Mad Lib        
*    Brother Clements, CS124
* Author:
*    Yiqi Wang     
* Summary: 
*    My program prompts the user for a mad lib, prompts them to fill 
in the information, and displays the completed mad lib.
*
*    Estimated:  4.0 hrs   
*    Actual:     8.0 hrs
*    The most difficult part is the display how I need to replace 
*    the word inside <> and print them out that cost the most time 
*    while also using the switch for the puncation
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
   cin.ignore(); // I added this so wont have error with test Bed
}


/*****************************************************************
 * This function will ask the questions based on the file the 
 * user chose.
 * **************************************************************/
void askQuestions(char word[32])
{
   if ((word[0] != ':') || !(isalpha(word[1])))
   // search for ":" and whether the  1 array is a letter
   {
      return; //return nothing  if the word is a token.
   }
   cout << "\t"; 
   // otherwise put a space first
   cout << (char)toupper(word[1]); 
   //change to upper case for the array at 1.

   for (int i = 2; word[i] != '\0'; i++)  
   // start at 2 if the word is not a \0 add one
   {
      if (word[i] == '_')      // if the word is a space
         cout << " ";            // cout the space
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
int readFile(char story[256][32])
{
   int length;
   char fileName[256];
   getFileName(fileName); // get the filename from the first function

   ifstream fin(fileName);   //opening the file.

   if (fin.fail())   // if fail print the following.
   {
      cout << "Unable to open file : "
           << fileName << endl;
      return -1;
   }

   for (length = 0; fin >> story[length]; length++)   
   // if success for loop length + 1
   {
      if (story[length][0] == ':') //copying it to the array
         askQuestions(story[length]);  
// do the askquestion function
   }
                                                                            
   return length;  // save it
}

/*********************************************************************
 * This function will change the puncation in different cases
 * for array 0 and array 1
 * ******************************************************************/
void changePun(char word[32])    
{  
   switch ((int) word[1])       
   {
      case '!':    // array word 1 is a !  swap it with \0
         word[0] = '\n';  
         word[1] = '\0';
         break;
      case '.':    // array word 1 is .  switch with .
         word[0] = '.';
         word[1] = '\0';
         break;
      case ',': // array word 1 is .  switch with .
         word[0] = ',';
         word[1] = '\0';
         break;      
   }
}

/*********************************************************************
 * This function will display the story out
 * ******************************************************************/   
void display(char story[256][32],int storyLength)
{
   cout << endl;      // create a space line
   cout << story[0];   // prompt the story at array[0]
   
   for (int i = 1 ; i < storyLength; i++)   
   // i start at arrary 1 it should be smaller then the story length
   { 
      if (story[i][0] == ':')  //search for [1++][0] if it is a ":"
         changePun(story[i]);  //use the changepun function 
         // to change the word at arrary [0] and [1]
      if ((story[i][1] == '<') && (story[i - 1][0] != '\n')) 
      //[1++][1] is a '<' and also is not a \n in the file
         cout << " \"";   // use a \'
      else if (story[i][1] == '<')  // other wise use \'
         cout << "\"";
      else if (story[i][1] == '>')  //> it means the finish of the word
// put a "
         cout << '"';           
      else if ((story[i - 1][0] == '\n') || (story[i][0] == '.')
          || (story[i][0] == ',') || (story[i][0] == '\n')
          || (story[i - 1][1] == '<'))
         cout << story[i];   
         // if those above all happen just print the story at [i]
      else
         cout << " " << story[i];
   }   
   // otherwise have a space before the story[i]
   cout << endl;   // finish the line
}

/*********************************************************************
 * This function will ask the user whether they want to play 
 * again or not
 * ******************************************************************/ 
bool again()
{
   char answer;    // answer respond as letter
   bool playAgain;   // yes or no bool
   
   cout << "Do you want to play again (y/n)? ";
   cin >> answer;
   
   if (answer == 'y')         
      playAgain = true;
   else if (answer == 'n')
      playAgain = false;
   return playAgain;
}

/**********************************************************************
 * Main will ask the other function and make sure the right values are
 * transfer over to the right functions.
 ***********************************************************************/
int main()
{
   char story[256][32] = {'\0'}; 
     // encase we use 256 and 32 for the maximum
   int storyLength;
   bool playAgain = true;
// I create a while loop so can it again.
   while (playAgain)
   {
      storyLength = readFile(story);
      display(story,storyLength);
      playAgain = again();
   }      
   cout << "Thank you for playing.\n";  //finish first round.  YES!!!
}