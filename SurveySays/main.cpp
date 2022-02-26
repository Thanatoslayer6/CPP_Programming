#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

string ListName, Options[6];
double Votes[7]; // Last index of votes is sum

double getPercentage(double d){
    return ((d/Votes[6])  * 100);
}

void getPossibleOptions(string *op) { // Pass by reference a string array
    for (int i = 0; i < 6; i++) {
        if (i == 5) { // Last loop we just assign it to "Others/Undecided"
            op[i] = "Others/Undecided";
            cout << "Choice #6: Others/Undecided" << endl;
        } else {
            cout << "Enter Choice #" << i + 1 << ": ";
            getline(cin, op[i]);
        }
    }
}

void getNumberOfVotes(double *v) {
    for (int i = 0; i < 6; i++) {
        cout << "Number of votes for " << Options[i] << ": ";
        cin >> v[i];
        v[6] += v[i]; // Store total of all frequencies in last index
    }
}

void finalOutput() {
    string temp[5];
    cout << "\n   /-----------------------\\" << endl;
    cout << "   |      Survey Says      |" << endl;
    cout << "   \\-----------------------/" << endl;
    cout << "     Top 5 " << ListName << endl;
    cout << "    ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "     Total or (n) is: " << Votes[6] << endl;
    cout << "    ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int i = 0; i < 5; i++) { // We don't include "Others/Undecided"
        cout << "\t" << Options[i] << " - " << fixed << setprecision(0) << getPercentage(Votes[i]) << "%" << endl;
    }
    cout << "    ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

double *sort(double ar[], int size){
    for (int i = 0; i < size; i++){
        for (int k = i + 1; k < size - 1; k++) {
            if (ar[i] > ar[k]) {
                 
            }
        }
    }
    return ar;
}

int main() {
    cout << "Enter the name of the list: ";
    getline(cin, ListName);
    getPossibleOptions(Options); // pass the string array and store the options
    getNumberOfVotes(Votes);
    finalOutput();
}
