

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Get the name of the file where your board is located
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin  >> fileName;
}

/**********************************************************************
 * Displays the options the user has in order to play the game
 ***********************************************************************/
void displayOptions()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n"
        << "   Z  Solve the board\n"
        << endl;
}

/**********************************************************************
 * Opens the file where the board is and reads it into the program
 ***********************************************************************/
bool readBoard(int board[][9], char fileName[])
{
   ifstream fin(fileName);

   // If the file can't be opened
   if (fin.fail())
   {
      cout << "Cannot write board from file";
      return false;
   }

   // Read the contents of the file to the board array
   for
      (int row = 0; row < 9; row++)
   {
      for (int column = 0; column < 9; column++)
      {
         fin >> board[row][column];
      }

      // If the contents can't be read into the array
      if (fin.fail())
      {
         cout << "Issue putting values into array board";
         return false;
      }
   }

   // Close the file
   fin.close();
   
   return true;
}

/**********************************************************************
 * Saves the progress you've made on the board to a file
 ***********************************************************************/
bool saveBoard(int board[][9])
{
   char destinationFile[256];

   ofstream fout;

   // Prompt user for name of the file to save board to
   cout << "What file would you like to write your board to: ";
   cin  >> destinationFile;

   // Open the file
   fout.open(destinationFile);

   // Dispay message if file could not be opened
   if (fout.fail())
   {
      cout << "could not save file";
      return false;
   }

   // Write board to file
   for (int row = 0; row < 9; row++)
   {
      for (int column = 0; column < 9; column++)
      {
         if (column == 8)
            fout << board[row][column] << endl;
         else
            fout << board[row][column] << " "; 
      }
   }

   // Close file and display message of success
   fout.close();
   cout << "Board written successfully\n";
   return true;

}

/**********************************************************************
 * Get the coordinates of the square the user wants
 ***********************************************************************/
bool getCoordinates(int board[][9], int *r, int *c, char coordinates[])
{
   // Prompt user for coordinates
   cout << "What are the coordinates of the square: ";
   cin  >> coordinates;

 
   if (coordinates[0] >= 'A' && coordinates[0] <= 'I')
      *c = coordinates[0] - 'A';
   else if (coordinates[0] >= 'a' && coordinates[0] <= 'i')
      *c = coordinates[0] - 'a';
   else if (coordinates[0] >= '1' && coordinates [0] <= '9' &&
            coordinates[1] >= 'A' && coordinates[1] <= 'I')
      *c = coordinates[1] - 'A';
   else if (coordinates[0] >= '1' && coordinates [0] <= '9' &&
            coordinates[1] >= 'a' && coordinates[1] <= 'i')
      *c = coordinates[1] - 'a';
   else
   {
      cout << "Square " << coordinates[0] << coordinates[1]
           << " is invalid\n";
      return false;
   }
   
   if (coordinates[1] >= '1' && coordinates[1] <= '9')
       *r = coordinates[1] - '1';    
   else if (coordinates[0] >= '1' && coordinates [0] <= '9' &&
            coordinates[1] >= 'A' && coordinates[1] <= 'I')
      *r = coordinates[0] - '1';
   else if (coordinates[0] >= '1' && coordinates [0] <= '9' &&
            coordinates[1] >= 'a' && coordinates[1] <= 'i')
      *r = coordinates[0] - '1';
   else
   {
      cout << "Square " << coordinates[0] << coordinates[1]
           << " is invalid\n";
      return false;
   }
   
   if (board[*r][*c] != 0)
   {
      cout << "ERROR: Square '" << coordinates[0] << coordinates[1]
           << "' is filled\n";
      return false;
   }

   return true;
}

/**********************************************************************
 * The rules of sudoku are kept here, no number of the same value can
 * be on the same row, column, or square
 ***********************************************************************/
void computeValues(int possibles[], int board[][9], int *r, int *c)
{
   for (int i = 0; i <= 9; i++)
       possibles[i] = true;

   // Go through the column
   for (int iRow = 0; iRow <= 8; iRow++)
      possibles[board[iRow][*c]] = false;

   // Go through the row
   for (int iCol = 0; iCol <= 8; iCol++)
      possibles[board[*r][iCol]] = false;

   // Go through the square
   for (int iRow = 0; iRow <= 2; iRow++)
      for (int iCol = 0; iCol <= 2; iCol++)
         possibles[board[*r / 3 * 3 + iRow][*c / 3 * 3 + iCol]] = false;
}

/**********************************************************************
 * Figure out which numbers are possiblities for a given square
 ***********************************************************************/
