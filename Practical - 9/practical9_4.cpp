#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    map<string, vector<string>> directory;
    int choice;

    do {
        cout << "\n=====================================\n";
        cout << "      DIRECTORY MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Add Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
            case 1: {
                string folderName;
                cout << "Enter folder name: ";
                getline(cin, folderName);

                if (directory.find(folderName) == directory.end()) {
                    directory[folderName] = vector<string>();
                    cout << "Folder \"" << folderName << "\" created successfully.\n";
                } else {
                    cout << "Folder already exists.\n";
                }
                break;
            }

            case 2: {
                string folderName, fileName;
                cout << "Enter folder name: ";
                getline(cin, folderName);

                if (directory.find(folderName) != directory.end()) {
                    cout << "Enter file name: ";
                    getline(cin, fileName);

                    directory[folderName].push_back(fileName);
                    cout << "File \"" << fileName
                         << "\" added to folder \"" << folderName << "\".\n";
                } else {
                    cout << "Folder not found.\n";
                }
                break;
            }

            case 3: {
                if (directory.empty()) {
                    cout << "\nDirectory is empty.\n";
                } else {
                    cout << "\n========== DIRECTORY CONTENTS ==========\n";

                    for (map<string, vector<string>>::iterator it = directory.begin();
                         it != directory.end(); ++it) {
                        cout << "\nFolder: " << it->first << endl;

                        if (it->second.empty()) {
                            cout << "  No files in this folder.\n";
                        } else {
                            for (vector<string>::iterator fileIt = it->second.begin();
                                 fileIt != it->second.end(); ++fileIt) {
                                cout << "  - " << *fileIt << endl;
                            }
                        }
                    }
                }
                break;
            }

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}