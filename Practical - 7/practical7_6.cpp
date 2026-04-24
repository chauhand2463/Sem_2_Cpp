#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int numerator, denominator;
    double result;

    try {
        cout << "========================================\n";
        cout << "      DIVISION WITH EXCEPTION HANDLING\n";
        cout << "========================================\n\n";

        cout << "Enter numerator (integer): ";
        if (!(cin >> numerator))
            throw "Invalid input! Numerator must be an integer.";

        cout << "Enter denominator (integer): ";
        if (!(cin >> denominator))
            throw "Invalid input! Denominator must be an integer.";

        if (denominator == 0)
            throw "Error! Division by zero is not allowed.";

        result = static_cast<double>(numerator) / denominator;

        cout << "\n------------- RESULT -------------\n";
        cout << "Numerator   : " << numerator << endl;
        cout << "Denominator : " << denominator << endl;
        cout << fixed << setprecision(2);
        cout << "Quotient    : " << result << endl;
        cout << "----------------------------------\n";
    }
    catch (const char* message) {
        cout << "\nException Caught: " << message << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nProgram terminated successfully." << endl;
    return 0;
}