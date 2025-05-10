#include <iostream>
#include <vector>

using namespace std;

void readArray(vector<int>& arr) {
    cout << "Please enter numbers:" << endl;
    for (int& num : arr) {
        cin >> num;
    }
}

int findMaxValue(const vector<int>& arr) {
    int maxValue = 0;
    for (int num : arr) {
        maxValue = max(maxValue, num);
    }
    return maxValue;
}

vector<int> calculateFrequency(const vector<int>& arr, int maxValue) {
    vector<int> freq(maxValue + 1, 0);
    for (int num : arr) {
        freq[num]++;
    }
    return freq;
}

void buildPrefixSum(vector<int>& freq) {
    for (int i = 1; i < freq.size(); i++) {
        freq[i] += freq[i - 1];
    }
}

vector<int> placeElements(const vector<int>& arr, vector<int>& freq) {
    vector<int> sortedArr(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        int index = freq[arr[i]] - 1;
        sortedArr[index] = arr[i];
        freq[arr[i]]--;
    }
    return sortedArr;
}

vector<int> countingSort(const vector<int>& arr) {
    int maxValue = findMaxValue(arr);
    vector<int> freq = calculateFrequency(arr, maxValue);
    buildPrefixSum(freq);
    return placeElements(arr, freq);
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    cout << "Please enter size of arr:" << endl;
    int n;
    cin >> n;

    vector<int> arr(n);
    readArray(arr);

    vector<int> sortedArr = countingSort(arr);

    printArray(sortedArr);

    return 0;
}