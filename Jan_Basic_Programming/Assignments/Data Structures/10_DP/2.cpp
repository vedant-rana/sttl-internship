#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int lengthOfLIS(const vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    int result = lengthOfLIS(nums);

    cout << "Length of the Longest Increasing Subsequence: " << result << endl;

    return 0;
}
