#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Item {
public:
    char name[50];
    int quantity;
    float price;
};

void addItem() {
    ofstream file("inventory.txt", ios::app);
    Item item;

    cout << "Enter item name: ";
    cin >> item.name;
    cout << "Enter quantity: ";
    cin >> item.quantity;
    cout << "Enter price: ";
    cin >> item.price;

    file << item.name << " " << item.quantity << " " << item.price << endl;
    file.close();
}

void viewItems() {
    ifstream file("inventory.txt");
    Item item;

    while (file >> item.name >> item.quantity >> item.price) {
        cout << "Name: " << item.name
             << " Quantity: " << item.quantity
             << " Price: " << item.price << endl;
    }

    file.close();
}

void searchItem() {
    ifstream file("inventory.txt");
    Item item;
    char searchName[50];
    int found = 0;

    cout << "Enter item name to search: ";
    cin >> searchName;

    while (file >> item.name >> item.quantity >> item.price) {
        if (strcmp(item.name, searchName) == 0) {
            cout << "Name: " << item.name
                 << " Quantity: " << item.quantity
                 << " Price: " << item.price << endl;
            found = 1;
        }
    }

    if (!found) {
        cout << "Item not found" << endl;
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Item\n2. View All Items\n3. Search Item\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewItems(); break;
            case 3: searchItem(); break;
            case 4: break;
            default: cout << "Invalid choice";
        }
    } while (choice != 4);

    return 0;
}