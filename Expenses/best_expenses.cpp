#include "iostream"

using namespace std;

int main(){
    double TotalExpenses[2], Expenses[5];
    string TypesOfExpenses[5] = {"Water", "Electricity", "Internet", "Food", "Other Expenses" }, Month[2] = { "last", "current" };
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            cout << "Enter " << Month[i] << " month's expenses for " << TypesOfExpenses[j] << ": ";
            cin >> Expenses[j];
            TotalExpenses[i] += Expenses[j];
        }
    }
    if (TotalExpenses[1] - TotalExpenses[0] > 0){
        cout << "You overspent money this month: PHP " << TotalExpenses[1] - TotalExpenses[0];
    } else if (TotalExpenses[1] - TotalExpenses[0] < 0){
        cout << "You saved money this month: PHP " << TotalExpenses[0] - TotalExpenses[1] << " Good Job!";
    } else {
        cout << "No difference in terms of last and current month: PHP " << TotalExpenses[1] - TotalExpenses[0] << " Good Job!";
    }
}
