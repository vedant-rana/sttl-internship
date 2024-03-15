#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int low, high;

    Interval(int l, int h) : low(l), high(h) {}
    Interval() : low(0), high(0) {}  
};

vector<Interval> findOverlappingIntervals(const vector<Interval>& intervals) {
    vector<Interval> result;
    if (intervals.size() < 2) {
        return result;
    }

    vector<pair<int, char>> points;  

    for (const auto& interval : intervals) {
        points.emplace_back(interval.low, 's');
        points.emplace_back(interval.high, 'e');
    }

    sort(points.begin(), points.end());

    int count = 0;
    Interval current;
    for (const auto& point : points) {
        if (point.second == 's') {
            if (count == 0) {
                current.low = point.first;
            }
            count++;
        } else {
            count--;
            if (count == 0) {
                current.high = point.first;
                result.push_back(current);
            }
        }
    }

    return result;
}

int main() {
    
    vector<Interval> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<Interval> overlappingIntervals = findOverlappingIntervals(intervals);

    cout << "Overlapping Intervals:\n";
    for (const Interval& interval : overlappingIntervals) {
        cout << "[" << interval.low << ", " << interval.high << "]\n";
    }

    return 0;
}
