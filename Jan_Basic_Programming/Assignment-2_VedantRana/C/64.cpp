#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minJumpsToReachEnd(const vector<int> &nums)
{
    int n = nums.size();

    if (n <= 1)
    {
        return 0;
    }

    vector<int> jumps(n, INT_MAX);
    jumps[0] = 0;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {

            if (j + nums[j] >= i)
            {

                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
    }

    return jumps[n - 1];
}

int main()
{

    vector<int> nums = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};

    int result = minJumpsToReachEnd(nums);

    cout << "Minimum number of jumps to reach the end: " << result << endl;

    return 0;
}
