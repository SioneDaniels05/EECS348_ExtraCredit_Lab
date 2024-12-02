#include <iostream>
#include <iomanip> // For formatting a double-precision number.
#include <string>

// Add this line to avoid repeating std::
using namespace std;


// Prototype for the extractNumeric function
double extractNumeric(const string& str) {
    double value = 0.0;
    double decimal_frac = 0.1;
    bool sign = false;
    bool sign_value = true;
    bool digit = false;
    bool decimal = false;
    int size = str.length();
    int i = 0;
    int decimal_pos = -1;

    if ((str[i] == '+') || (str[i] == '-')) { //checks for a sign at the beginning to allow proper indexing
        sign = true;
        if ((str[i]) == '-') {
            sign_value = false;
        }
        i++;
    }
    
    for (; i < size; i++) { //checks if the given input is valid to run (eg. 1, 1.1, 1.01, 0.01 etc)
        if (isdigit(str[i])) {
            digit = true;
        }
        else if ((str[i] == '.') and (decimal == false)) {
            decimal = true;
        }
        else {
            return -999999.99;
        }
    }
    
    if (digit == false) { //if there is no digit present in the input it'll return invalid
        return -999999.99;
    }

    for (int index = 0; index < size; index++) { //if there is a decimal it'll assign decimal_pos to it's indexing position
        if (str[index] == '.') {
            decimal_pos = index;
        }
    }
    
    if (decimal_pos == -1) { //if there is no decimal it'll set its position = to the inputs size
        decimal_pos = size;
    }

    if (sign == true) { //will start indexing at either 0 or 1 depending if there is a sign infront or not to prevent errors
        for (int index = 1; index < decimal_pos; index++) {
            value = value * 10 + (str[index] - '0');
        }
    }
    else {
        for (int index = 0; index < decimal_pos; index++) {
            value = value * 10 + (str[index] - '0');
        }
    }

    for (int index = decimal_pos + 1; index < size; index++) { //adds the 0's if there isn't enough decimal places
        value += (str[index] - '0')*decimal_frac;
        decimal_frac /= 10;
    }
    
    if (sign_value == false) { //if there is a - sign it'll make the value negative
        value = -value;
    }
    return value;
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