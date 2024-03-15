#include <iostream>
#include <vector>
#include <cmath>

class DynamicRMQ {
private:
    int size;
    std::vector<int> values;
    std::vector<std::vector<int>> sparseTable;

public:
    DynamicRMQ(const std::vector<int>& input) : size(input.size()), values(input) {
        int logSize = static_cast<int>(std::log2(size)) + 1;
        sparseTable.resize(size, std::vector<int>(logSize));

        
        for (int i = 0; i < size; ++i) {
            sparseTable[i][0] = i;
        }

        for (int j = 1; (1 << j) <= size; ++j) {
            for (int i = 0; i + (1 << j) - 1 < size; ++i) {
                int left = sparseTable[i][j - 1];
                int right = sparseTable[i + (1 << (j - 1))][j - 1];

                sparseTable[i][j] = (values[left] < values[right]) ? left : right;
            }
        }
    }

    int query(int left, int right) {
        int k = static_cast<int>(std::log2(right - left + 1));
        int idx1 = sparseTable[left][k];
        int idx2 = sparseTable[right - (1 << k) + 1][k];

        return (values[idx1] < values[idx2]) ? idx1 : idx2;
    }

    void update(int index, int newValue) {
        values[index] = newValue;

        
        for (int j = 1; (1 << j) <= size; ++j) {
            for (int i = 0; i + (1 << j) - 1 < size; ++i) {
                int left = sparseTable[i][j - 1];
                int right = sparseTable[i + (1 << (j - 1))][j - 1];

                sparseTable[i][j] = (values[left] < values[right]) ? left : right;
            }
        }
    }
};

int main() {
    std::vector<int> input = {2, 5, 1, 3, 7, 4, 6};

    DynamicRMQ rmq(input);

    std::cout << "Minimum in range [2, 5]: " << input[rmq.query(2, 5)] << std::endl;

    rmq.update(3, 0);

    std::cout << "Minimum in range [2, 5] after update: " << input[rmq.query(2, 5)] << std::endl;

    return 0;
}
