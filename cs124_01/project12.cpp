/***********************************************************************
* Program:
*    Project 12, Sudoku        
*    Brother Clements, CS124
* Author:
*    Yiqi Wang     
* Summary: 
*    This program will read a file for a sudoku game 
*    and allow user to the play the game according to the rule
*    with some help.
*
*    Estimated:  10.0 hrs   
*    Actual:     10.0 hrs
*    The most difficult part read the file, 
*    getCorrdinates and compute for the value.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

/**********************************************************************
 * Prompts the user for the name of the file where the board is saved
 ************************************************************************/
void getFilename(char filename[])
{
   cout << "Where is your board located? ";
   cin >> filename;
}

/**********************************************************************
 * Open the location file into a two dimensional array 
 ************************************************************************/
bool readFile(char filename[], int board[][9])
{   
    // open fin
   ifstream fin(filename);
       
   if (fin.fail())
   {
      return false;
   }
   else
   {
      for (int r = 0; r < 9; r++)
      {
         for (int c = 0; c < 9; c++)
         {
            fin >> board[r][c];
         }
      }
      return true;
   }
   fin.close();
}

/**********************************************************************
 * Quit and Save the edited  game board data to a file
 ************************************************************************/
bool writeFile(int board[][9])
{
   char finalDestination[256];
   //open
   ofstream fout;

   // Prompt user for name of the file to save board to
   cout << "What file would you like to write your board to: ";
   cin  >> finalDestination;

   // Open the file
   fout.open(finalDestination);

   // Display message if file could not be opened
   // return false
   if (fout.fail())
   {
      cout << "could not save file";
      return false;
   }

   // Write board to file
   for (int r = 0; r < 9; r++)
   {
      for (int c = 0; c < 9; c++)
      {
         if (c == 8) // reach to the end finish
            fout << board[r][c] << endl;
         else  // else put space
            fout << board[r][c] << " "; 
      }
   }

   // Close file and display message of success
   // return true
   fout.close();
   cout << "Board written successfully\n";
   return true;

}

/**********************************************************************
 * Prints the game options and commands for the user
 *********************************************************************/
void displayOptions()
{
   cout << "Options:" << endl;
   cout << "   ?  Show these instructions" << endl;
   cout << "   D  Display the board" << endl;
   cout << "   E  Edit one square" << endl;
   cout << "   S  Show the possible values for a square" << endl;
   cout << "   Q  Save and Quit" << endl;
}

/**********************************************************************
 * Read the multible array to the screen game board
 ************************************************************************/
void displayBoard(int board[][9])
{
   // Header
   cout << "   A B C D E F G H I" << endl;

   
   for (int r = 0; r < 9; r++)
   {
      cout << r + 1 <<  "  ";
      
      for (int c = 0; c < 9; c++)
      {
         if (board[r][c] != 0)
            cout << board[r][c];
         else cout << " ";
         if (c % 3 == 2 && c != 8)
            cout << "|";
         else if (c == 8)
            cout << (r  % 3 == 2 && r != 8 ?
                     "\n   -----+-----+-----\n" : "\n");
         else
            cout << " ";
      }
   }
}

/**********************************************************************
 * Asking player for what location for the game board they want
 *********************************************************************/
void getCoordinates(char coords[])
{
   cout << "What are the coordinates of the square: ";
   cin >> coords[0];
   cin >> coords[1];
}

/**********************************************************************
 * Key rule of the game
 ************************************************************************/
bool computeValue(int r, int c,char coords[], int board[][9])
{
   if (board[r][c] != 0)    
// if both row and col is not 
// a zero meaning it is filled with number return false;
   {
      cout << "ERROR: Square '" << coords[0] << coords[1]
           << "' is filled" << endl;
      return false;
   }
   // otherwise return true;
   return true;
}

/**********************************************************************
 * Change the location to a number player wants according to the rules
 ************************************************************************/
void editSquare(int board[][9],char coords[])
{
   
   int c;
   int r;
   getCoordinates(coords);
   c = toupper(coords[0]) - 'A';    // col start from letter A
   r = (int)coords[1] - '1';        // rol start from 1
   coords[0] = toupper(coords[0]);  // set corrd[0] to captial letter A 
   if (computeValue(r, c, coords, board))
   {
      cout << "What is the value at '" << coords[0]
           << coords[1] << "': ";
      cin >> board[r][c];
   }
}


/**********************************************************************
 * The Main loop function for all the command player needs
 **********************************************************************/
void interact(int board[][9])
{
   char displayOption;
   char coords[256];
   displayOptions();
   cout << endl;
   displayBoard(board);
   do
   {
      cout << "\n> ";
      cin >> displayOption;
      switch (displayOption)
      {
         case '?':
            displayOptions();
            cout << endl;
            break;
         case 'D':
         case 'd':
            displayBoard(board);
            break;
         case 'E':
         case 'e':
            editSquare(board, coords);
            break;
         case 'Q':
         case 'q':
            break;
         default:
            cout << "ERROR: Invalid command\n";
            break;
      }
   } 
   while (toupper(displayOption) != 'Q');
   // exit the loop if it is Q or q
   writeFile(board); 
}





/********************************************************************
 * Main function 
 ************************************************************************/
int main() 
{
   char filename[256];
   int board[9][9];
   char coords[256];

   getFilename(filename);
   readFile(filename, board);
   interact(board);
   
   
}

