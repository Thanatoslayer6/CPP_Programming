#include <iostream>
#include <ctime>

using namespace std;

// Declare and define the strings globally
string RandomMessage[3] = {
	"All that we are is the result of what we have thought.\nThe mind is everything, What we think what we become",
	"Never dream for success but work for it.",
	"If your heart sets out to do good things,\nthings will only get better."
};
string RandomColor[10] = {
	"Red", "Green", "Blue", "Orange", "Pink", "Yellow",
	"Brown", "Violet", "Indigo", "White"
};

void Output(string LifeConcept, int ln, int lmi, int lci){
	 	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << LifeConcept << " Advice: \n";
		cout << RandomMessage[lmi] << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Your Lucky Color of the day: " << RandomColor[lci] << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Your Lucky number: " << ln << endl;
	 	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

int main(){
	// Initialize rng and some variables
	srand((unsigned)time(0));
	int LuckyNumber = (rand() % 99) + 1;
	int LuckyMessageIndex = rand() % 3;
	int LuckyColorIndex = rand() % 10;


	char UserInput;
	
	// Ask for user input with style
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << " :~ Enter a letter traveler ~:\n";
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> ";
	cin >> UserInput;
	
	switch(UserInput){
		case 'M': case 'm':
			Output("Money", LuckyNumber, LuckyMessageIndex, LuckyColorIndex);
			break;
		case 'F': case 'f':
			Output("Fame", LuckyNumber, LuckyMessageIndex, LuckyColorIndex);
			break;
		case 'L': case 'l':
			Output("Love & Marriage", LuckyNumber, LuckyMessageIndex, LuckyColorIndex);
			break;
		case 'Y': case 'y':
			Output("Creativity", LuckyNumber, LuckyMessageIndex, LuckyColorIndex);
			break;
		case 'P': case 'p':
			Output("Helpful People", LuckyNumber, LuckyMessageIndex, LuckyColorIndex);
			break;
		case 'C': case 'c':
			Output("Career", LuckyNumber, LuckyMessageIndex, LuckyColorIndex);
			break;
		case 'S': case 's':
			Output("Spiritual Growth", LuckyNumber, LuckyMessageIndex, LuckyColorIndex);
			break;
		case 'H': case 'h':
			Output("Health", LuckyNumber, LuckyMessageIndex, LuckyColorIndex);
			break;
		default:
			cout << "~ Please try again ~" << endl;
			break;
	}


}
