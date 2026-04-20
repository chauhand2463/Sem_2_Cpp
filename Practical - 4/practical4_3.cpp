#include <iostream>
using namespace std;

int main() {
    int n, m;

    // Step 1: Read sizes
    cout << "Enter size of first array (n): ";
    cin >> n;

    cout << "Enter size of second array (m): ";
    cin >> m;

    // Step 2: Dynamic allocation
    int* arr1 = new int[n];
    int* arr2 = new int[m];

    // Step 3: Input sorted arrays
    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    // Step 4: Allocate merged array
    int* merged = new int[n + m];

    int i = 0, j = 0, k = 0;

    // Step 5: Merge process
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements
    while (i < n) {
        merged[k++] = arr1[i++];
    }

    while (j < m) {
        merged[k++] = arr2[j++];
    }

    // Step 6: Display result
    cout << "Merged Sorted Array:\n";
    for (int i = 0; i < n + m; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    // Step 7: Free memory
    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    return 0;
}