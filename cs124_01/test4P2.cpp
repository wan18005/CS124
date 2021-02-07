/***********************************************************************
* Program:
*    Test 4, Count lines
*    Brother Clement, CS124
* Author:
*    Yiqi Wang
* Summary: 
*    Count the number of lines in a file
************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string getFilename();
int    countLines(string filename);
void   display(int count, string filename);

string getFilename()
{
   string filename;
   cout << "Please enter the file name: ";
   cin  >> filename;
   return filename;
}

int countLines(string filename)
{
   // open the file
   ifstream fin(filename.c_str());

   // check for errors
   if (fin.fail())
      return 0;

   // read the file one line at a time
   // if I read a line, add one to count
   string line;
   int count = 0;
   while (getline(fin, line))
      count++;
   
   // close the file and return the answer
   fin.close();
   return count;
}




void display(int count, string filename)
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


int main(int argc, char ** argv)
{
   // get the filename either from argv or from a prompt
   string filename;
   if (argc == 2)
      filename = argv[1];
   else
      filename = getFilename();
   
   // read the file and return the number of lines
   int count = countLines(filename);

   // display the result
   display(count, filename);
   
   return 0;
}