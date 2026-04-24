#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> numbers;
    set<int> uniqueNumbers;
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        numbers.push_back(value);
        uniqueNumbers.insert(value);
    }

    cout << "\nOriginal List:\n";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }

    cout << "\n\nUnique Elements (Duplicates Removed):\n";
    for (set<int>::iterator it = uniqueNumbers.begin(); it != uniqueNumbers.end(); ++it) {
        cout << *it << " ";
    }

    vector<int> uniqueVector(uniqueNumbers.begin(), uniqueNumbers.end());

    cout << "\n\nUnique Elements Stored in Vector:\n";
    for (vector<int>::iterator it = uniqueVector.begin(); it != uniqueVector.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}