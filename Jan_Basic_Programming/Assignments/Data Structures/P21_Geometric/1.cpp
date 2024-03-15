#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Point {
    int x, y;


    static bool compare(Point a, Point b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
};


int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; 
    return (val > 0) ? 1 : 2; 
}


vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        
        cout << "Convex Hull is not possible with less than 3 points." << endl;
        return {};
    }


    int minY = points[0].y, minIdx = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < minY) || (y == minY && points[i].x < points[minIdx].x)) {
            minY = y;
            minIdx = i;
        }
    }


    swap(points[0], points[minIdx]);


    sort(points.begin() + 1, points.end(), [points](Point a, Point b) {
        int orientationVal = orientation(points[0], a, b);
        if (orientationVal == 0) {
            return (a.x + a.y) < (b.x + b.y);
        }
        return orientationVal == 2;
    });


    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);


    for (int i = 3; i < n; i++) {
        while (orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};


    vector<Point> convexHullPoints = convexHull(points);


    cout << "Convex Hull Points:" << endl;
    for (const Point& p : convexHullPoints) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return 0;
}
