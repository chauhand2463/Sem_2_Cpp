#include<iostream>
using namespace std;

class Student
{
private:
    string name;
    int rollNo;
    int marks[5];

public:
    void input()
    {
        cout<<"Enter Name: ";
        cin>>name;

        cout<<"Enter Roll Number: ";
        cin>>rollNo;

        cout<<"Enter marks of 5 subjects:\n";
        for(int i=0;i<5;i++)
        {
            cin>>marks[i];
        }
    }

    void display()
    {
        cout<<"\nName: "<<name<<endl;
        cout<<"Roll Number: "<<rollNo<<endl;
    }

    friend void calculateAverage(Student s);
};

void calculateAverage(Student s)
{
    int total = 0;

    for(int i=0;i<5;i++)
    {
        total += s.marks[i];
    }

    float avg = total / 5.0;

    cout<<"Average Marks: "<<avg<<endl;
}

int main()
{
    Student s[50];

    for(int i=0;i<50;i++)
    {
        cout<<"\nEnter details for Student "<<i+1<<endl;
        s[i].input();
    }

    cout<<"\n----- Student Records -----\n";

    for(int i=0;i<50;i++)
    {
        s[i].display();
        calculateAverage(s[i]);
    }

    return 0;
}