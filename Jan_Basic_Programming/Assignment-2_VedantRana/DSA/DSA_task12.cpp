#include <iostream>
#include <vector>

using namespace std;

int minOperationsForPairing(int N, vector<int>& arr) {
    int operations = 0;

    for (int i = 0; i < N; ++i) {
        if (arr[i] == i || arr[i] == i + 1) {
            
            continue;
        } else {
            
            std::swap(arr[i], arr[i + 1]);
            operations++;
        }
    }

    return operations;
}

int main() {
    
    int N1 = 2;
    vector<int> arr1 = {3, 0, 2, 1};
    int operations1 = minOperationsForPairing(N1, arr1);
    cout << "Minimum operations for N = 2: " << operations1 << endl;

    int N2 = 3;
    vector<int> arr2 = {1, 0, 3, 2, 4, 5};
    int operations2 = minOperationsForPairing(N2, arr2);
    cout << "Minimum operations for N = 3: " << operations2 << endl;

    return 0;
}
