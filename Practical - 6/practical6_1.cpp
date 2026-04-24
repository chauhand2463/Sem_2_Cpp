#include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    void setRadius(float r) {
        radius = r;
    }

    float getArea() {
        return 3.1416 * radius * radius;
    }
};

int main() {
    int n;
    cout << "Enter number of circles: ";
    cin >> n;

    Circle c[100];

    for (int i = 0; i < n; i++) {
        float r;
        cout << "Enter radius of circle " << i + 1 << ": ";
        cin >> r;
        c[i].setRadius(r);
    }

    cout << "\nAreas of circles:\n";

    for (int i = 0; i < n; i++) {
        cout << "Circle " << i + 1 << ": " << c[i].getArea() << endl;
    }

    return 0;
}