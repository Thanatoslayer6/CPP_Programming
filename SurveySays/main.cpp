#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

string ListName, Options[6];
int totalFrequency;
double Votes[6];

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

void getNumberOfVotes(double *v, int *total) {
    for (int i = 0; i < 6; i++) {
        cout << "Number of votes for " << Options[i] << ": ";
        cin >> v[i];
        *total += v[i]; // Store total of all frequencies in last index
    }
}

void finalOutput() {
    cout << "\n   /-----------------------\\" << endl;
    cout << "   |      Survey Says      |" << endl;
    cout << "   \\-----------------------/" << endl;
    cout << "     Results for " << ListName << endl;
    cout << "    ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "     Total or (n) is: " << totalFrequency << endl;
    cout << "    ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int i = 0; i < 5; i++) { // We don't include "Others/Undecided" thus only looping from 5 times
        cout << "    " << Options[i] << " - " << fixed << setprecision(0) << ((Votes[i]/totalFrequency) * 100) << "%  (with " << Votes[i] << " votes)" << endl;
    }
    cout << "    ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int main() {
    cout << "Enter the name of the list: ";
    getline(cin, ListName);
    getPossibleOptions(Options); // pass the string array and store the options
    getNumberOfVotes(Votes, &totalFrequency);
    finalOutput();
}
