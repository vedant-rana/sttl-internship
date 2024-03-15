#include <iostream>
#include <vector>

using namespace std;

int findNthFibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    vector<int> fib(n + 1, 0);
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    int result = findNthFibonacci(n);

    cout << "The " << n << "th Fibonacci number is: " << result << endl;

    return 0;
}
