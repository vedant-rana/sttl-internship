#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int MAX_ROWS = 12;
const int MAX_COLS = 10;

int findLongestRoute(const vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col) {
    if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || matrix[row][col] == 0) {
        return 0; 
    }

    if (dp[row][col] != -1) {
        return dp[row][col]; 
    }

    
    int right = 1 + findLongestRoute(matrix, dp, row, col + 1);
    int down = 1 + findLongestRoute(matrix, dp, row + 1, col);
    int left = 1 + findLongestRoute(matrix, dp, row, col - 1);
    int up = 1 + findLongestRoute(matrix, dp, row - 1, col);

    
    dp[row][col] = max({right, down, left, up});

    return dp[row][col];
}

int longestRoute(const vector<vector<int>>& matrix) {
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    return findLongestRoute(matrix, dp, 0, 0);
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int result = longestRoute(matrix);
    cout << "Longest Possible Route: " << result << endl;

    return 0;
}
