#include <iostream>
#include <string>
#include <chrono>

using namespace std;

string database[][2] = {
    {"admin12345", "wisdom123"},
    {"ellejohn", "pass123"},
    {"test", "pp"}
};
string username, password;
int pageNum;
string Pages[5] = { "Front Page", "Headline", "Entertainment", "Sports Page", "Editorial" };
char option, keyCodes[5] = {'f', 'h', 'e', 's', 'd'};

bool validateCredentials() {
    for (int i = 0; i < 3; i++){
        if (database[i][0] == username && database[i][1] == password) {
            return true; // Means username and pwd are correct
        }
    }
    return false;
}

int checkPage(){
    for (int i = 0; i < 5; i++) {
        if (keyCodes[i] == option || keyCodes[i] == option + 32) { // can be upper or lowercase
           return i; // Returns the right index for the page
        }
    }
    return -1; // -1 for error
}

void getDate() { // Taken from https://stackoverflow.com/questions/40100507/how-do-i-get-the-current-date-in-c
    std::time_t now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    cout << "    Date: " << std::ctime(&now_time);
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
    cout << R"(     _   ____________  _   __   _   _________       _______    _____ ________________)" << endl;
    cout << R"(    / | / / ____/ __ \/ | / /  / | / / ____/ |     / / ___/   / ___//  _/_  __/ ____/)" << endl;
    cout << R"(   /  |/ / __/ / / / /  |/ /  /  |/ / __/  | | /| / /\__ \    \__ \ / /  / / / __/)" << endl;
    cout << R"(  / /|  / /___/ /_/ / /|  /  / /|  / /___  | |/ |/ /___/ /   ___/ // /  / / / /___)" << endl;
    cout << R"( /_/ |_/_____/\____/_/ |_/  /_/ |_/_____/  |__/|__//____/   /____/___/ /_/ /_____/)" << endl;
    cout << "\n      ~ [ WELCOME TO THE NEON NEWS SITE (Logged in as " << username << ") ] ~\n";
    cout << "\n     Where do you want to go? ------ Please enter only one character \n\n";

    // Show possible pages
    for (int i = 0; i < 5; i++) {
        cout << "\t* " << Pages[i] << "\t" << "   -   " << keyCodes[i] << "\n";
    }
    cout << "\n\tGO TO ~~~~~~> ";
    cin >> option;
    pageNum = checkPage(); // Assign return value of function
    if (pageNum == -1) {
        throw 8;
    }
}

void ShowPage() {
    switch(pageNum) {
        case 0: // Front page
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-FRONT PAGE-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n\n";
            getDate(); // Show date
             
            cout << "\n\t ~~~ PCS Students Cramming Over The Upcoming Exams! ~~~\n\n";
            cout << 
            "\t As the exams are approaching near, and the school year \n"
            "\t closing in. Many students have been worried about taking \n"
            "\t their last exam... [READ MORE AT PAGE ]\n";
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
