#include <iostream>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;
    static int totalAccounts;

public:
    Account() {}

    Account(int accNo, string n, double bal) {
        accountNumber = accNo;
        name = n;
        balance = bal;
        totalAccounts++;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }

    void updateName(string newName) {
        name = newName;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }
};

int Account::totalAccounts = 0;

Account* findAccount(Account* accounts, int size, int accNo) {
    for (int i = 0; i < size; i++) {
        if (accounts[i].getAccountNumber() == accNo)
            return &accounts[i];
    }
    return nullptr;
}

int main() {
    Account* accounts = nullptr;
    int size = 0;
    int choice;

    do {
        cout << "\n1. Add Account\n2. Update Account\n3. Display Account\n4. Transfer Money\n5. Total Accounts\n6. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int accNo;
            string name;
            double balance;

            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> balance;

            Account* temp = new Account[size + 1];
            for (int i = 0; i < size; i++)
                temp[i] = accounts[i];

            temp[size] = Account(accNo, name, balance);

            delete[] accounts;
            accounts = temp;
            size++;
        }

        else if (choice == 2) {
            int accNo;
            string newName;

            cout << "Enter Account Number: ";
            cin >> accNo;

            Account* acc = findAccount(accounts, size, accNo);
            if (acc) {
                cout << "Enter New Name: ";
                cin >> newName;
                acc->updateName(newName);
            } else {
                cout << "Account not found\n";
            }
        }

        else if (choice == 3) {
            int accNo;

            cout << "Enter Account Number: ";
            cin >> accNo;

            Account* acc = findAccount(accounts, size, accNo);
            if (acc) {
                acc->display();
            } else {
                cout << "Account not found\n";
            }
        }

        else if (choice == 4) {
            int fromAcc, toAcc;
            double amount;

            cout << "Enter From Account: ";
            cin >> fromAcc;
            cout << "Enter To Account: ";
            cin >> toAcc;
            cout << "Enter Amount: ";
            cin >> amount;

            Account* sender = findAccount(accounts, size, fromAcc);
            Account* receiver = findAccount(accounts, size, toAcc);

            if (sender && receiver) {
                if (sender->withdraw(amount)) {
                    receiver->deposit(amount);
                    cout << "Transfer Successful\n";
                } else {
                    cout << "Insufficient Balance\n";
                }
            } else {
                cout << "Invalid Account\n";
            }
        }

        else if (choice == 5) {
            cout << "Total Accounts: " << Account::getTotalAccounts() << endl;
        }

    } while (choice != 6);

    delete[] accounts;
    return 0;
}