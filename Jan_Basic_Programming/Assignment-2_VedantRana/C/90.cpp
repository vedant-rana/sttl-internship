#include <iostream>
#include <vector>
#include <algorithm>

int minTaps(int n, std::vector<int> &ranges)
{
    std::vector<std::pair<int, int>> intervals;

    for (int i = 0; i <= n; ++i)
    {
        int left = std::max(0, i - ranges[i]);
        int right = std::min(n, i + ranges[i]);
        intervals.push_back({left, right});
    }

    std::sort(intervals.begin(), intervals.end());

    int taps = 0;
    int currentEnd = 0;
    int nextEnd = 0;

    for (int i = 0; i < intervals.size(); ++i)
    {
        if (intervals[i].first > currentEnd)
        {

            return -1;
        }

        nextEnd = std::max(nextEnd, intervals[i].second);

        if (i == currentEnd)
        {
            taps++;
            currentEnd = nextEnd;
        }
    }

    return currentEnd >= n ? taps : -1;
}

int main()
{

    int n = 7;
    std::vector<int> ranges = {1, 2, 1, 0, 2, 1, 0, 1};

    int result = minTaps(n, ranges);

    if (result != -1)
    {
        std::cout << "Minimum number of taps to water the garden: " << result << std::endl;
    }
    else
    {
        std::cout << "Cannot cover the entire garden." << std::endl;
    }

    return 0;
}
