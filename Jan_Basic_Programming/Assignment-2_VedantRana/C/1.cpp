#include <iostream>
using namespace std;
int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    int sum = N * (N + 1) / 2;

    cout << "Sum of first " << N << " numbers is: " << sum << endl;

    return 0;
}
