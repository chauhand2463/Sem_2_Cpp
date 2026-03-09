#include <iostream>
#include <string>

using namespace std;

const int MAX_ACCOUNTS = 100;

class Account {
private:
    string name;
    int accountId;
    double balance;

public:
    Account() {
        name = "";
        accountId = 0;
        balance = 0;
    }

    void createAccount(string n, int id, double initialBalance) {
        name = n;
        accountId = id;
        balance = initialBalance;
    }

    int getAccountId() {
        return accountId;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount.\n";
        } else if (amount > balance) {
            cout << "Withdrawal failed. Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        }
    }

    void display() {
        cout << "\n--- Account Summary ---\n";
        cout << "Customer Name : " << name << endl;
        cout << "Account ID    : " << accountId << endl;
        cout << "Balance       : " << balance << endl;
    }
};

int findAccount(Account accounts[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].getAccountId() == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice;

    do {
        cout << "\n==== Digital Savings Account System ====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Summary\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (accountCount >= MAX_ACCOUNTS) {
                    cout << "Account limit reached.\n";
                    break;
                }

                string name;
                int id;
                double initialBalance;

                cout << "Enter customer name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter unique account ID: ";
                cin >> id;

                if (findAccount(accounts, accountCount, id) != -1) {
                    cout << "Account ID already exists.\n";
                    break;
                }

                cout << "Enter initial balance (0 for zero balance): ";
                cin >> initialBalance;

                if (initialBalance < 0) {
                    initialBalance = 0;
                }

                accounts[accountCount].createAccount(name, id, initialBalance);
                accountCount++;

                cout << "Account created successfully.\n";
                break;
            }

            case 2: {
                int id;
                double amount;

                cout << "Enter account ID: ";
                cin >> id;

                int index = findAccount(accounts, accountCount, id);

                if (index == -1) {
                    cout << "Account not found.\n";
                } else {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    accounts[index].deposit(amount);
                }
                break;
            }

            case 3: {
                int id;
                double amount;

                cout << "Enter account ID: ";
                cin >> id;

                int index = findAccount(accounts, accountCount, id);

                if (index == -1) {
                    cout << "Account not found.\n";
                } else {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    accounts[index].withdraw(amount);
                }
                break;
            }

            case 4: {
                int id;
                cout << "Enter account ID: ";
                cin >> id;

                int index = findAccount(accounts, accountCount, id);

                if (index == -1) {
                    cout << "Account not found.\n";
                } else {
                    accounts[index].display();
                }
                break;
            }

            case 5:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
