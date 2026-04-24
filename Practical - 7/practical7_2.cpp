#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2), c3, c4;

    c3 = c1 + c2;
    c4 = c1 - c2;

    cout << "Addition: ";
    c3.display();

    cout << "Subtraction: ";
    c4.display();

    int n;
    cout << "\nEnter number of complex numbers: ";
    cin >> n;

    Complex arr[100];

    for (int i = 0; i < n; i++) {
        float r, im;
        cout << "Enter real and imaginary part: ";
        cin >> r >> im;
        arr[i] = Complex(r, im);
    }

    cout << "\nStored Complex Numbers:\n";
    for (int i = 0; i < n; i++) {
        arr[i].display();
    }

    return 0;
}