#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
public:
    float c;

    Celsius(float x = 0) {
        c = x;
    }

    operator Fahrenheit();

    bool operator==(Celsius other) {
        return c == other.c;
    }

    void display() {
        cout << c << " C" << endl;
    }
};

class Fahrenheit {
public:
    float f;

    Fahrenheit(float x = 0) {
        f = x;
    }

    operator Celsius() {
        return Celsius((f - 32) * 5 / 9);
    }

    bool operator==(Fahrenheit other) {
        return f == other.f;
    }

    void display() {
        cout << f << " F" << endl;
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((c * 9 / 5) + 32);
}

class Queue {
private:
    Fahrenheit arr[100];
    int front = 0, rear = -1;

public:
    void enqueue(Fahrenheit x) {
        arr[++rear] = x;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            arr[i].display();
        }
    }
};

int main() {
    Celsius c1(25), c2(30);
    Fahrenheit f1, f2;

    f1 = c1;
    f2 = c2;

    cout << "Celsius to Fahrenheit:\n";
    f1.display();
    f2.display();

    Celsius c3;
    c3 = f1;

    cout << "\nFahrenheit to Celsius:\n";
    c3.display();

    if (c1 == c2)
        cout << "\nTemperatures are equal\n";
    else
        cout << "\nTemperatures are not equal\n";

    Queue q;
    q.enqueue(f1);
    q.enqueue(f2);

    cout << "\nQueue (FIFO Storage):\n";
    q.display();

    int n;
    cout << "\nEnter number of Celsius values: ";
    cin >> n;

    Celsius arr[100];

    for (int i = 0; i < n; i++) {
        float val;
        cout << "Enter Celsius value: ";
        cin >> val;
        arr[i] = Celsius(val);
    }

    cout << "\nConverted Fahrenheit values (Array):\n";
    for (int i = 0; i < n; i++) {
        Fahrenheit temp = arr[i];
        temp.display();
    }

    return 0;
}