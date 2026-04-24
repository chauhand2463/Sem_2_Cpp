#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string fileName;
    ifstream file;

    cout << "=========================================\n";
    cout << "      FILE PROCESSING APPLICATION\n";
    cout << "=========================================\n";

    while (true) {
        cout << "\nEnter file name: ";
        getline(cin, fileName);

        file.open(fileName);

        if (file.is_open()) {
            cout << "\nFile opened successfully.\n";
            break;
        }

        cout << "Error: Unable to open file. Please try again.\n";
        file.clear();
    }

    string line;
    int lineNumber = 0;
    int validLines = 0;
    int invalidLines = 0;
    double totalSum = 0.0;

    cout << "\nProcessing file...\n";
    cout << "-----------------------------------------\n";

    while (getline(file, line)) {
        lineNumber++;

        if (line.empty()) {
            cout << "Line " << lineNumber << ": Empty line skipped.\n";
            invalidLines++;
            continue;
        }

        stringstream ss(line);
        double number;
        double lineSum = 0.0;
        int count = 0;
        bool valid = true;

        while (ss >> number) {
            lineSum += number;
            count++;
        }

        if (!ss.eof()) {
            valid = false;
        }

        if (valid && count > 0) {
            double average = lineSum / count;
            totalSum += lineSum;
            validLines++;

            cout << "Line " << lineNumber
                 << " -> Sum = " << lineSum
                 << ", Average = " << fixed << setprecision(2)
                 << average << endl;
        } else {
            cout << "Line " << lineNumber
                 << " -> Invalid or corrupted data. Skipped.\n";
            invalidLines++;
        }
    }

    file.close();

    cout << "\n=========================================\n";
    cout << "           PROCESSING SUMMARY\n";
    cout << "=========================================\n";
    cout << "Total Lines Read     : " << lineNumber << endl;
    cout << "Valid Lines          : " << validLines << endl;
    cout << "Invalid Lines        : " << invalidLines << endl;
    cout << "Overall Sum          : " << fixed << setprecision(2)
         << totalSum << endl;
    cout << "=========================================\n";

    return 0;
}