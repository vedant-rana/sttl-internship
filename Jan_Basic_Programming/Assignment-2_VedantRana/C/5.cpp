#include <iostream>

using namespace std;

// Function to calculate factorial
long long factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

//nPr
long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

//nCr
long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n, r;

    cout << "Enter value of n: ";
    cin >> n;
    cout << "Enter value of r: ";
    cin >> r;

    if (n < 0 || r < 0 || r > n) {
        cout << "Invalid input. Make sure n and r are non-negative and r <= n.\n";
        return 1;
    }

    cout << "Permutation (nPr) is: " << permutation(n, r) << endl;
    cout << "Combination (nCr) is: " << combination(n, r) << endl;

    return 0;
}
