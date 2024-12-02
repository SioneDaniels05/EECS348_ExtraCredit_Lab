#include <iostream>
#include <iomanip> // For formatting a double-precision number.
#include <string>

// Add this line to avoid repeating std::
using namespace std;


// Prototype for the extractNumeric function
double extractNumeric(const string& str) {
    return 0;
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                << number << endl;
        }
        else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}