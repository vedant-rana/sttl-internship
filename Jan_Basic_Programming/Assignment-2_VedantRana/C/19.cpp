#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell == 1 ? 'Q' : '.') << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
       
        printBoard(board);
        return true;
    }

    bool result = false;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;

            result = solveNQueensUtil(board, row + 1, n) || result;

            
            board[row][col] = 0;
        }
    }

    return result;
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueensUtil(board, 0, n)) {
        cout << "Solution does not exist.\n";
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
