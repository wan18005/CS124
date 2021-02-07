#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

//display the colmns of numbers
cout << "\tItem" << setw(20) << "Projected" << endl; 
cout << "\t=============" << setw(12) << "==========" << endl;
cout << "\tIncome" << setw(10) << "$" << setw(9) << 1000.00 << endl;
cout << "\tTaxes" << setw(11) << "$" << setw(9) << 100.00 << endl;
cout << "\tTithing" << setw(9) << "$" << setw(9) << 100.00 << endl;
cout << "\tLiving" << setw(10) << "$" << setw(9) << 650.00 << endl;
cout << "\tOther" << setw(11) << "$" << setw(9) << 90.00 << endl;
cout << "\t=============" << setw(12) << "==========" << endl;
cout << "\tDelta" <<setw (11) << "$" << setw(9) << 60.00 <<endl;
return 0;
}
 