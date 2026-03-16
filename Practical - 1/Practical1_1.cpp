#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    int walletId;
    string userName;
    double balance;

public:
   
    Wallet(int id, string name, double initialBalance = 0.0) {
        walletId = id;
        userName = name;
        balance = initialBalance;
    }

    void loadMoney(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount loaded successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void transferMoney(Wallet &receiver, double amount) {
        if (amount <= 0) {
            cout << "Invalid transfer amount.\n";
        } 
        else if (amount > balance) {
            cout << "Error: Insufficient balance for transfer.\n";
        } 
        else {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transfer successful.\n";
        }
    }

    void displayDetails() const {
        cout << "Wallet ID: " << walletId << endl;
        cout << "User Name: " << userName << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    Wallet user1(101, "Alice", 1000);
    Wallet user2(102, "Bob", 500);

    user1.loadMoney(500);
    user1.transferMoney(user2, 300);

    cout << "\nUser 1 Details:\n";
    user1.displayDetails();

    cout << "\nUser 2 Details:\n";
    user2.displayDetails();

    return 0;
}
