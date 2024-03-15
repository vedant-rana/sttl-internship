#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

struct Rectangle {
    Point topLeft;
    Point bottomRight;
};

bool doRectanglesOverlap(const Rectangle& rect1, const Rectangle& rect2) {
    // If one rectangle is on the left side of the other
    if (rect1.bottomRight.x < rect2.topLeft.x || rect2.bottomRight.x < rect1.topLeft.x) {
        return false;
    }

    // If one rectangle is above the other
    if (rect1.bottomRight.y < rect2.topLeft.y || rect2.bottomRight.y < rect1.topLeft.y) {
        return false;
    }

    // Rectangles overlap
    return true;
}

int main() {
    // Example usage
    Rectangle rect1 = {{0, 0}, {4, 4}};
    Rectangle rect2 = {{2, 2}, {6, 6}};

    if (doRectanglesOverlap(rect1, rect2)) {
        cout << "Rectangles overlap." << endl;
    } else {
        cout << "Rectangles do not overlap." << endl;
    }

    return 0;
}
