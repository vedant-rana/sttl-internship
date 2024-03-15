#include <iostream>
#include <vector>
#include <algorithm>

class WaveletTree {
private:
    std::vector<int> sequence;
    int low, high;
    WaveletTree* leftChild;
    WaveletTree* rightChild;

public:
    
    WaveletTree(const std::vector<int>& inputSequence, int lowRange, int highRange) {
        sequence = inputSequence;
        low = lowRange;
        high = highRange;

        if (low == high) {
            leftChild = rightChild = nullptr;
            return;
        }

        
        int mid = (low + high) / 2;
        auto partitionLambda = [mid](int element) { return element <= mid; };
        int median = std::partition(sequence.begin(), sequence.end(), partitionLambda) - sequence.begin();

        
        leftChild = new WaveletTree(std::vector<int>(sequence.begin(), sequence.begin() + median), low, mid);
        rightChild = new WaveletTree(std::vector<int>(sequence.begin() + median, sequence.end()), mid + 1, high);
    }

    
    int rangeQuery(int left, int right, int k) {
        if (left == right) {
            return sequence[left] <= k ? 1 : 0;
        }

        int mid = (low + high) / 2;

        if (k <= mid) {
            return leftChild->rangeQuery(left, mid, k);
        } else {
            return (mid - low + 1) + rightChild->rangeQuery(mid + 1, right, k);
        }
    }
};

int main() {
    std::vector<int> inputSequence = {1, 4, 2, 8, 6, 7, 3, 5};

    
    WaveletTree waveletTree(inputSequence, 1, 8);

    
    int result = waveletTree.rangeQuery(2, 7, 5);
    std::cout << "Number of elements less than or equal to 5 in the range [2, 7]: " << result << std::endl;

    return 0;
}
