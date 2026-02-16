#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l = 1, double w = 1) {
        setLength(l);
        setWidth(w);
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }

    void setLength(double l) {
        length = (l > 0) ? l : 1;
    }

    void setWidth(double w) {
        width = (w > 0) ? w : 1;
    }

    double calculateArea() const {
        return length * width;
    }

    double calculatePerimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    int n;
    std::cout << "Enter number of rectangles (max 10): ";
    std::cin >> n;

    if (n < 1 || n > 10) {
        std::cout << "Invalid number of rectangles." << std::endl;
        return 0;
    }

    Rectangle rectangles[10];  // fixed-size array

    for (int i = 0; i < n; i++) {
        double l, w;
        std::cout << "\nRectangle " << i + 1 << std::endl;
        std::cout << "Enter length: ";
        std::cin >> l;
        std::cout << "Enter width: ";
        std::cin >> w;

        rectangles[i].setLength(l);
        rectangles[i].setWidth(w);
    }

    std::cout << "\n--- Rectangle Details ---\n";
    for (int i = 0; i < n; i++) {
        std::cout << "\nRectangle " << i + 1 << std::endl;
        std::cout << "Length: " << rectangles[i].getLength() << std::endl;
        std::cout << "Width: " << rectangles[i].getWidth() << std::endl;
        std::cout << "Area: " << rectangles[i].calculateArea() << std::endl;
        std::cout << "Perimeter: " << rectangles[i].calculatePerimeter() << std::endl;
    }

    // Update a rectangle
    int index;
    std::cout << "\nEnter rectangle number to update (1 to " << n << "): ";
    std::cin >> index;

    if (index >= 1 && index <= n) {
        double newL, newW;
        std::cout << "Enter new length: ";
        std::cin >> newL;
        std::cout << "Enter new width: ";
        std::cin >> newW;

        rectangles[index - 1].setLength(newL);
        rectangles[index - 1].setWidth(newW);

        std::cout << "\nUpdated Rectangle " << index << std::endl;
        std::cout << "Area: " << rectangles[index - 1].calculateArea() << std::endl;
        std::cout << "Perimeter: " << rectangles[index - 1].calculatePerimeter() << std::endl;
    } else {
        std::cout << "Invalid rectangle number." << std::endl;
    }

    return 0;
}
