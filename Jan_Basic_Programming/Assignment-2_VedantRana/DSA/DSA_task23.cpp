#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printAllLCS(vector<vector<int>>& dp, const string& str1, const string& str2, int m, int n, string current) {
    if (m == 0 || n == 0) {
        reverse(current.begin(), current.end());
        cout << current << endl;
        return;
    }

    if (str1[m - 1] == str2[n - 1]) {
        printAllLCS(dp, str1, str2, m - 1, n - 1, current + str1[m - 1]);
    }

    if (dp[m - 1][n] >= dp[m][n - 1]) {
        printAllLCS(dp, str1, str2, m - 1, n, current);
    }

    if (dp[m][n - 1] >= dp[m - 1][n]) {
        printAllLCS(dp, str1, str2, m, n - 1, current);
    }
}

void findAllLCS(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[m][n];

    if (length == 0) {
        cout << "No common subsequence found." << endl;
    } else {
        cout << "Longest Common Subsequences in lexicographical order:" << endl;
        printAllLCS(dp, str1, str2, m, n, "");
    }
}

int main() {
    
    string str1 = "abcabcaa";
    string str2 = "acbacba";

    findAllLCS(str1, str2);

    return 0;
}
