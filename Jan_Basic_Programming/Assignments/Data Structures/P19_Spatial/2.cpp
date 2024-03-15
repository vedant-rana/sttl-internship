#include <iostream>
#include <vector>
using namespace std;
class Point {
public:
    double x, y;

    Point(double _x, double _y) : x(_x), y(_y) {}
};

class QuadtreeNode {
public:
    double x, y, width, height;
    vector<Point> points;
    QuadtreeNode* children[4];

    QuadtreeNode(double _x, double _y, double _width, double _height)
        : x(_x), y(_y), width(_width), height(_height) {
        for (int i = 0; i < 4; ++i) {
            children[i] = nullptr;
        }
    }

    ~QuadtreeNode() {
        for (int i = 0; i < 4; ++i) {
            delete children[i];
        }
    }
};

class Quadtree {
private:
    QuadtreeNode* root;

public:
    Quadtree(double x, double y, double width, double height) {
        root = new QuadtreeNode(x, y, width, height);
    }

    void insert(Point point) {
        insertPoint(root, point);
    }

    void queryRange(double x, double y, double xRange, double yRange) {
        vector<Point> result;
        queryRange(root, x, y, xRange, yRange, result);

        cout << "Points in the queried range:\n";
        for (const Point& p : result) {
            cout << "(" << p.x << ", " << p.y << ")\n";
        }
    }

private:
    void insertPoint(QuadtreeNode* node, const Point& point) {
        if (node == nullptr) {
            return;
        }

        if (node->points.size() < 4) {
            node->points.push_back(point);
            return;
        }

        if (node->children[0] == nullptr) {
            splitNode(node);
        }

        for (int i = 0; i < 4; ++i) {
            if (point.x >= node->children[i]->x && point.x <= node->children[i]->x + node->children[i]->width &&
                point.y >= node->children[i]->y && point.y <= node->children[i]->y + node->children[i]->height) {
                insertPoint(node->children[i], point);
                return;
            }
        }
    }

    void splitNode(QuadtreeNode* node) {
        double subWidth = node->width / 2;
        double subHeight = node->height / 2;

        node->children[0] = new QuadtreeNode(node->x, node->y, subWidth, subHeight);
        node->children[1] = new QuadtreeNode(node->x + subWidth, node->y, subWidth, subHeight);
        node->children[2] = new QuadtreeNode(node->x, node->y + subHeight, subWidth, subHeight);
        node->children[3] = new QuadtreeNode(node->x + subWidth, node->y + subHeight, subWidth, subHeight);

        for (const Point& p : node->points) {
            insertPoint(node, p);
        }

        node->points.clear();
    }

    void queryRange(QuadtreeNode* node, double x, double y, double xRange, double yRange, vector<Point>& result) {
        if (node == nullptr) {
            return;
        }

        if (!(x > node->x + node->width || x + xRange < node->x || y > node->y + node->height || y + yRange < node->y)) {
            for (const Point& p : node->points) {
                if (p.x >= x && p.x <= x + xRange && p.y >= y && p.y <= y + yRange) {
                    result.push_back(p);
                }
            }

            for (int i = 0; i < 4; ++i) {
                queryRange(node->children[i], x, y, xRange, yRange, result);
            }
        }
    }
};

int main() {
    Quadtree quadtree(0, 0, 100, 100);

    quadtree.insert(Point(10, 10));
    quadtree.insert(Point(30, 30));
    quadtree.insert(Point(70, 70));
    quadtree.insert(Point(90, 90));

    double x = 20, y = 20, xRange = 50, yRange = 50;
    quadtree.queryRange(x, y, xRange, yRange);

    return 0;
}
