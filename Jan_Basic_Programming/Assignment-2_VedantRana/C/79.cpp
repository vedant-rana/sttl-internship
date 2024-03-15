#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int connectSticks(vector<int> &sticks)
{

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int stick : sticks)
    {
        minHeap.push(stick);
    }

    int totalCost = 0;

    while (minHeap.size() > 1)
    {

        int stick1 = minHeap.top();
        minHeap.pop();
        int stick2 = minHeap.top();
        minHeap.pop();

        int currentCost = stick1 + stick2;
        totalCost += currentCost;

        minHeap.push(currentCost);
    }

    return totalCost;
}

int main()
{

    vector<int> sticks = {2, 4, 3};
    int result = connectSticks(sticks);

    cout << "Minimum cost to connect sticks: " << result << endl;

    return 0;
}
