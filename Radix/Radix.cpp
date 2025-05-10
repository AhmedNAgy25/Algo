#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getMax(const vector<int>& arr) {
    int max = arr[0];
    for (int num : arr) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = { 0 };

    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int maxNum = getMax(arr);

    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radixSort(arr);

    cout << "Sorted array:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}