#include <iostream>
#include <ctime>

using namespace std;

int main(){
	// Declare and define needed variables and feed RNG
	char Choice;
	bool GameIsRunning = true;
	string Player1Name, Player2Name;
	int Dice_1, Dice_2, TotalSumOfDices, PointNum, NumOfRolls = 0;
	srand(unsigned(time(NULL)));
	
	while (GameIsRunning == true){
		if (NumOfRolls == 0){
			// Ask for player's names	
			cout << "ENTER Player 1 Name: ";
			cin >> Player1Name;
			cout << "ENTER Player 2 Name: ";
			cin >> Player2Name;
		}
		Dice_1 = rand() % 6 + 1;
		Dice_2 = rand() % 6 + 1;
		TotalSumOfDices = Dice_1 + Dice_2;
		NumOfRolls++;
		cout << "\n~~~~~ Rolling Dice ~~~~~\n";
		cout << "Roll no: " << NumOfRolls << endl;
		switch(Dice_1){
			case 1:
				cout << " .-------.\n";
				cout << " |       |\n";
				cout << " |   *   |\n";
				cout << " |       |\n";
				cout << " `-------`\n";
				break;
			case 2:
				cout << " .-------.\n";
				cout << " |     * |\n";
				cout << " |       |\n";
				cout << " | *     |\n";
				cout << " `-------`\n";
				break;
			case 3:
				cout << " .-------.\n";
				cout << " |     * |\n";
				cout << " |   *   |\n";
				cout << " | *     |\n";
				cout << " `-------`\n";
				break;
			case 4:
				cout << " .-------.\n";
				cout << " | *   * |\n";
				cout << " |       |\n";
				cout << " | *   * |\n";
				cout << " `-------`\n";
				break;
			case 5:
				cout << " .-------.\n";
				cout << " | *   * |\n";
				cout << " |   *   |\n";
				cout << " | *   * |\n";
				cout << " `-------`\n";
				break;
			default:
				cout << " .-------.\n";
				cout << " | *   * |\n";
				cout << " | *   * |\n";
				cout << " | *   * |\n";
				cout << " `-------`\n";
				break;
		}

		switch(Dice_2){
			case 1:
				cout << " .-------.\n";
				cout << " |       |\n";
				cout << " |   *   |\n";
				cout << " |       |\n";
				cout << " `-------`\n";
				break;
			case 2:
				cout << " .-------.\n";
				cout << " |     * |\n";
				cout << " |       |\n";
				cout << " | *     |\n";
				cout << " `-------`\n";
				break;
			case 3:
				cout << " .-------.\n";
				cout << " |     * |\n";
				cout << " |   *   |\n";
				cout << " | *     |\n";
				cout << " `-------`\n";
				break;
			case 4:
				cout << " .-------.\n";
				cout << " | *   * |\n";
				cout << " |       |\n";
				cout << " | *   * |\n";
				cout << " `-------`\n";
				break;
			case 5:
				cout << " .-------.\n";
				cout << " | *   * |\n";
				cout << " |   *   |\n";
				cout << " | *   * |\n";
				cout << " `-------`\n";
				break;
			default:
				cout << " .-------.\n";
				cout << " | *   * |\n";
				cout << " | *   * |\n";
				cout << " | *   * |\n";
				cout << " `-------`\n";
				break;
		}
		if (NumOfRolls == 1){
			switch(TotalSumOfDices){
				case 7: case 11:
					cout << Player1Name << " Wins!\n";
					cout << "\n ~~~ Play Again? ~~~ [Y/n]: ";
					cin >> Choice;
					if (Choice == 'Y' || Choice == 'y'){
						NumOfRolls = 0;
					} else if (Choice == 'N' || Choice == 'n'){
						GameIsRunning = false;
					}
					break;
				case 2: case 3: case 12:
					cout << Player2Name << " Wins!\n";
					cout << "\n ~~~ Play Again? ~~~ [Y/n]: ";
					cin >> Choice;
					if (Choice == 'Y' || Choice == 'y'){
						NumOfRolls = 0;
					} else if (Choice == 'N' || Choice == 'n'){
						GameIsRunning = false;
					}
					break;
				default:
					PointNum = TotalSumOfDices;
					cout << "Point Number: " << PointNum << endl;
					cout << "No one won :( reroll? [Y/n]: ";
					cin >> Choice;
					if (Choice == 'Y' || Choice == 'y'){
						break;						
					} else if (Choice == 'N' || Choice == 'n'){
						cout << "Thanks for playing :D\n";
						GameIsRunning = false;
					} else {
						cout << "Please enter a proper character, exiting game...\n";
						GameIsRunning = false;
					}
			}
		} else if (NumOfRolls > 1){
				if (TotalSumOfDices == PointNum){
					cout << Player1Name << " Wins!\n";
					cout << "\n ~~~ Play Again? ~~~ [Y/n]: \n";
					cin >> Choice;
					if (Choice == 'Y' || Choice == 'y'){
						NumOfRolls = 0;
					} else if (Choice == 'N' || Choice == 'n'){
						GameIsRunning = false;
					}
				} else if (TotalSumOfDices == 7){
					cout << Player2Name << " Wins!\n";
					cout << "\n ~~~ Play Again? ~~~ [Y/n]: \n";
					cin >> Choice;
					if (Choice == 'Y' || Choice == 'y'){
						NumOfRolls = 0;
					} else if (Choice == 'N' || Choice == 'n'){
						GameIsRunning = false;
					}
				} else {
					cout << "Point Number: " << PointNum << endl;
				}
		} 
	}
}
