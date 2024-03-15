#include <iostream>
#include <vector>
#include <cmath>

class SqrtDecomposition {
private:
    int size;
    std::vector<int> blocks;
    std::vector<int> lazy;

public:
    SqrtDecomposition(const std::vector<int>& input) : size(input.size()) {
        int blockSize = static_cast<int>(std::sqrt(size)) + 1;
        blocks.resize(blockSize, INT_MAX);
        lazy.resize(blockSize, 0);

        for (int i = 0; i < size; ++i) {
            blocks[i / blockSize] = std::min(blocks[i / blockSize], input[i]);
        }
    }

    int query(int left, int right) {
        int result = INT_MAX;
        int blockSize = static_cast<int>(std::sqrt(size)) + 1;

        
        for (int i = 0; i < blockSize; ++i) {
            blocks[i] += lazy[i];
            lazy[i] = 0;
        }

        while (left <= right) {
            if (left % blockSize == 0 && left + blockSize - 1 <= right) {
                
                result = std::min(result, blocks[left / blockSize]);
                left += blockSize;
            } else {
                
                result = std::min(result, blocks[left / blockSize] + lazy[left / blockSize]);
                ++left;
            }
        }

        return result;
    }

    void update(int left, int right, int value) {
        int blockSize = static_cast<int>(std::sqrt(size)) + 1;

        while (left <= right) {
            if (left % blockSize == 0 && left + blockSize - 1 <= right) {
                
                blocks[left / blockSize] += value;
                lazy[left / blockSize] += value;
                left += blockSize;
            } else {
                
                blocks[left / blockSize] += value;
                ++left;
            }
        }
    }
};

int main() {
    std::vector<int> input = {2, 5, 1, 3, 7, 4, 6};

    SqrtDecomposition sqrtDecomp(input);

    std::cout << "Minimum in range [2, 5]: " << sqrtDecomp.query(2, 5) << std::endl;

    sqrtDecomp.update(3, 5, -2);

    std::cout << "Minimum in range [2, 5] after update: " << sqrtDecomp.query(2, 5) << std::endl;

    return 0;
}
