#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Account {
private:
    double principal{};
    double annualRate{};
    int months{};
    int loan_id{};
    string applicant_name;

public:
    void input() {
        cout << "Enter Loan ID: ";
        cin >> loan_id;

        cout << "Enter Applicant Name: ";
        getline(cin >> ws, applicant_name);

        cout << "Enter Principal Amount: ";
        cin >> principal;

        cout << "Enter Annual Interest Rate (%): ";
        cin >> annualRate;

        cout << "Enter Time (in months): ";
        cin >> months;
    }

    double calculate_emi() const {
        if (months <= 0 || principal <= 0) {
            return 0.0;
        }

        double monthlyRate = annualRate / 12.0 / 100.0;

        if (monthlyRate == 0) {
            return principal / months;
        }

        double factor = pow(1 + monthlyRate, months);
        return (principal * monthlyRate * factor) / (factor - 1);
    }

    void display() const {
        cout << "\nLoan ID: " << loan_id << endl;
        cout << "Applicant Name: " << applicant_name << endl;
        cout << "Monthly EMI: " << calculate_emi() << endl;
    }
};

int main() {
    Account acc1, acc2;

    acc1.input();
    acc1.display();

    acc2.input();
    acc2.display();

    return 0;
}