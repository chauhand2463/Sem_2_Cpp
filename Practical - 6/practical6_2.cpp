#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void setPerson(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int empID;
    float salary;

public:
    void setEmployee(int id, float s) {
        empID = id;
        salary = s;
    }

    void displayEmployee() {
        cout << "Employee ID: " << empID << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    void setManager(string d) {
        department = d;
    }

    void displayManager() {
        displayPerson();
        displayEmployee();
        cout << "Department: " << department << endl;
    }
};

int main() {
    Manager m;

    m.setPerson("Amit", 35);
    m.setEmployee(101, 75000);
    m.setManager("Engineering");

    cout << "Manager Details:\n";
    m.displayManager();

    return 0;
}