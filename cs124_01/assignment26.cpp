/***********************************************************************
* Program:
*    Assignment 26, Files     
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*   This program will read 10 grades from a file and display the average. 
*
*    Estimated:  2 hrs   
*    Actual:     6 hrs
*   I use the book's method it always shows the output 
*   when there are more then 10 files, so I use a bool and reference 
*   it in the readFile function, then the percentage display 
*   was all wired when I set precision to 0, 
*   but when I switch to 2 it is normal.
*
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;




void getFileName(char fileName[])
{
  
  cout << "Please enter the filename: ";
  cin >> fileName;
  
  return;
}

float readFile(char fileName[], bool &DisplayTheAverage)
{
  float data;
  float total = 0;
  int lengthOfFile = 10;
  int count = 0;
  ifstream fin(fileName);
   if (fin.fail())
   {
     cout << "Error reading file " << '"' << fileName << '"'<< endl;
     return 0;
   }
   
  // How many variables are in data. 
  while (fin >> data)
    {
      total += data;
      count++;
    }
  
  // Verify there are exactly 10 variable in file.   
  if (count != lengthOfFile)
  {
    cout << "Error reading file " << '"' << fileName << '"'<< endl;
    fin.close();
    DisplayTheAverage = false;
    return 0;
  }
  else 
  {
    total = total / lengthOfFile ; 
    fin.close();
    DisplayTheAverage = true;
    return total;
  }
}


void display(float total)
{ 
  cout.precision(2);
  cout << "Average Grade: " << total << "%" << endl;
  return;
}



int main()
{
  bool DisplayTheAverage;
  char fileName[256];
  getFileName(fileName);
  
  float total = readFile(fileName,DisplayTheAverage);
  if (DisplayTheAverage == true)
  {
      display(total);
  }
   return 0;
}