#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double INF = 1e9;

struct Point
{
    double x, y;

    Point(double x, double y) : x(x), y(y) {}
};

double distance(const Point &p1, const Point &p2)
{
    return std::hypot(p1.x - p2.x, p1.y - p2.y);
}

double bitonicTSP(const std::vector<Point> &points)
{
    int n = points.size();

    std::vector<Point> sortedPoints = points;
    std::sort(sortedPoints.begin(), sortedPoints.end(), [](const Point &a, const Point &b)
              { return a.x < b.x || (a.x == b.x && a.y < b.y); });

    std::vector<std::vector<double>> dp(n, std::vector<double>(n, INF));
    dp[0][0] = 0;

    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < j; ++i)
        {
            for (int k = 0; k < i; ++k)
            {
                dp[i][j] = std::min(dp[i][j], dp[k][i] + distance(sortedPoints[k], sortedPoints[j]));
            }
        }
    }

    double minCost = INF;
    for (int k = 0; k < n - 1; ++k)
    {
        minCost = std::min(minCost, dp[k][n - 1] + distance(sortedPoints[k], sortedPoints[n - 1]));
    }

    return minCost;
}

int main()
{

    std::vector<Point> points = {
        {0, 0},
        {1, 2},
        {3, 1},
        {5, 4},
        {7, 2},
        {9, 5}};

    double result = bitonicTSP(points);

    std::cout << "Minimum cost for Bitonic TSP: " << result << std::endl;

    return 0;
}