void displayPossible(int board[][9], char coordinates[])
{
   int row;
   int column;
   int *r = &row;
   int *c = &column;
   int possibles[10];
   bool first = true;

   // get the coordinates of the desired square
   getCoordinates(board, r, c, coordinates);

   // Follow the rules
   computeValues(possibles, board, r, c);

   // Display the possible numbers
   cout << "The possible values for '"
        << coordinates[0] << coordinates[1]
        << "' are: ";
   
   for (int i = 1; i <= 9; i++)
   {
      if (possibles[i] == true)
      {
         if (!first)
            cout << ", ";
         cout << i;
         first = false;
      }
   }
   cout << endl;
}

/**********************************************************************
 * The user must be able to edit a square, be careful once edited you
 * cannot change it! D:
 ***********************************************************************/
int editSquare(int board[][9], char coordinates[])
{
   int row;
   int column;
   int *r = &row;
   int *c = &column;
   int possibles[10];
   int input;
   int testValues = 0;   
   bool validSquare = getCoordinates(board, r, c, coordinates);

   // If the square isn't valid don't continue
   if (validSquare == false)
      return 1;

   // Follow the rules
   computeValues(possibles, board, r, c);

   // Prompt user for the edit
   cout << "What is the value at '"
        << coordinates[0] << coordinates[1]
        << "': ";
   cin  >> input;

   // Make sure the number is even a possibility
   for (int i = 0; i < 9; i++)
   {
      if (possibles[input] == 1)
          testValues++;
   }
   
   if (testValues == 0)
      cout << "ERROR: Value '"
           << input
           << "' in square '"
           << coordinates[0] << coordinates[1]
           << "' is invalid\n";
   else
      board[*r][*c] = input;
}

/**********************************************************************
 * Displays the sudoku board
 ***********************************************************************/
void displayBoard(int board[][9])
{
   // Header for columns
   cout << "   A B C D E F G H I\n";

   // Go through the rows
   for (int row = 0; row < 9; row++)
   {
      cout << row + 1 <<  "  ";
      // go through the columns
      for (int column = 0; column < 9; column++)
      {
         if (board[row][column] != 0)
           cout << board[row][column];
         else cout << " ";
         if (column % 3 == 2 && column != 8)
            cout << "|";
         else if (column == 8)
            cout << (row  % 3 == 2 && row != 8 ?
                     "\n   -----+-----+-----\n" : "\n");
         else
            cout << " ";
      }
   }
}

/**********************************************************************
 * Main should be called "caller" all he does is call other functions
 ***********************************************************************/
void solver(int board[][9])
{
   int possibles[10];
   int numPoss = 0;
   int answer;
   int passAgain;

   do
   {
      // go through the rows
      for (int row = 0; row < 9; row++)
      {
         passAgain = 0;
         int *r = &row;
         
         // go through the columns
         for (int column = 0; column < 9; column++)
         {
            int *c = &column;
            computeValues(possibles, board, r, c);
            numPoss = 0; 
            
            // check possible values
            for (int i = 1; i <= 9; i ++)
            {
               if (possibles[i] == true)
               {
                  numPoss++;
                  answer = i;
               }
            }

            // if there's only one possible answer and that's
            // an empty square fill it
            if (numPoss == 1 && board[*r][*c] == 0)
            {
               board[*r][*c] = answer;
               passAgain++;
            }
         }
      }
   }

   // Continue checking until all squares are filled
   while (passAgain > 0);
}

/**********************************************************************
 * As long as the game is running prompt the user for input
 ***********************************************************************/
int interact(int board[][9])
{
   int row;
   int column;
   int *r = &row;
   int *c = &column;
   char coordinates[2];
   char input;

   // Prompt user as long Q isn't entered
   do
   {
      cout << endl << "> ";
      cin >> input;

      switch (input)
      {
         case '?':
            displayOptions();
            break;
         case 'D':
            displayBoard(board);
            break;
         case 'd':
            displayBoard(board);
            break;
         case 'E':
            editSquare(board, coordinates);
            break;
         case 'e':
            editSquare(board, coordinates);
            break;
         case 'S':
            displayPossible(board, coordinates);
            break;
         case 's':
            displayPossible(board, coordinates);
            break;
         case 'Z':
            solver(board);
            break;
      }
      
      if (input != '?' && input != 'D' && input != 'd' && input != 'E' &&
          input != 'e' && input != 'S' && input != 's' && input != 'Q' &&
          input != 'q' && input != 'Z')
         cout << "ERROR: Invalid command\n";
   }
   while (input != 'Q' && input != 'q');
   
   saveBoard(board);
      
   return 0;
}

/**********************************************************************
 * Main should be called "caller" all he does is call other functions
 ***********************************************************************/
int main(int argc, char **argv)
{
   char fileName[256];

   int board[9][9];
   
   getFileName(fileName);

   readBoard(board, fileName);

   displayOptions();

   displayBoard(board);

   interact(board);
   
   return 0;
}