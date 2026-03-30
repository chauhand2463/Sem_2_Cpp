#include <iostream>

class DynamicArray {
    int* data;
    int size;
    int capacity;
public:
    DynamicArray() : data(nullptr), size(0), capacity(2) {
        data = new int[capacity];
    }
    ~DynamicArray() {
        delete[] data;
    }
    void insert(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; ++i) newData[i] = data[i];
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }
    void deleteAt(int index) {
        if (index < 0 || index >= size) return;
        for (int i = index; i < size - 1; ++i) data[i] = data[i + 1];
        --size;
    }
    void display() const {
        std::cout << "Array contents: ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << ' ';
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray arr;
    int choice, value, pos;
    while (true) {
        std::cout << "Enter operation (1=Insert, 2=Delete, 3=Display, 0=Exit): ";
        if (!(std::cin >> choice)) break;
        if (choice == 0) {
            break;
        }
        if (choice == 1) {
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            arr.insert(value);
        } else if (choice == 2) {
            std::cout << "Enter position to delete (0-indexed): ";
            std::cin >> pos;
            arr.deleteAt(pos);
        } else if (choice == 3) {
            arr.display();
        } else {
            std::cout << "Invalid operation" << std::endl;
        }
    }
    return 0;
}
