#include <iostream>

using namespace std;

int main() {
    int product = 1;
    cout << "Enter numbers by spaces: ";
    int input;

    do {
        cin >> input;
        product *= input;
    } while (cin.peek() != '\n'); // Use special cin method "cin.peek()"

    cout << "The result is: " << product << endl;
    return 0;
}
