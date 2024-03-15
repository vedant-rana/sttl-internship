#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcsOfThreeStrings(const string &X, const string &Y, const string &Z)
{
    int m = X.size();
    int n = Y.size();
    int p = Z.size();

    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(p + 1, 0)));

    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int k = 0; k <= p; ++k)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    dp[i][j][k] = 0;
                }
                else if (X[i - 1] == Y[j - 1] && X[i - 1] == Z[k - 1])
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }

    return dp[m][n][p];
}

int main()
{
    string X, Y, Z;
    cin >> X >> Y >> Z;

    int result = lcsOfThreeStrings(X, Y, Z);

    cout << "Length of Longest Common Subsequence: " << result << endl;

    return 0;
}
