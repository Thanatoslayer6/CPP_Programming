#include <iostream>
#include <string.h>
using namespace std;

string username, password; // Declare needed variables

bool checkUsername(string str) {
    if (str.length() <= 10) {
        return false;
    }
    return true; // returns true if username length is 10 or greater than 10
}

bool checkPassword(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%') {
            return true;
        }
    }
    return false; // returns false if no special character is found
}

int main() {
    try {
        // USERNAME
        cout << "\n Enter username (atleast 10 characters): ";
        cin >> username;
        if (checkUsername(username) == false) { // Validate username
            throw 5;
        }
        // PASSWORD
        cout << "\n Enter password (atleast 1 special character (!@#$%): ";
        cin >> password;
        if (checkPassword(password) == false) { // Validate password
            throw 10;
        }
        // If Successful
        cout << "\n ~ SUCCESS! ~\n";

    } catch (int errcode) {
        if (errcode == 5) {
            cout << "\nError Code 5: Username must be atleast 10 characters long\n";
            cout << "\n ~ FAILED! ~\n";
        } else if (errcode == 10) {
            cout << "\nError Code 10: Password must have atleast 1 special character (!@#$%)\n";
            cout << "\n ~ FAILED! ~\n";
        }
    }
}
