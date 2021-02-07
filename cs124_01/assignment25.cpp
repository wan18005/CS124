#include <iostream>
#include <iomanip>
using namespace std;

int getDays()
{
    int days;
    cout << "Number of days: ";
    cin >> days;
    return days;
}

int getOffSet()
{
    int offset;
    cout << "Offset: ";
    cin >> offset;
    return offset;
}

 void displayTable(int offset, int numDays)
{
    //headings
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

  


   // Determine the day of the week.
   int dayOfWeek = (offset + 1) % 7;

   // space  between each number 
   for (int i = 0; i <= dayOfWeek; i++)
   {
      cout << "" << setw(4);
   }

   // Display the first days to the last of  the month.
   for (int dayOfMonth = 1; dayOfMonth <= numDays; dayOfMonth++)
   {
      cout << setw(4) << dayOfMonth;

      dayOfWeek++;

      if (dayOfWeek % 7 == 0)
         cout << endl;
   }

   // End of the month
   if (dayOfWeek % 7 != 0)
      cout << endl;
}

int main()
{
int numDays = getDays();
int offset = getOffSet();
displayTable(offset,numDays);
return 0;
}