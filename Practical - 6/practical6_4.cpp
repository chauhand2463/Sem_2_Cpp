#include <iostream>
using namespace std;

class Account {
protected:
    int accNo;
    float balance;

public:
    void setAccount(int a, float b) {
        accNo = a;
        balance = b;
    }

    void deposit(float amt) {
        balance += amt;
    }

    void withdraw(float amt) {
        if (amt <= balance)
            balance -= amt;
        else
            cout << "Insufficient balance" << endl;
    }

    void display() {
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Savings : public Account {
private:
    float interestRate;

public:
    void setSavings(float r) {
        interestRate = r;
    }

    void addInterest() {
        balance += balance * interestRate / 100;
    }

    void displaySavings() {
        display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class Current : public Account {
private:
    float overdraftLimit;

public:
    void setCurrent(float limit) {
        overdraftLimit = limit;
    }

    void withdraw(float amt) {
        if (amt <= balance + overdraftLimit)
            balance -= amt;
        else
            cout << "Overdraft limit exceeded" << endl;
    }

    void displayCurrent() {
        display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    Savings s;
    Current c;

    s.setAccount(101, 5000);
    s.setSavings(5);
    s.deposit(1000);
    s.addInterest();

    cout << "Savings Account:\n";
    s.displaySavings();

    cout << endl;

    c.setAccount(201, 3000);
    c.setCurrent(2000);
    c.withdraw(4000);

    cout << "Current Account:\n";
    c.displayCurrent();

    return 0;
}