#include <iostream>

using namespace std;

int main() {
    string UserInput;
    int count[5] = {0}; // Define all indices to zero
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'}; // lowercase vowels
    cout << "Enter a text: ";
    getline(cin, UserInput);
    for (int i = 0; i < UserInput.size(); i++) {
        for (int k = 0; k < 5; k++) {
            // ASCII char - 32 is equal to it's uppercase character, accepts uppercase vowels...
            if (UserInput[i] == vowels[k] || UserInput[i] == vowels[k] - 32) {
                count[k]++;
            }
        }        
    }
    for (int j = 0; j < 5; j++) {
        if (count[j] > 0) { // Only output vowels appearing > 0
            cout << "User's input contains " << count[j] << " - " << vowels[j] << endl;
        }
    }
}