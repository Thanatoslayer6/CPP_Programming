#include <iostream>

using namespace std;

int main() {
//Declare variables for previous and current month's expenses and an array with datatype 'double' and size 5 for storing expenses
double LastMonth, CurrentMonth, Expenses[5];
// Use a 'for loop' for looping twice
    for (int i = 1; i <= 2; i++){
        switch (i){
            case 1: // Ask the user for all of the expenses last month, start at zero because arrays have zero based indexes
                for (int j = 0; j < 5; j++){ // loop starts with 0 until 4, also use different name for iterator 'j' not 'i' to make it look good
                    if (j == 0)
                        cout << "Enter last month's expenses for 'Water': " << endl;
                    else if (j == 1)
                        cout << "Enter last month's expenses for 'Electricity': " << endl;
                    else if (j == 2)
                        cout << "Enter last month's expenses for 'Food': " << endl;
                    else if (j == 3)
                        cout << "Enter last month's expenses for 'Internet': " << endl;
                    else
                        cout << "Enter last month's expenses for 'Other Expenses': " << endl;
                    cin >> Expenses[j]; // get standard input using cin for every loop
                    LastMonth += Expenses[j]; // increment that inputted value to lastmonth, repeat until loop not done
                    }
                break;
            case 2: // Again ask user for expenses, this time the current month
                for (int j = 0; j < 5; j++){
                    if (j == 0)
                        cout << "Enter current month's expenses for 'Water': " << endl;
                    else if (j == 1)
                        cout << "Enter current month's expenses for 'Electricity': " << endl;
                    else if (j == 2)
                        cout << "Enter current month's expenses for 'Food': " << endl;
                    else if (j == 3)
                        cout << "Enter current month's expenses for 'Internet': " << endl;
                    else
                        cout << "Enter current month's expenses for 'Other Expenses': " << endl;
                    cin >> Expenses[j];
                    CurrentMonth += Expenses[j];
                    }
                break;
        }
    }
   
    // Print output on the screen and determine the difference
   if (CurrentMonth > LastMonth){ // if current month exceeds expenses of last month it means we overspent...
       cout << "We overspent with the amount of: ₱" << (CurrentMonth - LastMonth); // currentmonth - lastmonth gets us a positive value
   } else if (CurrentMonth < LastMonth){ // if current month is lesser than last month it means we saved money
       cout << "Our Family save for as much as: ₱ " << (LastMonth - CurrentMonth) << " Good JOB!";
   } else {
       cout << "Nothing changed";
   }
   return 0;
}
