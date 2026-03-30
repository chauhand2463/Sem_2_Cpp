#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    Point& move(int dx, int dy) {
        this->x += dx;
        this->y += dy;
        return *this;
    }

    void display() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

void updatePoint(Point* p, int dx, int dy) {
    p->move(dx, dy);
}

int main() {
    int x, y;
    cout << "Enter initial x and y: ";
    cin >> x >> y;

    Point p(x, y);

    int dx1, dy1, dx2, dy2;
    cout << "Enter dx1 dy1: ";
    cin >> dx1 >> dy1;
    cout << "Enter dx2 dy2: ";
    cin >> dx2 >> dy2;

    p.move(dx1, dy1).move(dx2, dy2);
    p.display();

    int dx3, dy3;
    cout << "Enter dx3 dy3 for pointer update: ";
    cin >> dx3 >> dy3;

    updatePoint(&p, dx3, dy3);
    p.display();

    return 0;
}