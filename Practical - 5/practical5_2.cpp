#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file) {
        cout << "Error opening file";
        return 0;
    }

    string line;
    int charCount = 0, wordCount = 0, lineCount = 0;

    while (getline(file, line)) {
        lineCount++;

        int len = line.length();
        charCount += len;

        bool inWord = false;

        for (int i = 0; i < len; i++) {
            if (line[i] != ' ' && line[i] != '\t') {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
    }

    file.close();

    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << charCount << endl;

    return 0;
}