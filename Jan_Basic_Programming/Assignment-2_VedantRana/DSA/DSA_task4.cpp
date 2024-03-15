#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <algorithm>


using namespace std;

int smallestNeighbors(int cityCount, const unordered_map<int, vector<pair<int, int>>>& cityDistances, int threshold) {
    auto dijkstra = [&](int start) {
        vector<int> distances(cityCount + 1, INT_MAX);
        distances[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, start});

        while (!minHeap.empty()) {
            int currentDistance = minHeap.top().first;
            int currentCity = minHeap.top().second;
            minHeap.pop();

            if (currentDistance > distances[currentCity]) {
                continue;
            }

            for (const auto& neighbor : cityDistances.at(currentCity)) {
                int neighborCity = neighbor.first;
                int neighborDistance = neighbor.second;
                int totalDistance = currentDistance + neighborDistance;

                if (totalDistance < distances[neighborCity]) {
                    distances[neighborCity] = totalDistance;
                    minHeap.push({totalDistance, neighborCity});
                }
            }
        }

        return distances;
    };

    vector<int> result;
    for (int startCity = 1; startCity <= cityCount; ++startCity) {
        vector<int> distances = dijkstra(startCity);
        int neighborsWithinThreshold = count_if(distances.begin() + 1, distances.end(),
                                                [threshold](int d) { return 0 < d && d <= threshold; });
        result.push_back(neighborsWithinThreshold);
    }

    auto minNeighbors = min_element(result.begin(), result.end());
    int minCity = distance(result.begin(), minNeighbors) + 1; 
    return minCity;
}

int main() {
    int cityCount = 4;
    unordered_map<int, vector<pair<int, int>>> cityDistances = {
        {1, {{2, 1}, {3, 4}}},
        {2, {{1, 1}, {3, 2}}},
        {3, {{1, 4}, {2, 2}}},
        {4, {}}
    };
    int thresholdDistance = 4;

    int result = smallestNeighbors(cityCount, cityDistances, thresholdDistance);
    cout << "City with the smallest number of neighbors at a threshold distance: " << result << endl;

    return 0;
}

