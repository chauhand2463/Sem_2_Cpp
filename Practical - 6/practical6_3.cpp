#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int year;

public:
    void setVehicle(string b, int y) {
        brand = b;
        year = y;
    }

    void displayVehicle() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle {
private:
    string model;
    float price;

public:
    void setCar(string m, float p) {
        model = m;
        price = p;
    }

    void displayCar() {
        displayVehicle();
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of cars: ";
    cin >> n;

    Car cars[100];

    for (int i = 0; i < n; i++) {
        string b, m;
        int y;
        float p;

        cout << "\nEnter details for car " << i + 1 << endl;
        cout << "Brand: ";
        cin >> b;
        cout << "Year: ";
        cin >> y;
        cout << "Model: ";
        cin >> m;
        cout << "Price: ";
        cin >> p;

        cars[i].setVehicle(b, y);
        cars[i].setCar(m, p);
    }

    cout << "\nCar Details:\n";

    for (int i = 0; i < n; i++) {
        cout << "\nCar " << i + 1 << endl;
        cars[i].displayCar();
    }

    return 0;
}