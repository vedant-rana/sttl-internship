#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
class WaveletMatrix {
private:
    int n; 
    int bits; 
    std::vector<std::vector<int>> matrix;

public:
    WaveletMatrix(const std::vector<int>& array) : n(array.size()), bits(0), matrix(31) {
        for (int num : array) {
            bits = std::max(bits, 32 - __builtin_clz(num));
        }

        for (int i = 0; i < n; ++i) {
            for (int j = bits - 1; j >= 0; --j) {
                matrix[j].push_back((array[i] >> j) & 1);
                if ((array[i] >> j) & 1) {
                    array[i] -= (1 << j);
                }
            }
        }

        for (int j = 0; j < bits; ++j) {
            for (int i = 1; i < n; ++i) {
                matrix[j][i] += matrix[j][i - 1];
            }
        }
    }

    
    int rank(int x, int r) const {
        int result = 0;
        for (int j = bits - 1; j >= 0; --j) {
            int bit = (x >> j) & 1;
            if (bit) {
                result += matrix[j][r];
                if (r > 0) {
                    result -= matrix[j][r - 1];
                }
            }
            r = matrix[j][r] - 1;
        }
        return result;
    }

    
    int kthSmallest(int k, int l, int r) const {
        int result = 0;
        for (int j = bits - 1; j >= 0; --j) {
            int countOnes = matrix[j][r];
            if (l > 0) {
                countOnes -= matrix[j][l - 1];
            }
            if (k <= countOnes) {
                r = matrix[j][r] - 1;
            } else {
                result |= (1 << j);
                l = matrix[j][l] + k - countOnes - 1;
                r = matrix[j][r] + k - countOnes - 1;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> array = {1, 3, 2, 7, 6, 8, 0, 4, 5, 9};
    WaveletMatrix waveletMatrix(array);

    
    std::cout << "Rank of 3 in [0, 5]: " << waveletMatrix.rank(3, 5) << std::endl;
    std::cout << "3rd smallest element in [0, 5]: " << waveletMatrix.kthSmallest(3, 0, 5) << std::endl;

    return 0;
}
