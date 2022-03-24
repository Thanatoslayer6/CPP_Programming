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
string Pages[6] = { "Front Page", "Headline", "News Articles", "Entertainment", "Sports Page", "Editorial" };
char option, keyCodes[6] = {'f', 'h', 'n', 'e', 's', 'd'};

bool validateCredentials() {
    for (int i = 0; i < 3; i++){
        if (database[i][0] == username && database[i][1] == password) {
            return true; // Means username and pwd are correct
        }
    }
    return false;
}

int checkPage(){
    for (int i = 0; i < 6; i++) {
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
    for (int i = 0; i < 6; i++) {
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
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-END OF FRONT PAGE-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
            break;
        case 1: // Headline
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-HEADLINE-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n\n";
            cout << "\t ~~~ COVID-19 New Cases Are Now Dropping! ~~~\n\n";
            cout << 
            "    Reports have shown the gradual decrease of people being infected by COVID-19\n" 
            "    in a day to day basis. From more than 1k cases per day, now we see cases that\n" 
            "    are less than that. However there are still active cases with over 40k+ people\n"
            "    these active cases are somewhat stable; a plateau for now. On the other hand, \n"
            "    countless reports from professionals have said we're transitioning from a pan-\n"
            "    demic towards an endemic. Wherein the virus will still live on but the majority\n" 
            "    is immune to the virus and its discovered variants.\n";
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-END OF HEADLINE-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
            break;
        case 2: // News Articles
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-NEWS ARTICLES-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n\n";
            cout << "\t ~~~ PCS Students Worried About The Upcoming Exams! ~~~\n\n";
            cout << 
            "    As the exams are approaching near, and the school year closing in\n"
            "    Many students are worried and anxious about taking their last exam\n"
            "    As a result, students are finding ways to cope and relax as much as\n"
            "    possible. Ways such as playing video games, watching Netflix, and more\n"
            "    in order to lessen their stress and break free from all the tasks that\n"
            "    these students have encountered. \n\n"
            "    One student from 11 - Albert The Great (STEM) shared some techniques and\n"
            "    ways to handle the fear of failing and the overall anxiety towards exams\n"
            "    the student happily said 'You must be prepared at all times, kasi ganun\n"
            "    talaga, kung titignan mo you also need to be independent in learning all\n"
            "    by yourself if you can in this situation... avoid procrastinating and\n" 
            "    remove distractions. If you have free time, make sure to use it for your\n" 
            "    own benefit! don't be afraid to fail, study online, grasp and that's it.'\n";
            cout << "\n\t ~~~ Elections 2022: Why Technology is Important ~~~\n\n";
            cout << 
            "    The election day is almost here, it is time for Filipinos to practice\n"
            "    and exercise their right in a democratic way by means of voting for their\n"
            "    desired candidate. While elections can be an active way of showing one's \n"
            "    support towards a candidate. Technology can also come into play, and from\n"
            "    its inception, the advancement towards communication and self-expression \n"
            "    has never been easier.\n\n"
            "    For this reason, people of today especially millenials have been utilizing\n"
            "    it (Social Media) to show support, or even hate towards an idea or a person.\n"
            "    As a result, the current state of technology has never been so influential\n"
            "    in the recent years, and is deemed to be important in one's nation\n";
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-END OF ARTICLES-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
            break;
        case 3: // Entertainment
            break;
        case 4: // Sports Page
            break;
        case 5: // Editorial
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
