#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class NegativeNumberException {
public:
    const char* what() const {
        return "Cannot calculate square root of a negative number.";
    }
};

int main() {
    double number;

    cout << "Square Root Calculator\n";
    cout << "----------------------\n";

    try {
        cout << "Enter a number: ";
        cin >> number;

        if (!cin) {
            throw "Invalid input. Please enter a valid number.";
        }

        if (number < 0) {
            throw NegativeNumberException();
        }

        double squareRoot = sqrt(number);

        cout << fixed << setprecision(4);
        cout << "\nNumber      : " << number << endl;
        cout << "Square Root : " << squareRoot << endl;
    }
    catch (NegativeNumberException& e) {
        cout << "\nError: " << e.what() << endl;
    }
    catch (const char* message) {
        cout << "\nError: " << message << endl;
    }

    return 0;
}