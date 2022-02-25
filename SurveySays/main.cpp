#include <iostream>
#include <string.h>
using namespace std;

string ListName, Options[5];

void getPossibleOptions(string *op) { // Pass by reference a string array
    for (int i = 0; i < 5; i++) {
        cin >> op[i];
    }
}


int main() {
    cout << "Enter the name of the list: ";
    cin >> ListName;
    getPossibleOptions(Options); // pass the string array and store the options
}
