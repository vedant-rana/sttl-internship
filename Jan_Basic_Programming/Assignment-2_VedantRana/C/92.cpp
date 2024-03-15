#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Engineer
{
    int speed;
    int efficiency;
};

bool compareByEfficiency(const Engineer &a, const Engineer &b)
{
    return a.efficiency > b.efficiency;
}

long long maxPerformance(int n, std::vector<int> &speed, std::vector<int> &efficiency, int k)
{
    const int MOD = 1e9 + 7;

    std::vector<Engineer> engineers;
    for (int i = 0; i < n; ++i)
    {
        engineers.push_back({speed[i], efficiency[i]});
    }

    std::sort(engineers.begin(), engineers.end(), compareByEfficiency);

    long long result = 0;
    long long speedSum = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (const Engineer &engineer : engineers)
    {
        if (minHeap.size() == k)
        {
            speedSum -= minHeap.top();
            minHeap.pop();
        }

        minHeap.push(engineer.speed);
        speedSum += engineer.speed;

        result = std::max(result, speedSum * engineer.efficiency);
    }

    return result % MOD;
}

int main()
{

    int n = 6;
    std::vector<int> speed = {2, 10, 3, 1, 5, 8};
    std::vector<int> efficiency = {5, 4, 3, 9, 7, 2};
    int k = 3;

    long long result = maxPerformance(n, speed, efficiency, k);

    std::cout << "Maximum Performance: " << result << std::endl;

    return 0;
}
