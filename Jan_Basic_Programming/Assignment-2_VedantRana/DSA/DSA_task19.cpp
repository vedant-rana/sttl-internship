#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool isSubsetSumEqual(const vector<int>& arr, int n, vector<int>& subsetSum, vector<bool>& taken, int targetSum, int k, int curIdx, int limitIdx) {
    if (subsetSum[curIdx] == targetSum) {
        if (curIdx == k - 2) {
            return true;
        }
        return isSubsetSumEqual(arr, n, subsetSum, taken, targetSum, k, curIdx + 1, n - 1);
    }

    for (int i = limitIdx; i >= 0; --i) {
        if (taken[i]) {
            continue;
        }

        int temp = subsetSum[curIdx] + arr[i];

        if (temp <= targetSum) {
            taken[i] = true;
            subsetSum[curIdx] += arr[i];

            bool next = isSubsetSumEqual(arr, n, subsetSum, taken, targetSum, k, curIdx, i - 1);

            taken[i] = false;
            subsetSum[curIdx] -= arr[i];

            if (next) {
                return true;
            }
        }
    }

    return false;
}

bool canPartitionKSubsets(const vector<int>& arr, int n, int k) {
    if (k == 1) {
        return true;
    }

    if (n < k) {
        return false;
    }

    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % k != 0) {
        return false;
    }

    int targetSum = sum / k;
    vector<int> subsetSum(k, 0);
    vector<bool> taken(n, false);

    subsetSum[0] = arr[n - 1];
    taken[n - 1] = true;

    return isSubsetSumEqual(arr, n, subsetSum, taken, targetSum, k, 0, n - 1);
}

int main() {
    vector<int> arr1 = {2, 1, 4, 5, 6};
    int k1 = 3;

    vector<int> arr2 = {2, 1, 5, 5, 6};
    int k2 = 3;

    if (canPartitionKSubsets(arr1, arr1.size(), k1)) {
        cout << "Partition possible into " << k1 << " subsets with equal sum.\n";
    } else {
        cout << "Partition not possible into " << k1 << " subsets with equal sum.\n";
    }

    if (canPartitionKSubsets(arr2, arr2.size(), k2)) {
        cout << "Partition possible into " << k2 << " subsets with equal sum.\n";
    } else {
        cout << "Partition not possible into " << k2 << " subsets with equal sum.\n";
    }

    return 0;
}
