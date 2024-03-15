#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

pair<int, int> findDegree(const vector<int> &nums)
{
    unordered_map<int, int> frequency;
    unordered_map<int, int> firstIndex;
    int maxDegree = 0;
    int minLength = 200000;

    for (int i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];

        if (firstIndex.find(num) == firstIndex.end())
        {
            firstIndex[num] = i;
        }

        frequency[num]++;

        if (frequency[num] > maxDegree)
        {
            maxDegree = frequency[num];
            minLength = i - firstIndex[num] + 1;
        }
        else if (frequency[num] == maxDegree)
        {
            minLength = min(minLength, i - firstIndex[num] + 1);
        }
    }

    return {maxDegree, minLength};
}

int main()
{

    vector<int> nums = {1, 2, 2, 3, 1, 4, 2};

    pair<int, int> result = findDegree(nums);

    cout << "Degree of the array: " << result.first << endl;
    cout << "Minimum length of subarray with the same degree: " << result.second << endl;

    return 0;
}
