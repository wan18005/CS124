#include <iostream>
#include <iomanip>
using namespace std;

// block 1
float promptDevalue(int cost){
return 0;
}

float promptInsurance(int cost){
return 0;
}

float promptParking(int cost){
return 0;
}
int getPeriodicCost(int cost){
 promptDevalue(cost);
 promptInsurance(cost);
 promptParking(cost);
return 0;
}

// block 2
float promptMileage(int mileage){
return 0;
}

float promptGas(int cost){
return 0;
}

float promptRepairs(int cost){
return 0;
}

float promptTires(int cost){
return 0;
}

float getUsageCost(int cost ,int mileage){
   promptMileage(mileage);
   promptGas(cost);
   promptRepairs(cost);
   promptTires(cost);
   return 0;
}
// display part
void display (int costUsage, int costPeriodic){
cout << "Success\n";
}


// main part
int main(){
float costUsage;
float costPeriodic;
display(costUsage,costPeriodic);
return 0;
}