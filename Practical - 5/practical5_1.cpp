#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt");
    
    if (!file) {
        cout << "Error opening file";
        return 1;
    }

    string line;
    long long lines = 0, words = 0, chars = 0;

    while (getline(file, line)) {
        lines++;
        chars += line.size() + 1;

        bool inWord = false;

        for (char c : line) {
            chars++;
            if (c == ' ' || c == '\t') {
                inWord = false;
            } else if (!inWord) {
                inWord = true;
                words++;
            }
        }
    }

    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters: " << chars << endl;

    file.close();
    return 0;
}