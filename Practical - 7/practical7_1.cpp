#include <iostream>
using namespace std;

class Calculator {
private:
    float results[100];
    int count = 0;

public:
    int add(int a, int b) {
        int res = a + b;
        results[count++] = res;
        return res;
    }

    float add(float a, float b) {
        float res = a + b;
        results[count++] = res;
        return res;
    }

    float add(int a, float b) {
        float res = a + b;
        results[count++] = res;
        return res;
    }

    float add(float a, int b) {
        float res = a + b;
        results[count++] = res;
        return res;
    }

    void displayResults() {
        cout << "\nStored Results:\n";
        for (int i = 0; i < count; i++) {
            cout << results[i] << endl;
        }
    }
};

int main() {
    Calculator calc;

    cout << "Int + Int: " << calc.add(10, 5) << endl;
    cout << "Float + Float: " << calc.add(2.5f, 3.5f) << endl;
    cout << "Int + Float: " << calc.add(7, 2.3f) << endl;
    cout << "Float + Int: " << calc.add(4.2f, 6) << endl;

    calc.displayResults();

    return 0;
}