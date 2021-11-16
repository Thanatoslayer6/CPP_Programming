#include <iostream>
#include <ctime>

using namespace std;

int main(){
	// Initialize rng and some variables
	srand((unsigned)time(0));
	int LuckyNumber = (rand() % 99) + 1;
	int LuckyMessageIndex = rand() % 3;
	int LuckyColorIndex = rand() % 10;
	string RandomMessage[3] = {
		"All that we are is the result of what we have thought.\nThe mind is everything, What we think what we become",
		"Never dream for success but work for it.",
		"If your heart sets out to do good things,\nthings will only get better."
	};
	string RandomColor[10] = {
		"Red", "Green", "Blue", "Orange", "Pink", "Yellow",
		"Brown", "Violet", "Indigo", "White"
	};

	string LifeConcept;
	char UserInput;
	
	// Ask for user input with style
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << " :~ Enter a letter traveler ~:\n";
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> ";
	cin >> UserInput;
	
	switch(UserInput){
		case 'M': case 'm':
			LifeConcept = "Money";
			break;
		case 'F': case 'f':
			LifeConcept = "Fame";
			break;
		case 'L': case 'l':
			LifeConcept = "Love & Marriage";
			break;
		case 'Y': case 'y':
			LifeConcept = "Creativity";
			break;
		case 'P': case 'p':
			LifeConcept = "Helpful People";
			break;
		case 'C': case 'c':
			LifeConcept = "Career";
			break;
		case 'S': case 's':
			LifeConcept = "Spiritual growth";
			break;
		case 'H': case 'h':
			LifeConcept = "Health";
			break;
		default:
			cout << "~ Please try again ~" << endl;
			exit(0);
			break;
	}

	 	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << LifeConcept << " Advice: \n";
		cout << RandomMessage[LuckyMessageIndex] << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Your Lucky Color of the day: " << RandomColor[LuckyColorIndex] << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Your Lucky number: " << LuckyNumber << endl;
	 	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

}
