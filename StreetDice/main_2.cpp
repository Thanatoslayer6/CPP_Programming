#include <iostream>
#include <ctime>
 
using namespace std;
 
int main(){
    // Declare the variables
    char UserChoice;
    string Player1Name, Player2Name;
    bool GameIsRunning = true, PlayerWins;
    int Dice1, Dice2, SumOfTwoDices, PointNumber, NumOfRolls = 0;
    srand(unsigned(time(NULL)));
 
    while (GameIsRunning == true){
        // Use RNG, Dice will generate value from 1-6
        Dice1 = rand() % 6 + 1;
        Dice2 = rand() % 6 + 1;
        SumOfTwoDices = Dice1 + Dice2;
        PlayerWins = false;
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
        if (NumOfRolls == 1) {
            switch(SumOfTwoDices){
                case 7: case 11:
                    cout << "\t~ [Player 1 (" << Player1Name << ") Wins] ~ \n\n";
                    PlayerWins = true;
                    break;
                case 2: case 3: case 12:
                    cout << "\t~ [Player 2 (" << Player2Name << ") Wins] ~ \n\n";
                    PlayerWins = true;
                    break;
                default:
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
                    break;
            }
        } else if (NumOfRolls > 1) {
            switch(SumOfTwoDices){
                case 7:
                    cout << "\t~ [Player 2 (" << Player2Name << ") Wins] ~ \n";
                    cout << "\t* Reason: Because the sum of the two dices is: 7\n\n";
                    PlayerWins = true;
                    break;
                default:
                    if (SumOfTwoDices == PointNumber){
                        cout << "\t~ [Player 1 (" << Player1Name << ") Wins] ~ \n";
                        cout << "\t* Reason: Because the sum of the two dices is equal to the point number -> " << PointNumber << "\n\n";
                        PlayerWins = true;
                    } else {
                        cout << "\t ~ Point Number is -> " << PointNumber << "\n";
                        cout << "\t No one wins this round... rerolling again\n";
                    }
                    break;

            }
        }
        // If some player wins, ask user if he/she wants to play again...
        if (PlayerWins == true) {
            cout << "\t~ Do you wish to play again? [y/n]: ";
            cin >> UserChoice;
            switch(UserChoice) {
                case 'Y': case 'y':
                    NumOfRolls = 0;
                    break;
                case 'N': case 'n': default:
                    GameIsRunning = false;
                    cout << "\n\t---- Thanks for playing, Goodbye :D ----\n";
                    break;
                }
        }
    }
}
