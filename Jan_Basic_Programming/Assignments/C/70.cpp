#include <iostream>
#include <vector>
using namespace std;

string decimalToRoman(int num) {
    
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string result = "";

    for (int i = 0; i < values.size(); i++) {
        while (num >= values[i]) {
            num -= values[i];
            result += symbols[i];
        }
    }

    return result;
}

int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    string romanNumeral = decimalToRoman(decimalNumber);
    cout << "Roman : " << romanNumeral << endl;

    return 0;
}
