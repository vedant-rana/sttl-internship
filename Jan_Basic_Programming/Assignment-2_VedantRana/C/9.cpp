#include <iostream>
using namespace std;

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool isHarshad(int num) {
    int digitSum = sumOfDigits(num);
    return (num % digitSum == 0);
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (isHarshad(number)) {
        cout << number << " is a Harshad number.\n";
    } else {
        cout << number << " is not a Harshad number.\n";
    }

    return 0;
}
