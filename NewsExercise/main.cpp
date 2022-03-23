#include <iostream>
#include <string>

using namespace std;

string database[2][2] = {
    {"admin12345", "wisdom123"},
    {"ellejohn", "pass123"}
};
string username, password;

int checkUser(string usr) {
    for (int i = 0; i < 2; i++) {
        if (database[i][0] == usr) {
           return i;  // Means user exists, return index in the database
        } 
    }
    return -1; // Means user is not found, return -1
}

int checkPwd(int idx, string pwd) {
    for (int i = 0; i < 2; i++) {
        if (database[i][idx] == pwd) {
           return 1;  // Means password is correct
        } 
    }
    return -1; // Means wrong pwd
}

int checkPage(char choices[], char option){
    for (int i = 0; i < 5; i++) {
        if (choices[i] == option || choices[i] == option - 32) { // can be upper or lowercase
           return 1; 
        }
    }
    return -1;
}

void Login() {
    cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-SITE LOGIN-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
    // Username validation
    int usr_index, pass_status;
    cout << "\tEnter username: ";
    cin >> username;
    usr_index = checkUser(username);
    if (usr_index == -1){
        throw 5;
    }
    // Password validation
    cout << "\tEnter password: ";
    cin >> password;
    pass_status = checkPwd(usr_index, password);
    if (pass_status == -1) {
        throw 6;
    }
    cout << ".-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
}

void Home() {
    char choices[5] = { 'f', 'h', 'e', 's', 'd' };
    char option;
    // Greet the user
    cout << "\n      ~ [ WELCOME TO THE NEON NEWS SITE (Logged in as " << username << ") ] ~\n";
    cout << "\n     Where do you want to go? ------ Please enter only one character \n\n";
    cout << "\t* Front Page     - F\n";
    cout << "\t* Headline       - H\n";
    cout << "\t* Entertainment  - E\n";
    cout << "\t* Sports Page    - S\n";
    cout << "\t* Editorial      - D\n\n";
    cout << "\tGO TO ~~~~~~> ";
    cin >> option;
    if (checkPage(choices, option) == -1) {
        throw 8;
    }
}

int main() {
    try {
        Login();
        Home();
    } catch (int errcode) {
        switch (errcode) {
            case 5:
                cout << "\n\tError code 5: Failed to login (username not found)\n";
                break;
            case 6:
                cout << "\n\tError code 6: Failed to login (wrong password)\n";
                break;
            case 8:
                cout << "\n\tError code 8: Page doesn't exist! \n";
        }
    }
}
