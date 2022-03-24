#include <iostream>
#include <string>
#include <chrono>

using namespace std;

string database[2][2] = {
    {"admin12345", "wisdom123"},
    {"ellejohn", "pass123"}
};
string username, password;
int pageNum;
string choices[5][2] = { 
    {'f', "Front Page" },
    {'h', "Headline" },
    {'e', "Entertainment" },
    {'s', "Sports Page" },
    {'d', "Editorial" }
};
char option;

bool validateCredentials() {
    for (int i = 0; i < 2; i++){
        if (database[i][0] == username && database[i][1] == password) {
            return true; // Means username and pwd are correct
        }
    }
    return false;
}

int checkPage(char choices[]){
    for (int i = 0; i < 5; i++) {
        if (choices[i] == option || choices[i] == option + 32) { // can be upper or lowercase
           return i; // Returns the right index
        }
    }
    return -1; // -1 for error
}

void getDate() { // Taken from https://stackoverflow.com/questions/40100507/how-do-i-get-the-current-date-in-c
    std::time_t now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    cout << "    Date:" << std::ctime(&now_time);
}

void Login() {
    cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-SITE LOGIN-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
    cout << "\tEnter username: ";
    cin >> username;
    cout << "\tEnter password: ";
    cin >> password;
    if (validateCredentials() == false) {
        throw 5;
    }
    cout << ".-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
}

void Home() {
    // Greet the user
    cout << "\n      ~ [ WELCOME TO THE NEON NEWS SITE (Logged in as " << username << ") ] ~\n";
    cout << "\n     Where do you want to go? ------ Please enter only one character \n\n";
    cout << "\t* " << choices[0][1] << "     - F\n";
    cout << "\t* Headline       - H\n";
    cout << "\t* Entertainment  - E\n";
    cout << "\t* Sports Page    - S\n";
    cout << "\t* Editorial      - D\n\n";
    cout << "\tGO TO ~~~~~~> ";
    cin >> option;
    pageNum = checkPage(choices); // Assign return value of function
    if (pageNum == -1) {
        throw 8;
    }
}

void ShowPage() {
    switch(pageNum) {
        case 0: // Front page
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-FRONT PAGE-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n\n";
            getDate(); // Show date
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-END OF FRONT PAGE-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
            break;
        case 1: // Headline
            break;
        case 2: // Entertainment
            break;
        case 3: // Sports Page
            break;
        case 4: // Editorial
            break;
    }
}

int main() {
    try {
        Login();
        Home();
        ShowPage();
    } catch (int errcode) {
        switch (errcode) {
            case 5:
                cout << "\n\tError code 5: Failed to login (wrong username/password)\n";
                break;
            case 8:
                cout << "\n\tError code 8: Page doesn't exist! \n";
                break;
        }
    }
}
