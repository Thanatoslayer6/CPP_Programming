#include <iostream>
#include <string.h>
using namespace std;

string ListName, Options[6];
int Votes[7]; // Last index of votes is sum

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

void getNumberOfVotes(int *v) {
    for (int i = 0; i < 6; i++) {
        cout << "Number of votes for " << Options[i] << ": ";
        cin >> v[i];
        v[6] += v[i]; // Store total of all frequencies in last index
    }
}

int main() {
    cout << "Enter the name of the list: ";
    getline(cin, ListName);
    getPossibleOptions(Options); // pass the string array and store the options
    getNumberOfVotes(Votes);
    
    /* cout << "TOP 5: " << ListName << endl; */
    /* cout << "Total is " << Votes[6] << endl; */
    /* for (int i = 0; i < 5; i++) { // We don't include "Others/Undecided" */
    /*     cout << Options[i] << " has " << Votes[i] << " votes" << endl; */
    /* } */
}
