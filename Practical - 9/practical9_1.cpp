#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void displayVector(const vector<int>& numbers) {
    for (vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void manualReverse(vector<int>& numbers) {
    vector<int>::iterator left = numbers.begin();
    vector<int>::iterator right = numbers.end() - 1;

    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        ++left;
        --right;
    }
}

int main() {
    vector<int> numbers;
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        numbers.push_back(value);
    }

    cout << "\nOriginal Vector: ";
    displayVector(numbers);

    vector<int> reversedUsingLibrary = numbers;
    reverse(reversedUsingLibrary.begin(), reversedUsingLibrary.end());

    cout << "Reversed using std::reverse(): ";
    displayVector(reversedUsingLibrary);

    vector<int> manuallyReversed = numbers;
    manualReverse(manuallyReversed);

    cout << "Reversed using manual iterator swapping: ";
    displayVector(manuallyReversed);

    return 0;
}
