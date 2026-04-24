#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

string toLowerCase(string word) {
    for (char& ch : word) {
        ch = tolower(ch);
    }
    return word;
}

int main() {
    map<string, int> wordCount;
    string sentence, word;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);

    while (ss >> word) {
        string cleanWord = "";

        for (char ch : word) {
            if (isalnum(ch)) {
                cleanWord += tolower(ch);
            }
        }

        if (!cleanWord.empty()) {
            wordCount[cleanWord]++;
        }
    }

    cout << "\nWord Frequency:\n";
    cout << "-------------------------\n";

    for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}