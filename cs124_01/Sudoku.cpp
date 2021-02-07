#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

const int SIZE = 9;

bool checkBoard(int boardArray[][SIZE]);
void getBoard(char myBoard[]);
bool createArray(int boardArray[][SIZE], char myBoard[],
                 bool boardArrayRO[][SIZE]);
void drawBoard(int boardArray[][SIZE], bool boardArrayRO[][SIZE]);
void displayMenu();
bool isValid(char coords[]);
int promptNum(char coords[]);
bool checkEmpty(int boardArray[][SIZE], int row, int col);
bool getCoords (char coords[], int boardArray[][SIZE],
                bool boardArrayRO[][SIZE]);
void editArray(int boardArray[][SIZE], bool boardArrayRO[][SIZE]);
void getValues(int boardArray[][SIZE], char coords[], bool values[]);
void showOptions(int boardArray[][SIZE], bool boardArrayRO[][SIZE]);
bool saveAndQuit(int boardArray[][SIZE]);
void interact(int boardArray[][SIZE], bool boardArrayRO[][SIZE]);

/*
 * Stores arrays and calls other functions.
 */
int main()
{
   char myBoard[256];
   int boardArray[SIZE][SIZE];
   bool boardArrayRO[SIZE][SIZE];
   getBoard(myBoard);
   if (createArray(boardArray,myBoard,boardArrayRO))
   {
      return 0;
   }
   interact(boardArray,boardArrayRO);
   return 0;
}

/*
 * Checks if the board is valid or not.
 */
