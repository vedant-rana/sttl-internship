#include <iostream>
#include <unordered_map>
#include <vector>

int countSubarraysWithSum(std::vector<int> &nums, int targetSum)
{
    int n = nums.size();
    std::unordered_map<int, int> prefixSumCount;

    int currentSum = 0;
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        currentSum += nums[i];

        if (currentSum == targetSum)
        {
            count++;
        }

        if (prefixSumCount.find(currentSum - targetSum) != prefixSumCount.end())
        {
            count += prefixSumCount[currentSum - targetSum];
        }

        prefixSumCount[currentSum]++;
    }

    return count;
}

int main()
{

    std::vector<int> nums = {10, 2, -2, -20, 10};
    int targetSum = -10;

    int result = countSubarraysWithSum(nums, targetSum);

    std::cout << "Number of subarrays with sum " << targetSum << ": " << result << std::endl;

    return 0;
}
