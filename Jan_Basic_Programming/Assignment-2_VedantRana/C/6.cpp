#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

bool isAlphanumeric(char c) {
    return isalnum(c) != 0;
}

string toLowerCase(string s) {
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}

bool isPalindrome(string s) {
    s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isAlphanumeric(c); }), s.end());
    s = toLowerCase(s);

    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "The entered string is a valid palindrome.\n";
    } else {
        cout << "The entered string is not a valid palindrome.\n";
    }

    return 0;
}
