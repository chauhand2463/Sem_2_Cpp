#include <iostream>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    int copies;

public:
    void setData() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Copies: ";
        cin >> copies;
    }

    int getId() const {
        return id;
    }

    void issue() {
        if (copies > 0) {
            copies--;
            cout << "Book issued.\n";
        } else {
            cout << "No copies available.\n";
        }
    }

    void giveBack() {
        copies++;
        cout << "Book returned.\n";
    }

    void show() const {
        cout << "\nID: " << id
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nCopies: " << copies << endl;
    }
};

int main() {
    const int MAX = 20;
    Book books[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n1. Add Book";
        cout << "\n2. Issue Book";
        cout << "\n3. Return Book";
        cout << "\n4. Display All Books";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count >= MAX) {
                cout << "Library full.\n";
            } else {
                books[count].setData();
                count++;
                cout << "Book added.\n";
            }
        } 
        else if (choice == 2) {
            int id, found = -1;
            cout << "Enter Book ID: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (books[i].getId() == id) {
                    found = i;
                    break;
                }
            }

            if (found != -1)
                books[found].issue();
            else
                cout << "Book not found.\n";
        } 
        else if (choice == 3) {
            int id, found = -1;
            cout << "Enter Book ID: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (books[i].getId() == id) {
                    found = i;
                    break;
                }
            }

            if (found != -1)
                books[found].giveBack();
            else
                cout << "Book not found.\n";
        } 
        else if (choice == 4) {
            cout << "\nTotal books: " << count << endl;
            for (int i = 0; i < count; i++) {
                books[i].show();
            }
        } 
        else if (choice == 5) {
            cout << "Exiting...\n";
        } 
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
