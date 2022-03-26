#include <iostream>
#include <string>

using namespace std;

string database[][2] = {
    {"admin12345", "wisdom123"},
    {"ellejohn", "pass123"},
    {"test", "pp"}
};
string username, password;
int pageNum;
bool loggedIn = false;
string Pages[7] = { "Front Page", "Headline", "News Articles", "Entertainment", "Sports Page", "Editorial", "EXIT"};
char option, keyCodes[7] = {'f', 'h', 'n', 'e', 's', 'd', 'x'};

bool validateCredentials() {
    for (int i = 0; i < 3; i++){
        if (database[i][0] == username && database[i][1] == password) {
            return true; // Means username and pwd are correct
        }
    }
    return false;
}

int checkPage(){
    for (int i = 0; i < 7; i++) {
        if (keyCodes[i] == option || keyCodes[i] == option + 32) { // can be upper or lowercase
           return i; // Returns the right index for the page
        }
    }
    return -1; // -1 for error
}


void showTableOfContents() { // Show possible pages
    cout << "\n\t~ Table of Contents ~ \n\n";
    for (int i = 0; i < 7; i++) {
        if (i == 6) { // Exit
            cout << "\n    [ Press x for " << Pages[i] << " ]\n"; 
        } else {
            cout << "      * " << Pages[i] << "\t   -   " << keyCodes[i] << "\n";
        }
    }
}

void Login() {
    cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-SITE LOGIN-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
    cout << "\tEnter username: ";
    cin >> username;
    cout << "\tEnter password: ";
    cin >> password;
    if (validateCredentials() == false) {
        throw 5;
    } else {
        loggedIn = true;
    }
    cout << ".-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
}

