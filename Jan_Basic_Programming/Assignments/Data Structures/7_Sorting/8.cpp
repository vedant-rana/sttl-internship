#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void countingSort(vector<int>& arr, int exp) {
    const int n = arr.size();
    vector<int> output(n);
    const int radix = 10;

    vector<int> count(radix, 0);

    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % radix]++;
    }

    for (int i = 1; i < radix; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int maxElement = getMax(arr);

    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
