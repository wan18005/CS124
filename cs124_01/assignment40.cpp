/***********************************************************************
* Program:
*    Assignment 40, MULTI-DIMENSIONAL ARRAYS
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*   This program will compute the user grade to letter grade.
*
*    Estimated:  2 hrs   
*    Actual:     3 hrs
*   The most hard part is the display the grid and writting 
*   back to the file.
*   get idea from https://www.dreamincode.net/forums/topic/199265-tic-tac-toe-board/
*    https://www.daniweb.com/programming/software-development/threads/323955/tic-tac-toe-board
*    http://forums.codeguru.com/showthread.php?505045-Tic-Tac-Toe-Board
************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

/*****************************************************************
 * This function get the filename from the user.
 * **************************************************************/
void getFileName(char fileName[]) // read the filename
{
   cout << "Enter source filename: ";
   cin >> fileName;
}

/*****************************************************************
 * This function will read the file the check 
 * whether it is a 3 by 3 grid
 * **************************************************************/
bool readFile(char fileName[], char grid[3][3])
{

   ifstream fin(fileName);
   if(fin.fail())
   {
   cout << "ERROR" << endl;
    return false;
   }
   bool isGrid = true;                  
   //  create a bool state whether it is a grid or not
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         fin >> grid[row][col];          // fin grid[3][3]
    
    
   if (fin.fail())    // if not false
      isGrid = false;

   fin.close();   // close fin
   return true;
}

/*****************************************************************
 * This function will display the game board for the tic tac toe.
 * **************************************************************/
void display(char grid [3][3])
{
  
   for (int row = 0; row < 3; row++)    
   // for the row  
   {
      if (row != 0)                     
      // nothing on the game board for row1 , row 2, row3
         cout << "---+---+---" << endl;
      for (int col = 0; col < 3; col++)     
      // checking for column
      {
         if ((col == 0) && (grid[row][0] == '.'))    
         // if col is 1 and row 0 is a . print the boarder 
            cout << "   |";
         else if ((col == 0) && (grid[row][0] != '.')) 
         // if col and row 0 is not a . print  middle boarder
            cout << ' ' << grid[row][0] << " |";
         else if ((col == 1) && grid[row][1] == '.')   
         // if col is 1 and row 1 is a . print the side boarder 
            cout << "   |";
         else if ((col == 1) && grid[row][1] != '.') 
         // if col is 1 and row 1 is not a . print the middle boarder 
            cout << ' ' << grid[row][1] << " |";
         else if ((col == 2) && grid[row][2] == '.')  
         // if col is 2 and row 2 is a . print the next line 
            cout << "   \n";
         else if ((col == 2) && grid[row][2] != '.')
         // if col is 2 and row 2 is not a . print the next line 
            cout << ' ' << grid[row][2] << " \n";
      }
       
   }
  
   return;
}

/*****************************************************************
 * This function will write back to the file.
 * **************************************************************/
bool writeFile(char newFile[], char grid[3][3])
{
   ofstream fout(newFile);        // a new file
   if (fout.fail())               // if fail return false
      return false;                

 
   for (int row = 0; row < 3; row++)      // row ++
   {   
      for (int col = 0; col < 3; col++)  // col ++
      {
         if ((col == 0) && (grid[row][0]))     
         // both 0  fout a space @ row 0
            fout << grid[row][0] << ' ';
         else if 
            ((col == 1) && (grid[row][1])) 
            // both 1  fout a space @ row 1
               fout << grid[row][1] << ' ';
         else 
            fout << grid[row][2] << endl;    
            // otherwise just write on row 2
      }
   }   

   fout.close();  // close

   return true;  //return true for writefile success!
}

/*****************************************************************
 * This function will recall all the other function 
 * and prompt user that this file is written or not. 
 * **************************************************************/
int main() 
{
   char fileName[256];  //declare fileName
   getFileName(fileName);  // get the file
   char grid[3][3];     // declare grid as 3*3

   readFile(fileName, grid);     // open readFile function
   display(grid);           // open displayGrid function
  
   char newFile[256];           // declare for the new file
   cout << "Enter destination filename: ";   
   // prompt for the filename address
   cin >> newFile;     // key in the newFile
   cout << "File written" << endl;  // prompt it is written
 

   writeFile(newFile,grid);   // open writeFile function

   return 0;
}