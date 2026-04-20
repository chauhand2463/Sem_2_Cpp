#include <iostream>
#include <iomanip>
using namespace std;

ostream& currency(ostream& out) {
    out << "₹";
    return out;
}

class Student {
public:
    string name;
    int marks;
    float fees;
};

int main() {
    Student s[3] = {
        {"Amit", 85, 15000.5},
        {"Riya", 92, 17500.75},
        {"Karan", 78, 14000.0}
    };

    cout << setfill('=') << setw(50) << "" << endl;
    cout << setfill(' ');

    cout << left << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Fees" << endl;

    cout << setfill('-') << setw(50) << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < 3; i++) {
        cout << left << setw(15) << s[i].name
             << setw(10) << s[i].marks
             << currency << fixed << setprecision(2) << s[i].fees
             << endl;
    }

    cout << setfill('=') << setw(50) << "" << endl;

    return 0;
}