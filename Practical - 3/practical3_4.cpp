#include <iostream>
using namespace std;

template <typename T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

template <typename T>
void reverseArray(T arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

template <typename T>
void leaders(T arr[], int n) {
    T maxRight = arr[n - 1];
    cout << maxRight << " ";
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            maxRight = arr[i];
            cout << maxRight << " ";
        }
    }
    cout << endl;
}

int main() {
    int choice, n;

    cout << "Select Data Type:\n1. Integer\n2. Float\n3. Character\n";
    cin >> choice;

    cout << "Enter size: ";
    cin >> n;

    if (choice == 1) {
        int arr[100];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << "Array: ";
        display(arr, n);

        cout << "Max: " << findMax(arr, n) << endl;

        reverseArray(arr, n);
        cout << "Reversed: ";
        display(arr, n);

        cout << "Leaders: ";
        leaders(arr, n);
    }

    else if (choice == 2) {
        float arr[100];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << "Array: ";
        display(arr, n);

        cout << "Max: " << findMax(arr, n) << endl;

        reverseArray(arr, n);
        cout << "Reversed: ";
        display(arr, n);

        cout << "Leaders: ";
        leaders(arr, n);
    }

    else if (choice == 3) {
        char arr[100];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << "Array: ";
        display(arr, n);

        cout << "Max: " << findMax(arr, n) << endl;

        reverseArray(arr, n);
        cout << "Reversed: ";
        display(arr, n);

        cout << "Leaders: ";
        leaders(arr, n);
    }

    return 0;
}