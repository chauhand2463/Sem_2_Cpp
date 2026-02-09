#include <iostream>
using namespace std;

class Student {
    int roll;
    int m1, m2, m3;
    float avg;

public:
    // Default constructor
    Student() {
        roll = 1;
        m1 = 60;
        m2 = 70;
        m3 = 80;
        avg = (m1 + m2 + m3) / 3.0;
    }

    void display() {
        cout << "Roll No: " << roll << endl;
        cout << "Marks: " << m1 << ", " << m2 << ", " << m3 << endl;
        cout << "Average: " << avg << endl;
    }
};

int main() {
    // Array of student objects
    Student s[3];

    // Display all student records
    for (int i = 0; i < 3; i++) {
        s[i].display();
    }

    return 0;
}
