#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// Helper function to print lines
void printLine(int count, char ch) {
    for (int i = 0; i < count; i++) cout << ch;
    cout << "\n";
}

class Item {
private:
    int itemID;
    string itemName;
    double price;
    int quantity;

public:
    // Default Constructor
    Item() : itemID(0), itemName(""), price(0.0), quantity(0) {}

    // Parameterized Constructor
    Item(int id, string name, double p, int qty) 
        : itemID(id), itemName(name), price(p), quantity(qty) {
        if (price < 0) price = 0;
        if (quantity < 0) quantity = 0;
    }

    // Setter methods
    void setItemID(int id) { itemID = id; }
    void setItemName(string name) { itemName = name; }
    void setPrice(double p) { if (p >= 0) price = p; }
    void setQuantity(int qty) { if (qty >= 0) quantity = qty; }

    // Getter methods
    int getItemID() const { return itemID; }
    string getItemName() const { return itemName; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    // Increase stock when shipment arrives
    void addStock(int units) {
        if (units > 0) {
            quantity += units;
            cout << "Added " << units << " units to stock. New quantity: " << quantity << endl;
        } else {
            cout << "Invalid quantity to add!" << endl;
        }
    }

    // Decrease stock when items are sold
    bool sellStock(int units) {
        if (units <= 0) {
            cout << "Invalid quantity to sell!" << endl;
            return false;
        }
        if (validateStock(units)) {
            quantity -= units;
            cout << "Sold " << units << " units. Remaining stock: " << quantity << endl;
            return true;
        }
        return false;
    }

    // Validate stock before sale
    bool validateStock(int units) const {
        if (units > quantity) {
            cout << "Insufficient stock! Available: " << quantity << ", Requested: " << units << endl;
            return false;
        }
        return true;
    }

    // Display item details
    void displayItemInfo() const {
        printf("%-8d %-20s $%-10.2f %-10d\n", itemID, itemName.c_str(), price, quantity);
    }

    // Calculate total value in stock
    double getTotalValue() const {
        return price * quantity;
    }
};

class Inventory {
private:
    Item items[100];
    int itemCount;

public:
    // Constructor
    Inventory() : itemCount(0) {}

    // Add item to inventory
    void addItem(const Item& item) {
        if (itemCount < 100) {
            items[itemCount++] = item;
            cout << "Item added to inventory." << endl;
        } else {
            cout << "Inventory is full! Cannot add more items." << endl;
        }
    }

    // Remove item from inventory by ID
    bool removeItem(int itemID) {
        for (int i = 0; i < itemCount; i++) {
            if (items[i].getItemID() == itemID) {
                cout << "Item ID " << itemID << " removed from inventory." << endl;
                // Shift items
                for (int j = i; j < itemCount - 1; j++) {
                    items[j] = items[j + 1];
                }
                itemCount--;
                return true;
            }
        }
        cout << "Item ID " << itemID << " not found!" << endl;
        return false;
    }

    // Find item by ID
    Item* findItem(int itemID) {
        for (int i = 0; i < itemCount; i++) {
            if (items[i].getItemID() == itemID) {
                return &items[i];
            }
        }
        return nullptr;
    }

    // Display all items
    void displayAllItems() const {
        if (itemCount == 0) {
            cout << "Inventory is empty!" << endl;
            return;
        }
        cout << "\n";
        printLine(60, '=');
        printf("%-8s %-20s %-12s %-10s\n", "ID", "Item Name", "Price", "Qty");
        printLine(60, '-');

        for (int i = 0; i < itemCount; i++) {
            items[i].displayItemInfo();
        }
        printLine(60, '=');
        cout << "\n";
    }

    // Calculate total inventory value
    double getTotalInventoryValue() const {
        double total = 0;
        for (int i = 0; i < itemCount; i++) {
            total += items[i].getTotalValue();
        }
        return total;
    }

    // Get number of items in inventory
    int getInventoryCount() const {
        return itemCount;
    }

    // Low stock alert
    void lowStockAlert(int threshold) const {
        cout << "\n";
        printLine(50, '-');
        cout << "Low Stock Alert (Threshold: " << threshold << ")\n";
        printLine(50, '-');
        bool found = false;
        for (int i = 0; i < itemCount; i++) {
            if (items[i].getQuantity() < threshold) {
                cout << items[i].getItemName() << " (ID: " << items[i].getItemID() 
                     << ") - Stock: " << items[i].getQuantity() << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "All items have sufficient stock.\n";
        }
        printLine(50, '-');
        cout << "\n";
    }
};

// Demo function
void displayMenu() {
    cout << "\n======== INVENTORY MANAGEMENT SYSTEM ========\n";
    cout << "1. Add Item          5. Display All Items\n";
    cout << "2. Add Stock         6. Total Value\n";
    cout << "3. Sell Item         7. Low Stock Alert\n";
    cout << "4. Remove Item       8. Exit\n";
    cout << "==============================================\n";
}

int main() {
    Inventory inventory;
    int choice;
    bool running = true;

    cout << "====== Digital Inventory Management System ======\n\n";

    while (running) {
        displayMenu();
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input!\n";
            continue;
        }

        switch (choice) {
            case 1: {
                int id, qty;
                string name;
                double price;

                cout << "\n--- Add New Item ---\n";
                cout << "Enter Item ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Item Name: ";
                getline(cin, name);
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Quantity: ";
                cin >> qty;

                if (price >= 0 && qty >= 0) {
                    Item newItem(id, name, price, qty);
                    inventory.addItem(newItem);
                } else {
                    cout << "Price and Quantity cannot be negative!" << endl;
                }
                break;
            }

            case 2: {
                int id, units;
                cout << "\n--- Add Stock ---\n";
                cout << "Enter Item ID: ";
                cin >> id;
                cout << "Enter Units to Add: ";
                cin >> units;

                Item* item = inventory.findItem(id);
                if (item != nullptr) {
                    item->addStock(units);
                } else {
                    cout << "Item ID " << id << " not found!\n";
                }
                break;
            }

            case 3: {
                int id, units;
                cout << "\n--- Sell Item ---\n";
                cout << "Enter Item ID: ";
                cin >> id;
                cout << "Enter Units to Sell: ";
                cin >> units;

                Item* item = inventory.findItem(id);
                if (item != nullptr) {
                    item->sellStock(units);
                } else {
                    cout << "Item ID " << id << " not found!\n";
                }
                break;
            }

            case 4: {
                int id;
                cout << "\n--- Remove Item ---\n";
                cout << "Enter Item ID to Remove: ";
                cin >> id;
                inventory.removeItem(id);
                break;
            }

            case 5: {
                inventory.displayAllItems();
                break;
            }

            case 6: {
                cout << "\n";
                printLine(50, '-');
                printf("Total Inventory Value: $%.2f\n", inventory.getTotalInventoryValue());
                cout << "Total Items in Inventory: " << inventory.getInventoryCount() << "\n";
                printLine(50, '-');
                cout << "\n";
                break;
            }

            case 7: {
                int threshold;
                cout << "\nEnter Low Stock Threshold: ";
                cin >> threshold;
                inventory.lowStockAlert(threshold);
                break;
            }

            case 8: {
                cout << "\nThank you!\n";
                running = false;
                break;
            }

            default: {
                cout << "Invalid choice!\n";
            }
        }
    }

    return 0;
}
