/***********************************************************************
* Program:
*    Project 13, Sudoku with Sudoku solver commented       
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*    This program will read a file for a sudoku game 
*    and allow user to the play the game according to the rule
*    with some help.
*
*    Estimated:  8.0 hrs   
*    Actual:     10.0 hrs
*    The solver and extra credit is the most hard part for this program
************************************************************************/


#include <iostream>
#include <fstream>
using namespace std;
const int SIZE = 9;

int editSquare(int board[][SIZE], char coords[]);
int interact(int board[][SIZE]);
void getFileName(char fileName[]);
void displayOptions();
void displayBoard(int board[][SIZE]);
void computeValues(int solution[], int board[][SIZE], int *r, int *c);
void displayPossible(int board[][SIZE], char coords[]);
void sudokuSolver(int board[][SIZE]);
bool readFile(int board[][SIZE], char fileName[]);
bool writeFile(int board[][SIZE]);
bool getCoords(int board[][SIZE], int *r, int *c, char coords[]);


/**********************************************************************
 * Main
 ***********************************************************************/
int main()
{
   char fileName[256];

   int board[SIZE][SIZE];
   
   getFileName(fileName);

   readFile(board, fileName);

   interact(board);
   
   return 0;
}

/**********************************************************************
 * interact with the player 
 ***********************************************************************/
int interact(int board[][SIZE])
{
   char displayOption;
   char coords[256];
   displayOptions();
   displayBoard(board);

   // Prompt user as long Q isn't entered
   do
   {
      cout << "\n> ";
      cin >> displayOption;

      switch (displayOption)
      {
         case '?':  // if input is ?
            displayOptions();
            break;
         case 'D': // if input is d or D
         case 'd':
            displayBoard(board);
            break;
         case 'E':// if input is e or E
         case 'e':
            editSquare(board, coords);
            break;
         case 'S':// if input is s or S
         case 's':
            displayPossible(board, coords);
            break;
         case 'A':// if input is a or A
         case 'a':
            sudokuSolver(board);
            break;
      }
      if (toupper(displayOption) != '?' && toupper(displayOption) != 'D' 
         && toupper(displayOption) != 'E'
         && toupper(displayOption) != 'S' && toupper(displayOption) != 'Q' 
         && toupper(displayOption) != 'A')
         cout << "ERROR: Invalid command\n";
   }
   while (toupper(displayOption) != 'Q');
   
   writeFile(board);
   return 0;
}

/**********************************************************************
 * Get the name of the board
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin  >> fileName;
}

/**********************************************************************
 * Displays the options to the user
 ***********************************************************************/
void displayOptions()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n"
        //<< "   A  Sudoku Solver Answer\n"    // sudoku solver for 85% 
        << endl;
}

/**********************************************************************
 * Displays the sudoku board
 ***********************************************************************/
void displayBoard(int board[][SIZE])
{
   // Board header
   cout << "   A B C D E F G H I\n";

   // Go through the rows
   for (int row = 0; row < SIZE; row++)
   {
      cout << row + 1 <<  "  ";
      // go through the col
      for (int col = 0; col < SIZE; col++)
      {
         if (board[row][col] == 0)   // both 0 empty space
            cout << " ";
         else
         {
            if (board[row][col])
               cout <<  board[row][col];
            else
               cout << board[row][col];
         }


         if (col % 3 == 2 && col != 8)   // line 
            cout << "|";
         else if (col == 8)
            cout << (row  % 3 == 2 && row != 8 ?
                     "\n   -----+-----+-----\n" : "\n");   // grid
         else
            cout << " ";
      }
   }
}

/**********************************************************************
 * Opens the board 
 ***********************************************************************/
bool readFile(int board[][SIZE], char fileName[])
{
   ifstream fin(fileName);

   // If the file can not be opened
   if (fin.fail())
   {
      return false;  //return false
   }

   else
   {
      for (int row = 0; row < SIZE; row++)
   
      {
         for (int col = 0; col < SIZE; col++)
         {
            fin >> board[row][col];
         }

      // If the contents can not be read into the array
         if (fin.fail())
         {
            return false;   // return false
         }
      }

   // Close the file
      fin.close();
   
      return true;
   }
}

/**********************************************************************
 * Saves the board to special location
 ***********************************************************************/
bool writeFile(int board[][SIZE])
{
   char finalDestination[256];
   // open 
   ofstream fout;
   // ask for location
   cout << "What file would you like to write your board to: ";
   cin  >> finalDestination;
   //open
   fout.open(finalDestination);
   //if fail
   if (fout.fail())
   {
      cout << "could not save file";
      return false;
   }
    // go over the array
   for (int row = 0; row < SIZE; row++)
   {
      for (int col = 0; col < SIZE; col++)
      {
         if (col == 8)  // the end finish
            fout << board[row][col] << endl;
         else // else put space
            fout << board[row][col] << " "; 
      }
   }
   //close
   fout.close();
   cout << "Board written successfully\n";
   return true;

}



/**********************************************************************
 * The rules of sudoku are kept here, no number of the same value can
 * be on the same row, column, or square
 ***********************************************************************/
