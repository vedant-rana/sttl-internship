#include <iostream>
#include <vector>

class FenwickTree {
private:
    std::vector<int> BIT;

public:
    FenwickTree(int size) : BIT(size + 1, 0) {}

    
    void update(int i, int delta) {
        i++; 
        while (i < BIT.size()) {
            BIT[i] += delta;
            i += i & -i; 
        }
    }

    
    int getPrefixSum(int i) {
        i++; 
        int sum = 0;
        while (i > 0) {
            sum += BIT[i];
            i -= i & -i; 
        }
        return sum;
    }

    
    int getRangeSum(int start, int end) {
        if (start == 0)
            return getPrefixSum(end);
        else
            return getPrefixSum(end) - getPrefixSum(start - 1);
    }
};

int main() {
    std::vector<int> arr = {1, 3, 5, 2, 7, 6, 4, 8};
    FenwickTree fenwickTree(arr.size());

    
    for (int i = 0; i < arr.size(); i++) {
        fenwickTree.update(i, arr[i]);
    }

    
    std::cout << "Prefix sum from 0 to 5: " << fenwickTree.getRangeSum(0, 5) << std::endl;
    std::cout << "Prefix sum from 2 to 6: " << fenwickTree.getRangeSum(2, 6) << std::endl;

    
    fenwickTree.update(3, 5);

    
    std::cout << "Prefix sum from 0 to 5 after update: " << fenwickTree.getRangeSum(0, 5) << std::endl;

    return 0;
}
