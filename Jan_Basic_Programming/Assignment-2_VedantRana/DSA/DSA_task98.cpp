#include <iostream>
#include <vector>
#include <omp.h>

int parallelBinarySearch(const std::vector<int>& arr, int key) {
    int result = -1;
    int size = arr.size();

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            #pragma omp critical
            {
                result = i;
            }
        }
    }

    return result;
}

int main() {
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 7;

    int result = parallelBinarySearch(sortedArray, key);

    if (result != -1) {
        std::cout << "Key " << key << " found at index " << result << std::endl;
    } else {
        std::cout << "Key " << key << " not found in the array" << std::endl;
    }

    return 0;
}
