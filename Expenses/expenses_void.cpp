#include <iostream>

using namespace std;

 /* USE GLOBAL VARIABLES 
  Declare variables for previous and current month's expenses 
  Declare an array with 'double' datatype for storing expenses */
double LastMonth, CurrentMonth, Expenses[5];

/* Function for calculating the expenses per month, accepts two parameters 
    and returns the total value for that month */
double ExpensesCalc(double PassedMonth, string month){
    for (int i = 0; i < 5; i++){
        switch (i){
            case 0:
                cout << "Enter " << month << " expenses for Water: " << endl;
                break;
            case 1:
                cout << "Enter " << month << " expenses for Electricity: " << endl;
                break;
            case 2:
                cout << "Enter " << month << " expenses for Food: " << endl;
                break;
            case 3:
                cout << "Enter " << month << " expenses for Internet: " << endl;
                break;
            case 4:
                cout << "Enter " << month << " expenses for Other Expenses: " << endl;
                break;
            }
        cin >> Expenses[i];
        PassedMonth += Expenses[i];
    }
    return PassedMonth;
}

int main() {
    /* Use a loop for getting the total expenses with the help of the function
    above, and store them on the proper variable*/
    for (int i = 0; i < 2; i++){
        switch (i){
            case 0:
                LastMonth = ExpensesCalc(LastMonth, "last month's");
                break;
            case 1:
                CurrentMonth = ExpensesCalc(CurrentMonth, "current month's");
                break;
        }
    }

    // Print last output on the screen and determine the difference for the two months
   if (CurrentMonth > LastMonth){
       cout << "We overspent with the amount of: ₱" << (CurrentMonth - LastMonth);
   } else if (CurrentMonth < LastMonth){
       cout << "Our Family save for as much as: ₱ " << (LastMonth - CurrentMonth) << " Good JOB!";
   }
}
