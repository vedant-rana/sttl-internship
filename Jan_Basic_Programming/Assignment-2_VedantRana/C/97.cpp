#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int countLessEqual(const std::vector<std::vector<int>> &matrix, int target)
{
    int count = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = rows - 1;
    int col = 0;

    while (row >= 0 && col < cols)
    {
        if (matrix[row][col] <= target)
        {
            count += (row + 1);
            col++;
        }
        else
        {
            row--;
        }
    }

    return count;
}

int kthSmallest(const std::vector<std::vector<int>> &matrix, int k)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int low = matrix[0][0];
    int high = matrix[rows - 1][cols - 1];

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int count = countLessEqual(matrix, mid);

        if (count < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int main()
{

    std::vector<std::vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}};
    int k = 8;

    int result = kthSmallest(matrix, k);

    std::cout << "Kth Smallest Element: " << result << std::endl;

    return 0;
}
