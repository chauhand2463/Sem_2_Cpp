#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GradingSystem {
protected:
    double marks;

public:
    GradingSystem(double m) : marks(m) {}
    virtual string computeGrade() const = 0;
    virtual void display() const = 0;
    virtual ~GradingSystem() {}
};

class Undergraduate : public GradingSystem {
    string name;

public:
    Undergraduate(string n, double m) : GradingSystem(m), name(n) {}

    string computeGrade() const override {
        if (marks >= 90) return "A+";
        else if (marks >= 80) return "A";
        else if (marks >= 70) return "B+";
        else if (marks >= 60) return "B";
        else if (marks >= 50) return "C";
        else if (marks >= 40) return "D";
        else return "F";
    }

    void display() const override {
        cout << "Undergraduate Student\n";
        cout << "Name  : " << name << endl;
        cout << "Marks : " << marks << endl;
        cout << "Grade : " << computeGrade() << endl;
        cout << "-----------------------------\n";
    }
};

class Postgraduate : public GradingSystem {
    string name;

public:
    Postgraduate(string n, double m) : GradingSystem(m), name(n) {}

    string computeGrade() const override {
        if (marks >= 95) return "A+";
        else if (marks >= 85) return "A";
        else if (marks >= 75) return "B+";
        else if (marks >= 65) return "B";
        else if (marks >= 55) return "C";
        else if (marks >= 50) return "D";
        else return "F";
    }

    void display() const override {
        cout << "Postgraduate Student\n";
        cout << "Name  : " << name << endl;
        cout << "Marks : " << marks << endl;
        cout << "Grade : " << computeGrade() << endl;
        cout << "-----------------------------\n";
    }
};

int main() {
    vector<GradingSystem*> students;
    int n, choice;
    string name;
    double marks;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "1. Undergraduate\n2. Postgraduate\nEnter choice: ";
        cin >> choice;

        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter marks: ";
        cin >> marks;

        if (choice == 1)
            students.push_back(new Undergraduate(name, marks));
        else if (choice == 2)
            students.push_back(new Postgraduate(name, marks));
        else {
            cout << "Invalid choice. Skipping student.\n";
        }
    }

    cout << "\nStudent Grade Report\n";
    cout << "=============================\n";

    for (const auto& student : students) {
        student->display();
    }

    for (auto& student : students) {
        delete student;
    }

    return 0;
}