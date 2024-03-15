#include <iostream>

using namespace std;

bool isBuzzNumber(int number) {
    return (number % 7 == 0) || (number % 10 == 7);
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (isBuzzNumber(number)) {
        cout << number << " is a Buzz Number.\n";
    } else {
        cout << number << " is not a Buzz Number.\n";
    }

    return 0;
}
