/*********************************************************
* Program:     
*    Test 1,
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
*   Test 14 , This program will convert dollar into Euro 
*   for Sue.
***************************************************************/
#include <iostream>
using namespace std;


double inputDollar(){
double dollar;
cout << "Please enter the amount in US Dollars: $";
cin >> dollar;
return dollar;
}


void displayP(){

cout << "\t" << "Euros: " << endl;

return;
}
void displayN(){
cout << "\t" << "Euros: " << endl;
return;
}

bool PorN(float eu){

return eu;
}

int main(){
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
double Dollar;
double e;
float dollar;
Dollar = inputDollar();
e = Dollar / 1.41;

if ((e >= 0 ))
cout << "\t" << "Euros: " << e << endl;

else 
cout << "\t" << "Euros: " << " (" << e << ")" << endl;

return 0;
}



