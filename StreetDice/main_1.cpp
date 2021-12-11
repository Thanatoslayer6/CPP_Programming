#include <iostream>
#include <ctime>
 
using namespace std;
 
int main(){
    // Declare the variables
    bool GameIsRunning = true;
    char UserChoice;
    string Player1Name, Player2Name;
    int Dice1, Dice2, SumOfTwoDices, PointNumber, NumOfRolls = 0;
    srand(unsigned(time(NULL)));
 
    while (GameIsRunning == true){
        // Use RNG, Dice will generate value from 1-6
        Dice1 = rand() % 6 + 1;
        Dice2 = rand() % 6 + 1;
        SumOfTwoDices = Dice1 + Dice2;
        if (NumOfRolls == 0){
            // Insert ASCII ART MENU (Raw)
            cout << R"(
        .~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.
        |   ___  ____  ____  ____  ____  ____    ____  ____  ___  ____   |
        |  / __)(_  _)(  _ \( ___)( ___)(_  _)  (  _ \(_  _)/ __)( ___)  |
        |  \__ \  )(   )   / )__)  )__)   )(     )(_) )_)(_( (__  )__)   |
        |  (___/ (__) (_)\_)(____)(____) (__)   (____/(____)\___)(____)  |
        |                                                                |
        `~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
            )" << "\n";
 
            // Ask for player's names
            cout << "\t ENTER Player 1 Name: ";
            cin >> Player1Name;
            cout << "\t ENTER Player 2 Name: ";
            cin >> Player2Name;
        }
 
        // Insert ASCII Art (Raw)
        cout << R"(
        ###################################################
            ___       _____             ___  _
           / _ \___  / / (_)__  ___ _  / _ \(_)______
          / , _/ _ \/ / / / _ \/ _ `/ / // / / __/ -_) _ _
         /_/|_|\___/_/_/_/_//_/\_, / /____/_/\__/\__(_|_|_)
                              /___/
        ###################################################
            )" << "\n";
 
        NumOfRolls++;
        cout << "\t Roll no: " << NumOfRolls << "\n";
        switch(Dice1){
            case 1:
                cout << "\t.-------.\n";
                cout << "\t|       |\n";
                cout << "\t|   *   |\n";
                cout << "\t|       |\n";
                cout << "\t`-------`\n";
                break;
            case 2:
                cout << "\t.-------.\n";
                cout << "\t|     * |\n";
                cout << "\t|       |\n";
                cout << "\t| *     |\n";
                cout << "\t`-------`\n";
                break;
            case 3:
                cout << "\t.-------.\n";
                cout << "\t|     * |\n";
                cout << "\t|   *   |\n";
                cout << "\t| *     |\n";
                cout << "\t`-------`\n";
                break;
            case 4:
                cout << "\t.-------.\n";
                cout << "\t| *   * |\n";
                cout << "\t|       |\n";
                cout << "\t| *   * |\n";
                cout << "\t`-------`\n";
                break;
            case 5:
                cout << "\t.-------.\n";
                cout << "\t| *   * |\n";
                cout << "\t|   *   |\n";
                cout << "\t| *   * |\n";
                cout << "\t`-------`\n";
                break;
            default:
                cout << "\t.-------.\n";
                cout << "\t| *   * |\n";
                cout << "\t| *   * |\n";
                cout << "\t| *   * |\n";
                cout << "\t`-------`\n";
                break;
        }
        switch(Dice2){
            case 1:
                cout << "\t\t.-------.\n";
                cout << "\t\t|       |\n";
                cout << "\t\t|   *   |\n";
                cout << "\t\t|       |\n";
                cout << "\t\t`-------`\n";
                break;
            case 2:
                cout << "\t\t.-------.\n";
                cout << "\t\t|     * |\n";
                cout << "\t\t|       |\n";
                cout << "\t\t| *     |\n";
                cout << "\t\t`-------`\n";
                break;
            case 3:
                cout << "\t\t.-------.\n";
                cout << "\t\t|     * |\n";
                cout << "\t\t|   *   |\n";
                cout << "\t\t| *     |\n";
                cout << "\t\t`-------`\n";
                break;
            case 4:
                cout << "\t\t.-------.\n";
                cout << "\t\t| *   * |\n";
                cout << "\t\t|       |\n";
                cout << "\t\t| *   * |\n";
                cout << "\t\t`-------`\n";
                break;
            case 5:
                cout << "\t\t.-------.\n";
                cout << "\t\t| *   * |\n";
                cout << "\t\t|   *   |\n";
                cout << "\t\t| *   * |\n";
                cout << "\t\t`-------`\n";
                break;
            default:
                cout << "\t\t.-------.\n";
                cout << "\t\t| *   * |\n";
                cout << "\t\t| *   * |\n";
                cout << "\t\t| *   * |\n";
                cout << "\t\t`-------`\n";
                break;
        }
        cout << "\n\t* The sum of the two dices is -> " << SumOfTwoDices << "\n";
 
        // Game Mechanics
        if (NumOfRolls == 1 && (SumOfTwoDices == 7 || SumOfTwoDices == 11 )){
            cout << "\t~ [Player " << Player1Name << " Wins] ~ \n\n";
            cout << "\t~ Do you wish to play again? [y/n]: ";
            cin >> UserChoice;
            if (UserChoice == 'Y' || UserChoice == 'y'){
                NumOfRolls = 0;
            } else if (UserChoice == 'N' || UserChoice == 'n'){
                GameIsRunning = false;
                cout << "\n\t---- Thanks for playing, Goodbye :D ----\n";
            } else {
                GameIsRunning = false;
                cout << "\n\t---- Exiting game, Please enter proper character...  ----\n";
            }
        } else if (NumOfRolls == 1 && (SumOfTwoDices == 2 || SumOfTwoDices == 3 || SumOfTwoDices == 12)) {
            cout << "\t~ [Player " << Player2Name << " Wins] ~ \n\n";
            cout << "\t~ Do you wish to play again? [y/n]: ";
            cin >> UserChoice;
            if (UserChoice == 'Y' || UserChoice == 'y'){
                NumOfRolls = 0;
            } else if (UserChoice == 'N' || UserChoice == 'n'){
                GameIsRunning = false;
                cout << "\n\t---- Thanks for playing, Goodbye :D ----\n";
            } else {
                GameIsRunning = false;
                cout << "\n\t---- Exiting game, Please enter proper character...  ----\n";
            }
        } else if (NumOfRolls == 1 && (SumOfTwoDices == 4 || SumOfTwoDices == 5
                                       || SumOfTwoDices == 6 || SumOfTwoDices == 8
                                       || SumOfTwoDices == 9 || SumOfTwoDices == 10)) {
            PointNumber = SumOfTwoDices;
            cout << "\t ~ Point Number is -> " << PointNumber << "\n\n";
            cout << "\t ~ Type 'Y' or 'y' to reroll: ";
            cin >> UserChoice;
            if (UserChoice == 'Y' || UserChoice == 'y'){
                cout << "\t\t* * * * * Rerolling again * * * * *\n";
            } else {
                GameIsRunning = false;
                cout << "\n\t---- Didn't reroll... Thanks for playing, Goodbye :D ----\n";
            }
        } else if (NumOfRolls > 1 && SumOfTwoDices == PointNumber){
            cout << "\t~ [Player " << Player1Name << " Wins] ~ \n";
            cout << "\t* Reason: Because the sum of the two dices is equal to the point number -> " << PointNumber << "\n\n";
            cout << "\t~ Do you wish to play again? [y/n]: ";
            cin >> UserChoice;
            if (UserChoice == 'Y' || UserChoice == 'y'){
                NumOfRolls = 0;
            } else if (UserChoice == 'N' || UserChoice == 'n'){
                GameIsRunning = false;
                cout << "\n\t---- Thanks for playing, Goodbye :D ----\n";
            } else {
                cout << "\n\t---- Exiting game, Please enter proper character...  ----\n";
            }
        } else if (NumOfRolls > 1 && SumOfTwoDices == 7){
            cout << "\t~ [Player " << Player2Name << " Wins] ~ \n";
            cout << "\t* Reason: Because the sum of the two dices is: 7\n\n";
            cout << "\t~ Do you wish to play again? [y/n]: ";
            cin >> UserChoice;
            if (UserChoice == 'Y' || UserChoice == 'y'){
                NumOfRolls = 0;
            } else if (UserChoice == 'N' || UserChoice == 'n'){
                GameIsRunning = false;
                cout << "\n\t---- Thanks for playing, Goodbye :D ----\n";
            } else {
                cout << "\n\t---- Exiting game, Please enter proper character...  ----\n";
            }
        } else {
            cout << "\t ~ Point Number is -> " << PointNumber << "\n";
            cout << "\t No one wins this round... rerolling again\n";
        }
    }
}
