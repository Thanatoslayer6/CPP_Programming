#include <iostream>

using namespace std;

int main() {
    char UserInput[1000]; // 1000 as the maximum size of chars
    char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
    int count[5] = {0}; // Define all indices to zero
    // Ask for user input 
    cout << "Enter a text: ";
    cin.get(UserInput, 1000);
    // Iterate over the text
    for (int i = 0; i < 1000; i++) {
        if (UserInput[i] == '\0') break; // If the index reaches a null terminator, end the loop
        for (int k = 0; k < 5; k++) {
            // Allow uppercase vowels by subtracting 32 to an ASCII char (results into an uppercase)
            if (UserInput[i] == vowels[k] || UserInput[i] == vowels[k] - 32) {
                count[k]++;
            }
        }        
    }
    // Output everything
    for (int j = 0; j < 5; j++) {
        if (count[j] > 0) { // Only output vowels appearing > 0
            cout << "User's input contains " << count[j] << " - " << vowels[j] << endl;
        }
    }
}