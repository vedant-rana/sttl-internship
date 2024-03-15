#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

void yaoGraph(const std::vector<Point>& points) {
    std::vector<Point> xSorted = points;
    std::vector<Point> ySorted = points;

    std::sort(xSorted.begin(), xSorted.end(), compareX);
    std::sort(ySorted.begin(), ySorted.end(), compareY);

    
    for (int i = 0; i < xSorted.size() - 1; ++i) {
        std::cout << "Edge: (" << xSorted[i].x << "," << xSorted[i].y << ") - ("
                  << xSorted[i + 1].x << "," << xSorted[i + 1].y << ")\n";
    }
}

int main() {
    std::vector<Point> points = {{1, 2}, {3, 5}, {7, 8}, {4, 6}, {2, 9}};

    yaoGraph(points);

    return 0;
}
