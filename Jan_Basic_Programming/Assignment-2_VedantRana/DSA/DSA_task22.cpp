#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &str, int start, int end) {
    while (start < end) {
        if (str[start++] != str[end--]) {
            return false;
        }
    }
    return true;
}

void printAllPalindromicPartitions(const string &str) {
    int n = str.length();

    
    for (int mask = 1; mask < (1 << n); mask++) {
        vector<string> partition;
        int start = 0, end = 0;

        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                end = i;
                partition.push_back(str.substr(start, end - start + 1));
                start = end + 1;
            }
        }

        
        bool isPalindromic = true;
        for (const string &subStr : partition) {
            if (!isPalindrome(subStr, 0, subStr.length() - 1)) {
                isPalindromic = false;
                break;
            }
        }

        
        if (isPalindromic) {
            for (const string &subStr : partition) {
                cout << subStr << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    
    cout << "Palindromic Partitions for 'nitin':" << endl;
    printAllPalindromicPartitions("nitin");

    cout << "\nPalindromic Partitions for 'geeks':" << endl;
    printAllPalindromicPartitions("geeks");

    return 0;
}
