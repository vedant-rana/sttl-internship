#include <iostream>
using namespace std;

int main() {
    double sideLength;

    cout << "Enter the side length of the cube: ";
    cin >> sideLength;

    double volume = sideLength * sideLength * sideLength;

    
    cout << "The volume of the cube is: " << volume << endl;

    return 0;
}
