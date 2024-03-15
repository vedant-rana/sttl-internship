#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Line {
    long long slope, intercept;

    long long eval(long long x) const {
        return slope * x + intercept;
    }
};

class ConvexHullTrick {
private:
    deque<Line> lines;

    bool isIntersectionValid(const Line& l1, const Line& l2, const Line& l3) {
        return (l3.intercept - l1.intercept) * (l1.slope - l2.slope) >=
               (l2.intercept - l1.intercept) * (l1.slope - l3.slope);
    }

public:
    void addLine(long long slope, long long intercept) {
        Line newLine = {slope, intercept};

        while (lines.size() >= 2 && isIntersectionValid(lines[lines.size() - 2], lines[lines.size() - 1], newLine)) {
            lines.pop_back();
        }

        lines.push_back(newLine);
    }

    long long query(long long x) {
        while (lines.size() >= 2 && lines[0].eval(x) < lines[1].eval(x)) {
            lines.pop_front();
        }

        return lines.front().eval(x);
    }
};

int main() {
    // Example usage:
    ConvexHullTrick cht;

    cht.addLine(1, 0);  // y = x
    cht.addLine(-1, 2); // y = -x + 2

    cout << "Maximum value at x=1: " << cht.query(1) << endl; // Should output 2

    cht.addLine(2, -3); // y = 2x - 3

    cout << "Maximum value at x=1: " << cht.query(1) << endl; // Should output 2
    cout << "Maximum value at x=2: " << cht.query(2) << endl; // Should output 1

    return 0;
}
