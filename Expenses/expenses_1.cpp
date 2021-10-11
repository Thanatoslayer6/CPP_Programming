#include "iostream"

using namespace std;

int main(){
    double TotalLastMonth, TotalCurrentMonth, Expenses[5];
    string TypesOfExpenses[5] = {
        "Water", "Electricity", "Food", "Internet", "Other Expenses"
    };
    
    for(int i=1; i<=2; i++){
        if (i == 1) {
            for(int j=0; j < 5; j++){
                cout << "Enter last month's expenses for " << TypesOfExpenses[j] << ": ";
                cin >> Expenses[j];
                TotalLastMonth += Expenses[j];
            }
        } else if (i == 2){
            for(int j=0; j < 5; j++){
                cout << "Enter current month's expenses for " << TypesOfExpenses[j] << ": ";
                cin >> Expenses[j];
                TotalCurrentMonth += Expenses[j];
            }
        }
    }
    if (TotalCurrentMonth > TotalLastMonth){
       cout << "We overspent with the amount of: ₱" << (TotalCurrentMonth - TotalLastMonth); // currentmonth - lastmonth gets us a positive value
    } else if (TotalCurrentMonth < TotalLastMonth){
       cout << "Our Family save for as much as: ₱ " << (TotalLastMonth - TotalCurrentMonth) << " Good JOB!";
    } else {
        cout << "No difference in expenses ;)";
    }
}