void Home() {
    // Greet the user
    cout <<
    R"(
                |\ | _   ,_  |\ | _     _  (`.|- _ 
                | \|(/_()||  | \|(/_LL|_\  _)||_(/_
    )";
    cout << "\n      ~ [ WELCOME TO THE NEON NEWS SITE (Logged in as " << username << ") ] ~\n";
    cout << "\n     Where do you want to go? ------ Please enter only one character \n\n";
}

void ShowPage() {
    switch(pageNum) {
        case 0: // Front page
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-FRONT PAGE-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n\n";
            cout << R"(
*--------------------------------------------------------------------------------*
|  Monday, April 4, 2022  | CALL US NOW! (212) 804-6003 | PH LOTTO RESULTS 6/58  |
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|  _  _ _  _ _  _ ___  ____ ____    ____ ____    _  _ ____ _ _ _  |-o         o/||
|  |\ | |  | |\/| |__] |___ |__/    |  | |___    |\ | |___ | | |  |    \ q /    o|
|  | \| |__| |  | |__] |___ |  \    |__| |       | \| |___ |_|_|  |  o .-o-. o   |
|                                                                 | o-(o o o)-o  |
|  ____ ____ _  _ _ ___         ____    ____ ____ ____ ____ ____  |  o ._o_. o   |
|  |    |  | |  | | |  \ __ /|  |__|    |    |__| [__  |___ [__   |    / b \    q| 
|  |___ |__|  \/  | |__/    _|_    |    |___ |  | ___] |___ ___]  |--------------|
|                                                                 |COVID-19 VIRUS|
|                                                                 `--------------| 
|  ____ ____ ____    _  _ ____ _ _ _    ___  ____ ____ ___  ___  _ _  _ ____   / |
|  |__| |__/ |___    |\ | |  | | | |    |  \ |__/ |  | |__] |__] | |\ | | __  /  |
|  |  | |  \ |___    | \| |__| |_|_|    |__/ |  \ |__| |    |    | | \| |__] .   |
|                                                                                |
|  [ H E A D L I N E ]                                                           |
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|  [ N E W S  - A R T I C L E S ]   |             [ E N T E R T A I N M E N T ]  |
|                                   |                                            |
|  PCS STUDENTS WORRIED ABOUT THE   |         /\  _ |_. _. _  _ |_ _ _|          | 
|          UPCOMING EXAMS           |        /--\| )|_|(_||_)(_||_(-(_|          | 
|                                   |                 |                          | 
| ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |                          __   __  __  __   | 
|                                   |   |\/| _   . _ _  . _     _) /  \  _)  _)  | 
|  ELECTIONS 2022: WHY TECHNOLOGY   |   |  |(_)\/|(-_)  || )   /__ \__/ /__ /__  | 
|          IS IMPORTANT             |                                            | 
|                                   |                                            |
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|                                               | [ S P O R T S ]                |
|             ..,,;;;;;;,,,,                    |                                |
|       .,;'';;,..,;;;,,,,,.''';;,..            |     THE RISE IN POPULARITY     |
|    ,,''                    '';;;;,;''         |                                | 
|   ;'    ,;@@;'  ,@@;, @@, ';;;@@;,;';.        |            OF CHESS            |
|  ''  ,;@@@@@'  ;@@@@; ''    ;;@@@@@;;;;       |                                | 
|     ;;@@@@@;    '''     .,,;;;@@@@@@@;;;      |       AMIDST THE PANDEMIC      |
|    ;;@@@@@@;           , ';;;@@@@@@@@;;;.     |                                |
|     '';@@@@@,.  ,   .   ',;;;@@@@@@;;;;;;     |                   (\=,         | 
|        .   '';;;;;;;;;,;;;;@@@@@;;' ,.:;'     |    __    |'-'-'|  //  .\       | 
|          ''..,,     ''''    '  .,;'           |   /  \   |_____| (( \_  \      |
|               ''''''::''''''''                |   \__/    |===|   ))  `\_)     |
|                                               |  /____\   |   |  (/     \      |
|      "In a world of universal deceit,         |   |  |    |   |   | _.-'|      |
|   telling the truth is a revolutionary act."  |   |__|    )___(    )___(       |
|                                               |  (====)  (=====)  (=====)      |
|          ~ George Orwell ~ 1984 ~             |  }===={  }====={  }====={      |  
|                                               | (______)(_______)(_______)     |
| [ E D I T O R I A L ] - A World On Fire?      | ><><><><><><><><><><><><><><>< |
*--------------------------------------------------------------------------------*
            )" << '\n';

            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-END OF FRONT PAGE-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
            break;
        case 1: // Headline
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-HEADLINE-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n\n";
            cout << "\t ~~~ Number Of New COVID-19 Cases Are Now Dropping! ~~~\n\n";
            cout << 
            "    Reports have shown the gradual decrease of people being infected by COVID-19\n" 
            "    in a day to day basis. From more than 1k cases per day, now we see cases that\n" 
            "    are less than that. However there are still active cases with over 40k+ people\n"
            "    these active cases are somewhat stable; a plateau for now. On the other hand, \n"
            "    countless reports from professionals have said we're transitioning from a pan-\n"
            "    demic towards an endemic. Wherein the virus will still live on but the majority\n" 
            "    will be immune to the virus and its discovered variants.\n";
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-END OF SECTION-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
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
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-END OF SECTION-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
            break;
        case 3: // Entertainment
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-ENTERTAINMENT-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n\n";
            cout << "\n\t ~~~ Anticipated Movies in 2022 ~~~\n\n";
            cout << 
            "   It's been the third month of the year, and so far we have seen movies or shows\n"
            "   that exceed our expectations, some are entertaining, some will leave its viewers\n"
            "   a moral or a lesson, and some will make you speechless. As we move forward through\n" 
            "   the years, normal/mediocre movies come and go, it will stay there for a while but\n"
            "   movies that are made with true essence and is on its purest form will stay longer.\n"
            "   We see this, as some rare and old movies still become relevant and influential\n"
            "   throughout the decades. With that, we have considered 5 movies that are mostly\n" 
            "   anticipated by critics and praised by its fans.\n\n"
            "   LIST OF MOVIES (IN NO ORDER)\n\n"
            "   * Nope\n\t - Directed by Jordan Peele, Horror/Thriller\n\n"
            "   * Top Gun: Maverick\n\t - Directed by Joseph Kosinski, Action/Adventure\n\n"
            "   * The Northman\n\t - Directed by Robert Eggers, Action/Adventure\n\n"
            "   * Thor: Love and Thunder\n\t - Directed by Taika Waititi, Action/Adventure\n\n"
            "   * The Batman (NOW SHOWING)\n\t - Directed by Matt Reeves, Action/Adventure\n\n"
            "   * Doctor Strange in the Multiverse of Madness\n\t - Directed by Sam Raimi, Adventure/Fantasy\n\n"
            "   * Lightyear\n\t - Directed by Angus MacLane, Adventure/Fantasy\n\n"
            "   * Jurrasic World: Dominion\n\t - Directed by Colin Trevorrow, Sci-Fi/Adventure\n\n"
            "   * Avatar 2\n\t - Directed by James Cameron, Sci-Fi/Action\n\n"
            "   * Turning Red (NOW SHOWING)\n\t - Directed by Domee Shi, Comedy/Family\n\n";
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-END OF SECTION-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
            break;
        case 4: // Sports Page
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-SPORTS-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n\n";
            cout << "\n\t ~~~ The Rise In Popularity Of Chess Amidst The Pandemic ~~~\n\n";
            cout << 
            "   Chess has been totally on the rise since the start of the pandemic, from\n"
            "   its ancient history 1500 years ago. Chess is considered as a recreational\n"
            "   activity, it is a sport in which decades of competition have sparked from\n"
            "   countries that are focusing on it such as Russia, and the United States back\n"
            "   then in the span of the Cold War, where both countries battle in order to see\n"
            "   who's the smartest and the toughest of them all. Now in the present time, Chess\n"
            "   is still seen as a competitive sport. However, it can be a means of entertainment\n"
            "   as well.\n\n"
            "   Amidst the current situation that this pandemic has brought to us, many people are\n"
            "   forced to stay in their homes, especially adults or kids who are working or study-\n" 
            "   ing for a period of time. With professional chess players switching to the digital\n"
            "   side of technology, we now have livestreamers who play Chess and teach the masses\n"
            "   and for that cause, the advancement of technology is at work as well. Considereing\n"
            "   that in the past we didn't have online Chess. From this little spark, a recent tv-\n"
            "   show on Netflix entitled 'The Queen's Gambit' gained a lot of attention, not just \n"
            "   from Chess players, but from normal people as well. As a result, it boosted the pop\n"
            "   ularity of the game. As of now, Chess is still becoming more popular as new players\n"
            "   are introduced to the game, the ease of access within chess is literally clicks away\n"
            "   countless platforms such as 'Lichess.org', allows users (even users with no accounts)\n"
            "   to play live and real-time. In the end, people stay at home and find new ways to gain\n"
            "   hobbies or interests, just to pass the time.\n";
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-END OF SECTION-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
            break;
        case 5: // Editorial
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-EDITORIAL-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n\n";
            cout << "\n\t ~~~ OPINION: A World On Fire ~~~\n\n";
            cout <<
            "   Apparently, you might have heard the recent news about the Russian invasion of Ukraine\n"
            "   while this seems, quite alarming and shocking at the same time. What's truly happening is we're\n"
            "   like slowly approacing our doom, and this is like the first step, from diseases, wars\n"
            "   famine, poverty and more.\n\n"
            "   We're slowly killing ourselves, deteriorating, every aspect in our life is basically affected,\n"
            "   from the moment you hold your phone, you are not in control. What's sad about the 21st Century\n"
            "   is that, it got real. It got real to the point where there's simply no return, and if you\n" 
            "   think this Russian invasion is the first thing to happen in this decade or year....\n"
            "   and will probably be the last thing to happen... You're wrong! because it's happening \n"
            "   in basically almost every part of the world, like Afghanistan, Sudan, Yemen, and much \n"
            "   more in terms of minor or major conflicts. In fact, China is already planning their way\n"
            "   in a long term, theres no need for blood to pour down in every nation. In fact, what they're\n"
            "   doing now is colonizing us. Neocolonialism if u may, it just doesn't happen right in the\n"
            "   Philippines, as many Southeast Asian countries are also affected like Malaysia, Thailand\n"
            "   and much more. Moving on, we can somewhat see a pattern that governments are becoming too\n"
            "   powerful and tyrannical. History is just forced to repeat itself from Hitler, Mao Zedong,\n" 
            "   Stalin and Kim II-Sung, we now have Kim Jong-Un, Duterte/Marcos, Putin, Xi Jinping ironically\n"
            "   and literally becoming the 'Four Horsemen of the Apocalypse'. Only these men have brought\n"
            "   suffering and oppression to the totality of all people, their lies twist and bend history\n"
            "   and the minds of the people especially the youth which is the future of one's nation.\n"
            "   The crazy thing is, people are vulnerable and they have no idea, that they're no longer\n"
            "   protected, and in control of their minds. From mass surveillance, fake news/disinformation\n"
            "   social media/gaming addiction, you name it, and from these typical things what is at the cen-\n"
            "   ter is technology itself. Ever since we got it, it made things easier, and now it seems like\n"
            "   we want more of that, whether it's convenience, pleasure, satisfaction.\n\n"
            "   In the end, we humans are naturally inclined to greed and selfishness. From all of these things,\n" 
            "   you might ask yourself, when will we ever wake up? when will we ever just get along? Well you\n"
            "   must understand and realize that the power is in your hands use it for the greater good for your\n"
            "   family, your people, and most importantly yourself. Someday, we'll just get there....\n\n"
            "   Thanks for reading =)\n";
            cout << "\n.-=-=-=-=-=-=-=-=-=-=-=-=-=-END OF SECTION-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
            break;
        case 6: // EXIT
            cout << "\n ==================/\\ ^_^ GOODBYE READER ^_^ /\\=======================\n";
            loggedIn = false;
            break;
    }
}

void Navigation() {
    showTableOfContents();
    cout << "\n    Navigate to -----> ";
    cin >> option;
    pageNum = checkPage(); // Assign return value of function
    if (pageNum == -1) {
        throw 8;
    }
}

int main() {
    try {
        Login();
        Home();
        while (loggedIn == true) {
            Navigation();
            ShowPage();
        }
    } catch (int errcode) {
        switch (errcode) {
            case 5:
                cout << "\n\tError code 5: Failed to login (wrong username/password) Exiting now...\n";
                break;
            case 8:
                cout << "\n\tError code 8: Page doesn't exist! Exiting now...\n";
                break;
        }
    }
}
