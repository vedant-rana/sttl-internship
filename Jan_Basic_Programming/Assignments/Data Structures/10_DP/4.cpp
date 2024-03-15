#include <iostream>
#include <vector>

using namespace std;

string findLongestCommonSubsequence(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int len = dp[m][n];
    string result(len, ' ');

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result[len - 1] = str1[i - 1];
            --i;
            --j;
            --len;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    return result;
}

int main() {
    string str1 = "ABCD";
    string str2 = "ACDF";

    string result = findLongestCommonSubsequence(str1, str2);

    cout << "Longest Common Subsequence: " << result << endl;

    return 0;
}
