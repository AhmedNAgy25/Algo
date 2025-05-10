#include <iostream>
#include <vector>
using namespace std;

void inputVector(vector<int>& vec, int size) {
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        int value;
        cin >> value;
        vec.push_back(value);
    }
}

int linearSearch(const vector<int>& vec, int target) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    int size, searchElement;

    cout << "Enter the size of the vector: ";
    cin >> size;

    vector<int> vec;
    vec.reserve(size);

    inputVector(vec, size);

    cout << "Enter the element to search: ";
    cin >> searchElement;

    int index = linearSearch(vec, searchElement);

    if (index != -1) {
        cout << "Element found at index " << index << " (position " << index + 1 << ")." << endl;
    }
    else {
        cout << "Element not found in the vector." << endl;
    }

    return 0;
}