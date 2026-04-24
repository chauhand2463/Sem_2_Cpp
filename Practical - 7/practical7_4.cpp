#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Shape {
public:
    virtual double Area() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override {
        return length * width;
    }

    void display() const override {
        cout << "Rectangle (Length = " << length
             << ", Width = " << width
             << ") -> Area = " << Area() << endl;
    }
};

class Circle : public Shape {
    double radius;
    static constexpr double PI = 3.141592653589793;

public:
    Circle(double r) : radius(r) {}

    double Area() const override {
        return PI * radius * radius;
    }

    void display() const override {
        cout << "Circle (Radius = " << radius
             << ") -> Area = " << Area() << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    vector<Shape*> dynamicShapes;
    dynamicShapes.push_back(new Rectangle(10, 5));
    dynamicShapes.push_back(new Circle(7));
    dynamicShapes.push_back(new Rectangle(8, 4));
    dynamicShapes.push_back(new Circle(3.5));

    cout << "Dynamic Collection:\n";
    for (Shape* shape : dynamicShapes) {
        shape->display();
    }

    Shape* staticShapes[4];
    staticShapes[0] = new Rectangle(6, 3);
    staticShapes[1] = new Circle(5);
    staticShapes[2] = new Rectangle(12, 2);
    staticShapes[3] = new Circle(9);

    cout << "\nStatic Collection:\n";
    for (int i = 0; i < 4; ++i) {
        staticShapes[i]->display();
    }

    for (Shape* shape : dynamicShapes) {
        delete shape;
    }

    for (int i = 0; i < 4; ++i) {
        delete staticShapes[i];
    }

    return 0;
}