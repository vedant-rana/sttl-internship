#include <iostream>
#include <vector>

int maxCoins(std::vector<int> &nums)
{
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));

    for (int k = 2; k <= n + 1; ++k)
    {
        for (int left = 0; left + k <= n + 1; ++left)
        {
            int right = left + k;
            for (int i = left + 1; i < right; ++i)
            {
                dp[left][right] = std::max(dp[left][right],
                                           nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
            }
        }
    }

    return dp[0][n + 1];
}

int main()
{

    std::vector<int> balloons = {3, 1, 5, 8};

    int result = maxCoins(balloons);

    std::cout << "Maximum coins that can be collected: " << result << std::endl;

    return 0;
}
