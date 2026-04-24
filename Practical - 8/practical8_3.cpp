#include <iostream>
#include <string>
using namespace std;

class InsufficientFundsException {
public:
    const char* what() const {
        return "Withdrawal amount exceeds available balance.";
    }
};

class InvalidAmountException {
public:
    const char* what() const {
        return "Amount must be greater than zero.";
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0.0) {
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0)
            throw InvalidAmountException();

        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw InvalidAmountException();

        if (amount > balance)
            throw InsufficientFundsException();

        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

string logs[100];
int logIndex = 0;

void addLog(const string& message) {
    if (logIndex < 100)
        logs[logIndex++] = message;
}

void processWithdrawal(BankAccount& account, double amount) {
    addLog("Entered processWithdrawal()");
    account.withdraw(amount);
    addLog("Withdrawal successful");
    addLog("Exiting processWithdrawal()");
}

void performTransaction(BankAccount& account, double amount) {
    addLog("Entered performTransaction()");
    processWithdrawal(account, amount);
    addLog("Exiting performTransaction()");
}

int main() {
    BankAccount account(5000);

    addLog("Program started");
    addLog("Initial balance: Rs. 5000");

    try {
        double withdrawAmount;

        cout << "Current Balance: Rs. " << account.getBalance() << endl;
        cout << "Enter amount to withdraw: Rs. ";
        cin >> withdrawAmount;

        performTransaction(account, withdrawAmount);

        cout << "\nTransaction completed successfully.\n";
        cout << "Remaining Balance: Rs. " << account.getBalance() << endl;
    }
    catch (InsufficientFundsException& e) {
        addLog("Exception caught in main(): InsufficientFundsException");
        cout << "\nTransaction Failed: " << e.what() << endl;
    }
    catch (InvalidAmountException& e) {
        addLog("Exception caught in main(): InvalidAmountException");
        cout << "\nTransaction Failed: " << e.what() << endl;
    }

    addLog("Program ended");

    cout << "\n\nTransaction Log (Stack Unwinding Demonstration)\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < logIndex; i++) {
        cout << i + 1 << ". " << logs[i] << endl;
    }

    return 0;
}