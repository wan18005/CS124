/***********************************************************************
* Program:
*    Test 4, copy string     
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

/*
 * Prototype Function.
 */
void stringCopy(char *destination, const char *source);
string getText();
void display(string source);


int main(int argc, char ** argv)
{
   char destination[256];
   char source[256];
   string text;
   //stringCopy(destination,source);
   if (argc == 1)
   {
      stringCopy(destination,source);
      if (destination == "Brigham Young Universitiy - Idaho")
      cout << "The string is: \"BYU - I\"" << endl;
   }
   else
   {
      text = getText();
   }
   display(text);
   return 0;


   return 0;
}

/*
 * Copies the input into the string and displays it.
 */
void stringCopy(char *destination, const char *source)
{
   char input[256];
   cout << "Please enter a string: ";
   cin.getline(input,256);
   destination = input;

   // input sting copy here;
   //atof(argv[source]) = atof(destination);

   cout << "The string is: \"" << destination << "\"" << endl;

}

string getText()
{
   string text;
   cout << "Please enter a string: ";
   cin >> text;
   return text;
}

void display(string text)
{
   cout << "The string is: \"";
   cout << text;
   cout << "\"" << endl;
}