#include <iostream>
using namespace std;

class Employee
{
    string name;
    float basic, bonus;

public:
    
    Employee(string n, float b, float bo)
    {
        name = n;
        basic = b;
        bonus = bo;
    }

    
    inline float totalSalary()
    {
        return basic + bonus;
    }

    void display()
    {
        cout << "\nName: " << name;
        cout << "\nBasic Salary: " << basic;
        cout << "\nBonus: " << bonus;
        cout << "\nTotal Salary: " << totalSalary() << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee *emp[n];

    for(int i = 0; i < n; i++)
    {
        string name;
        float basic, bonus;
        int choice;

        cout << "\nEmployee " << i+1 << endl;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Basic Salary: ";
        cin >> basic;

        cout << "1. Default Bonus\n2. Custom Bonus\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
            bonus = 1000;   
        else
        {
            cout << "Enter Bonus: ";
            cin >> bonus;
        }

        emp[i] = new Employee(name, basic, bonus);
    }

    cout << "\nEmployee Details\n";

    for(int i = 0; i < n; i++)
    {
        emp[i]->display();
    }

    return 0;
}   