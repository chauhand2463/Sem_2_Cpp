#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>
using namespace std;

int main() {
    int numerator, denominator;
    double result;

    try {
        cout << "========================================\n";
        cout << "      DIVISION EXCEPTION HANDLER\n";
        cout << "========================================\n\n";

        cout << "Enter numerator (integer): ";
        if (!(cin >> numerator)) {
            throw invalid_argument("Invalid input! Numerator must be an integer.");
        }

        cout << "Enter denominator (integer): ";
        if (!(cin >> denominator)) {
            throw invalid_argument("Invalid input! Denominator must be an integer.");
        }

        if (denominator == 0) {
            throw runtime_error("Division by zero is not allowed.");
        }

        result = static_cast<double>(numerator) / denominator;

        cout << "\n----------- RESULT -----------\n";
        cout << "Numerator   : " << numerator << endl;
        cout << "Denominator : " << denominator << endl;
        cout << fixed << setprecision(2);
        cout << "Quotient    : " << result << endl;
        cout << "------------------------------\n";
    }
    catch (const invalid_argument& e) {
        cout << "\nInput Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    catch (const runtime_error& e) {
        cout << "\nRuntime Error: " << e.what() << endl;
    }
    catch (...) {
        cout << "\nAn unexpected error occurred." << endl;
    }

    return 0;
}