void computeValues(int solution[], int board[][SIZE], int *r, int *c)
{
   for (int i = 0; i <= SIZE; i++)
      solution[i] = true;

   // for column
   for (int playerRow = 0; playerRow <= 8; playerRow++)
      solution[board[playerRow][* c]] = false;

   // for row
   for (int playerCol = 0; playerCol <= 8; playerCol++)
      solution[board[* r][playerCol]] = false;

   // for square
   for (int playerRow = 0; playerRow <= 2; playerRow++)
      for (int playerCol = 0; playerCol <= 2; playerCol++)
         solution[board[* r / 3 * 3 + playerRow]    
         // get the line for the location for the square
            [* c / 3 * 3 + playerCol]] = false;
}

/**********************************************************************
 * It will display all the possible number for that location
 ***********************************************************************/
void displayPossible(int board[][SIZE], char coords[])
{
   int row;
   int col;
   int *r = &row;
   int *c = &col;
   int solution[10];
   bool valid = true;

   // get the coordinates of the desired square
   getCoords(board, r, c, coords);

   // run the rule
   computeValues(solution, board, r, c);

   // Display the possible numbers
   cout << "The possible values for '"
        << coords[0] << coords[1]
        << "' are: ";
   // go through solution, otherwise false
   for (int i = 1; i <= SIZE; i++)
   {
      if (solution[i] == true)
      {
         if (!valid)
            cout << ", ";
         cout << i;
         valid = false;
      }
   }
   cout << endl;
}

/**********************************************************************
 * The user must be able to edit a square, be careful once edited you
 * cannot change it! D:
 ***********************************************************************/
int editSquare(int board[][SIZE], char coords[])
{
   int row;
   int column;
   int *r = &row;  // address to the int row
   int *c = &column; // address to the int col
   int solution[10];  // possible solution 0-9
   int location;
   int test = 0;   
   bool valid = getCoords(board, r, c, coords);

   // check whether it is value square or not
   if (valid == false)
      return 1;

   // Follow the rules
   computeValues(solution, board, r, c);

   // Prompt user for the edit
   cout << "What is the value at '"
        << coords[0] << coords[1]
        << "': ";
   cin  >> location;

   // Make sure the number is right for that square
   for (int i = 0; i < SIZE; i++)
   {
      if (solution[location] == 1)
         test++;
   }
   
   if (test == 0)
      cout << "ERROR: Value '" << location
           << "' in square '" << coords[0] << coords[1]
           << "' is invalid\n";
   else
      board[* r][* c] = location;
}

/**********************************************************************
 * Get the coordinates of the square the user wants
 ***********************************************************************/
bool getCoords(int board[][SIZE], int *r, int *c, char coords[])
{
   // Prompt user for coordinates
   cout << "What are the coordinates of the square: ";
   cin  >> coords;

 
   if (coords[0] >= 'A' && coords[0] <= 'I')  
   // if use input is between both the condition
      *c = coords[0] - 'A';                  
   // col is a 
   else if (coords[0] >= 'a' && coords[0] <= 'i') 
   // encase it is lower case
      *c = coords[0] - 'a';
    // col is a 
   else if (coords[0] >= '1' && coords [0] <= '9' &&
            coords[1] >= 'A' && coords[1] <= 'I')
   // encase it is between 1 and 9 and coords is between A and I 
      *c = coords[1] - 'A';
   // col is A 
   else if (coords[0] >= '1' && coords [0] <= '9' &&
            coords[1] >= 'a' && coords[1] <= 'i')
      *c = coords[1] - 'a';
   else
   {
      cout << "Square " << coords[0] << coords[1]
           << " is invalid\n";
      return false;
   }
   
   if (coords[1] >= '1' && coords[1] <= '9')
      *r = coords[1] - '1';    
   else if (coords[0] >= '1' && coords [0] <= '9' &&
            coords[1] >= 'A' && coords[1] <= 'I')
      *r = coords[0] - '1';
   else if (coords[0] >= '1' && coords [0] <= '9' &&
            coords[1] >= 'a' && coords[1] <= 'i')
      *r = coords[0] - '1';
   else
   {
      cout << "Square " << coords[0] << coords[1]
           << " is invalid\n";
      return false;
   }
   
   if (board[* r][* c] != 0)
   {
      cout << "ERROR: Square '" << coords[0] << coords[1]
           << "' is filled\n";
      return false;
   }

   return true;
}

/**********************************************************************
 * Solver function for the sudoku 85% version
 ***********************************************************************/
void sudokuSolver(int board[][SIZE])
{
   int solution[10]; // solution set 0-9
   int possibility;   
   int answer;
   int playAgain;

   do
   {
      // go through the rows
      for (int row = 0; row < SIZE; row++)
      {
         playAgain = 0;  // playAgain start at 0 
         int *r = &row;  // pointer r to row
         
         // go through the columns
         for (int col = 0; col < SIZE; col++)
         {
            int *c = &col;  // pointer c to col
            computeValues(solution, board, r, c);  // call compute
            possibility = 0; // possibility start at 0
            
            // check possible values
            for (int i = 1; i <= SIZE; i++ )   // try all the number
            {
               if (solution[i] == true)  // solution at I is true
               {
                  possibility++;       // go through all possibility
                  answer = i;          // final answer is i
               }
            }

            // if only one possibility for the answer
            // fill that square
            if (possibility == 1 && board[* r][* c] == 0)
            {
               board[* r][* c] = answer;
               playAgain++;  // keep going 
            }
         }
      }
   }

   // keep going until no more number exit out
   while (playAgain > 0);
}


