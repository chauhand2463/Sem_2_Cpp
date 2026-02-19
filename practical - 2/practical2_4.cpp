#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

class Item {
public:
    int id;
    string name;
    double price;
    int quantity;

    void inputItem() {
        cout << "Enter Item ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Item Name: ";
        getline(cin, name);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayItem() {
        cout << id << "\t" << name << "\t" 
             << price << "\t" << quantity << endl;
    }
};

int main() {

    Item items[MAX];
    int itemCount = 0;
    int choice;

    while (true) {
        cout << "\n===== INVENTORY MENU =====\n";
        cout << "1. Add Item\n";
        cout << "2. Add Stock\n";
        cout << "3. Sell Item\n";
        cout << "4. Display Items\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            if (itemCount < MAX) {
                items[itemCount].inputItem();
                itemCount++;
                cout << "Item Added.\n";
            } else {
                cout << "Inventory Full.\n";
            }
        }

        else if (choice == 2) {
            int searchID, addQty;
            cout << "Enter Item ID: ";
            cin >> searchID;
            cout << "Enter Quantity to Add: ";
            cin >> addQty;

            for (int i = 0; i < itemCount; i++) {
                if (items[i].id == searchID) {
                    items[i].quantity += addQty;
                    cout << "Stock Updated.\n";
                    break;
                }
            }
        }

        else if (choice == 3) {
            int searchID, sellQty;
            cout << "Enter Item ID: ";
            cin >> searchID;
            cout << "Enter Quantity to Sell: ";
            cin >> sellQty;

            for (int i = 0; i < itemCount; i++) {
                if (items[i].id == searchID) {
                    if (sellQty <= items[i].quantity) {
                        items[i].quantity -= sellQty;
                        cout << "Item Sold.\n";
                    } else {
                        cout << "Not Enough Stock.\n";
                    }
                    break;
                }
            }
        }

        else if (choice == 4) {
            cout << "\nID\tName\tPrice\tQty\n";
            cout << "--------------------------------\n";
            for (int i = 0; i < itemCount; i++) {
                items[i].displayItem();
            }
        }

        else if (choice == 5) {
            cout << "Program Ended.\n";
            break;
        }

        else {
            cout << "Invalid Choice.\n";
        }
    }

    return 0;
}