bool checkBoard(int boardArray[][SIZE])
{
   int row = 0;
   int col = 0;
   char coords[2];
   for (int loop = 0; loop < SIZE; loop++)
   {
      int numCol[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int numRow[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int numBox[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      for (int r = 0; r < 9; r++)
      {
         if (boardArray[r][col] != 0)
            numCol[boardArray[r][col]] += 1;
         if (numCol[boardArray[r][col]] > 1)
         {
            coords[1] = r + 48;
            coords[0] = col + 66;
            cout << "ERROR: Duplicate value '" << boardArray[r][col]
                 << "' in inside square represented by '"
                 << coords[0] << coords[1] << "'\n";
            return false;
         }
      }
      for (int c = 0; c < 9; c++)
      {
         if (boardArray[row][c] != 0)
            numRow[boardArray[row][c]] += 1;
         if (numRow[boardArray[row][c]] > 1)
         {
            coords[1] = row + 48;
            coords[0] = c + 66;
            cout << "ERROR: Duplicate value '" << boardArray[row][c]
                 << "' in inside square represented by '"
                 << coords[0] << coords[1] << "'\n";
            return false;
         }
      }
      int mRow = (row / 3) * 3;
      int mCol = (col / 3) * 3;
      for (int r = mRow; r < (mRow + 3); r++)
      {
         for (int c = mCol; c < (mCol + 3); c++)
         {
            if(boardArray[r][c] != 0)
               numBox[boardArray[r][c]] += 1;
            if (numBox[boardArray[r][c]] > 1)
            {
               coords[1] = r + 48;
               coords[0] = c + 66;
               cout << "ERROR: Duplicate value '" << boardArray[r][c]
                    << "' in inside square represented by '"
                    << coords[0] << coords[1] << "'\n";
               return false;
            }
         }
      }
      row++;
      col++;
   }
   return true;
}

/*
 * Just getting the board name from the user.
 */
void getBoard(char myBoard[])
{
   cout << "Where is your board located? ";
   cin.getline(myBoard, 256);
   return;
}

/*
 * Transfers data from the file into an array.
 */
bool createArray(int boardArray[][SIZE], char myBoard[],
                 bool boardArrayRO[][SIZE])
{
   bool validBoard = true;
   ifstream fin(myBoard);
   if (fin.fail())
   {
      cout << "Unable to open file " << myBoard << ".\n";
      return true;
   }
   // First loop parsing the rows.
   for (int row = 0; row < SIZE; row++)
   {
      // For each row we go through the columns inputting info
      // from the file to our array.
      for (int col = 0; col < SIZE; col++)
      {
         fin >> boardArray[row][col];
         if (boardArray[row][col] != 0)
            boardArrayRO[row][col] = true;
         else
            boardArrayRO[row][col] = false;
      }
   }
   fin.close();
   validBoard = checkBoard(boardArray);
   if (!validBoard)
      return true;
   return false;
}

/*
 * Stores arrays and calls other functions
 */
void drawBoard(int boardArray[][SIZE], bool boardArrayRO[][SIZE])
{
   cout << "   A B C D E F G H I\n";

   // First loop parsing the rows
   for (int row = 0; row < SIZE; row++)
   {
      cout << row + 1 << "  ";
      // For each row we go through the columns inputting info
      // from the array onto the screen matching the desired format.
      for (int col = 0; col < SIZE; col++)
      {
         // If the array value is 0 we want a blank space instead.
         if (boardArray[row][col] == 0)
            cout << " ";
         else
         {
            if (boardArrayRO[row][col])
               cout << "\E[22;32m" << boardArray[row][col] << "\E[0m";
            else
               cout << boardArray[row][col];
         }
         // Put a space between the columns except for the
         // the columns 3, 6, and 9.
         if ((col + 1) % 3 != 0)
            cout << " ";
            // The last column gets a new line.
         else if (col == (SIZE - 1))
            cout << endl;
            // The 3rd and 6th columns get pipe symbol.
         else
            cout << '|';
      }
      // 3rd and 6th rows get spacers after them.
      if (row == 2 || row == 5)
         cout << "   -----+-----+-----\n";
   }
   cout << "\n";
}

/*
 * Display the options menu
 */
void displayMenu()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n\n";
   return;
}

/*
 * Check for valid coordinate data.
 */
bool isValid(char coords[])
{
   // Make sure the letter is an alpha and the number is a digit
   if (isalpha(coords[0]) && isdigit(coords[1]))
   {
      // Letter needs to be between A and I.
      if (coords[0] >= 'A' && coords[0] <= 'I')
      {
         // Numbers 1 through 9 only
         if (coords[1] >= '1' && coords[1] <= '9')
         {
            return true;
         }
      }
   }
   return false;
}

/*
 * Prompt user for the number that will be put into the board array.
 */
int promptNum(char coords[])
{
   int inputNum;
   cout << "What is the value at '" << coords[0] << coords[1] << "': ";
   cin >> inputNum;
   // The number has to be between 1 and 9.
   if (inputNum < 1 || inputNum > SIZE)
   {
      cout << "ERROR: Value '" << inputNum << "' in square '"
           << coords[0] << coords[1] << "' is invalid\n\n";
      return 0;
   }
   return inputNum;
}

/*
 * Make sure the space is empty that they user wants to update.
 */
bool checkEmpty(int boardArray[][SIZE], int row, int col)
{
   if (boardArray[row][col] == 0)
      return true;
   else
      return false;
}

/*
 * Prompt user for the coords, making sure they are valid.
 */
bool getCoords (char coords[], int boardArray[][SIZE],
                bool boardArrayRO[][SIZE])
{
   int row = 0;
   int col = 0;
   char tempCoords[2];
   bool loop = true;
   do
   {
      cout << "What are the coordinates of the square: ";
      cin >> tempCoords[0] >> tempCoords[1];
      if (isalpha(tempCoords[1]))
      {
         coords[0] = tempCoords[1];
         coords[1] = tempCoords[0];
      }
      else
      {
         coords[0] = tempCoords[0];
         coords[1] = tempCoords[1];
      }
      // If lower case letter is entered convert to uppercase.
      if (islower(coords[0]))
         coords[0] = toupper(coords[0]);
      // Convert the user input to corresponding values of array.
      col = coords[0] - 65;
      row = coords[1] - 49;
      if (!isValid(coords))
      {
         cout << "ERROR: Square '" << tempCoords[0] << tempCoords[1]
              << "' is invalid\n";
      }
      else if (!checkEmpty(boardArray,row,col) && boardArrayRO[row][col])
      {
         cout << "ERROR: Square '"
              << coords[0] << coords[1] << "' is read-only\n\n";
         return false;
      }
      else
         loop = false;
   }
   while (loop);
   return true;
}

/*
 * Edits a location in the array per user request.
 */
void editArray(int boardArray[][SIZE], bool boardArrayRO[][SIZE])
{
   bool values[10];
   char coords[2];
   int inputNum;
   int col;
   int row;
   if (getCoords(coords,boardArray,boardArrayRO))
   {
      // Convert the user input to corresponding values of array.
      col = coords[0] - 65;
      row = coords[1] - 49;
      // Get new number from the user.
      inputNum = promptNum(coords);
      if (inputNum != 0)
      {
         // Make sure the number is available for use
         getValues(boardArray,coords,values);
         if (values[inputNum])
         {
            boardArray[row][col] = inputNum;
            cout << endl;
            return;
         }
         else
         {
            cout << "ERROR: Value '" << inputNum
                 << "' in square '" << coords[0] << coords[1]
                 << "' is invalid\n\n";
            return;
         }
      }
      else
         return;
   }
}

/*
 * This will have a function to show available option for a user
 * designated coords.
 */
void getValues(int boardArray[][SIZE], char coords[], bool values[])
{
   // convert char coords to int col and row
   int numCol = coords[0] - 'A';
   int numRow = coords[1] - '1';
   // set all values to true to start
   for (int iTrue = 1; iTrue < 10; iTrue++)
   {
      values[iTrue] = true;
   }
   // loop through the row and set any number already used to false
   for (int r = 0; r < 9; r++)
   {
      if (r != numRow)
         values[ boardArray[r][numCol] ] = false;
   }
   // loop through the row and set any number already used to false
   for (int c = 0; c < 9; c++)
   {
      if (c != numCol)
         values[ boardArray[numRow][c] ] = false;
   }
   // this will get us to the segment to set those numbers to false
   int mRow = (numRow / 3) * 3;
   int mCol = (numCol / 3) * 3;
   for (int r = mRow; r < (mRow + 3); r++)
   {
      for (int c = mCol; c < (mCol + 3);c++)
      {
         if (r != numCol || c != numRow)
            values[boardArray[r][c]] = false;
      }
   }
}

/*
 * This will have a function to show available option for a user
 * designated coords.
 */
void showOptions(int boardArray[][SIZE], bool boardArrayRO[][SIZE])
{
   bool values[10];
   char coords[2];
   if (getCoords(coords,boardArray,boardArrayRO))
   {
      int numCol = coords[0] - 'A';
      int numRow = coords[1] - '1';
      getValues(boardArray,coords,values);
      if (checkEmpty(boardArray,numRow,numCol))
      {
         cout << "The possible values for '"
              << coords[0] << coords[1]
              << "' are: ";
         int iTrue = 0;
         for (int iCount = 1; iCount <= 9; iCount++)
         {
            if (values[iCount])
               // increment up for each true value
               iTrue += 1;
         }
         for (int iValues =1; iValues <= 9; iValues++)
         {
            // if it is true display the result
            if (values[iValues])
            {
               cout << iValues;
               iTrue -= 1;
               if (iTrue > 0)
                  cout << ", ";
               else
                  // the last one gets new line instead of comma space
                  cout << endl;
            }
         }
         cout << "\n";
      }
      else
         cout << "It is filled\n";
   }
   else if (!getCoords(coords,boardArray,boardArrayRO))
   {
      cout << "Error!\n";
   }
   return;
}

/*
 * Saves then return the quit command
 */
bool saveAndQuit(int boardArray[][SIZE])
{
   char myBoard[256];
   cout << "What file would you like to write your board to: ";
   cin >> myBoard;
   ofstream fout(myBoard);
   // Check for issues opening file.
   if (fout.fail())
   {
      cout << "Unable to open file " << myBoard
           << "." << endl;
      return false;
   }
   // First loop parsing the rows
   for (int row = 0; row < SIZE; row++)
   {
      // For each row we go through the columns input info
      // from our array to the file.
      for (int col = 0; col < SIZE; col++)
      {
         if (col != (SIZE - 1))
            fout << boardArray[row][col] << " ";
         else
            fout << boardArray[row][col] << endl;
      }
   }
   cout << "Board written successfully\n";
   fout.close();
   return false;
}

/*
 * Handles the interactions from the user, calling the appropriate
 * function depending on the users input.
 */
void interact(int boardArray[][SIZE], bool boardArrayRO[][SIZE])
{
   char userInput;
   bool stayInLoop = true;
   displayMenu();
   drawBoard(boardArray,boardArrayRO);
   do
   {
      cout << "> ";
      cin >> userInput;
      switch (userInput)
      {
         case '?':
            displayMenu();
            cout << endl;
            break;
         case 'D':
         case 'd':
            drawBoard(boardArray,boardArrayRO);
            break;
         case 'E':
         case 'e':
            editArray(boardArray,boardArrayRO);
            break;
         case 'S':
         case 's':
            showOptions(boardArray,boardArrayRO);
            break;
         case 'Q':
         case 'q':
            stayInLoop = saveAndQuit(boardArray);
            break;
         default:
            cout << "ERROR: Invalid command\n\n";
      }
   }
   while (stayInLoop);
   return;
}
