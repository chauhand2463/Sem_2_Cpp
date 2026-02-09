#include <iostream>
using namespace std;

class Student {
    int roll;
    int m1, m2, m3;
    float avg;

public:
    Student();      // default constructor declaration
    void display();
};

// Default constructor definition (outside class)
Student::Student() {
    roll = 1;
    m1 = 60;
    m2 = 70;
    m3 = 80;
    avg = (m1 + m2 + m3) / 3.0;
}

void Student::display() {
    cout << "Roll No: " << roll << endl;
    cout << "Marks: " << m1 << ", " << m2 << ", " << m3 << endl;
    cout << "Average: " << avg << endl;
}

int main() {
    // Array of objects
    Student s[3];

    // Display records
    for (int i = 0; i < 3; i++) {
        s[i].display();
    }

    return 0;
}
