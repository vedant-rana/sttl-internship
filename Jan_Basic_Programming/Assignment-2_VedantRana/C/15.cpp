#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double radius;

    cout << "Enter the radius of the sphere: ";
    cin >> radius;

    double surfaceArea = 4 * 3.14 * pow(radius, 2);

    cout << "The surface area of the sphere is: " << surfaceArea << endl;

    return 0;
}
