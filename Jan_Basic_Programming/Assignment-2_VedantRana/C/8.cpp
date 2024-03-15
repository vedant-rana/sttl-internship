#include <iostream>
using namespace std;

int main() {
    double base, height;

    cout << "Enter the base of the parallelogram: ";
    cin >> base;

    cout << "Enter the height of the parallelogram: ";
    cin >> height;

    double area = base * height;

    cout << "The area of the parallelogram is: " << area << endl;

    return 0;
}
