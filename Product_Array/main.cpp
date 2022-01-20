#include <iostream>

using namespace std;

int main() {
    int input[100]; // Only 100 numbers can be inputted by the user
    int product = 1;
    cout << "Enter numbers with spaces separated: ";
    for (int i = 0; i < 100; i++){
        cin >> input[i];
        product *= input[i];
        if (cin.get() == '\n') {
            break; // If user presses enter we stop the loop
        }
    }
    cout << "The product is: " << product << endl;
}