#include <iostream>
#include <vector>
#include <functional>  // For std::hash
#include <bitset>

class BloomFilter {
private:
    std::vector<bool> filter;
    std::vector<std::hash<std::string>> hashFunctions;
    size_t numElements;
    size_t filterSize;
    size_t numHashFunctions;

    void resizeFilter() {
        // Double the filter size and rehash the existing elements
        size_t newSize = filterSize * 2;
        std::vector<bool> newFilter(newSize, false);

        for (size_t i = 0; i < filterSize; ++i) {
            if (filter[i]) {
                for (size_t j = 0; j < numHashFunctions; ++j) {
                    size_t newIndex = hashFunctions[j](std::to_string(i)) % newSize;
                    newFilter[newIndex] = true;
                }
            }
        }

        filter = std::move(newFilter);
        filterSize = newSize;
    }

public:
    BloomFilter(size_t initialSize, size_t numHashFuncs)
        : filter(initialSize, false), numElements(0),
          filterSize(initialSize), numHashFunctions(numHashFuncs) {
        
        // Initialize hash functions
        for (size_t i = 0; i < numHashFuncs; ++i) {
            hashFunctions.emplace_back(std::hash<std::string>());
        }
    }

    void insert(const std::string& element) {
        for (size_t i = 0; i < numHashFunctions; ++i) {
            size_t index = hashFunctions[i](element) % filterSize;
            filter[index] = true;
        }

        ++numElements;

        // Check if resizing is needed
        if (numElements > filterSize / 2) {
            resizeFilter();
        }
    }

    bool contains(const std::string& element) const {
        for (size_t i = 0; i < numHashFunctions; ++i) {
            size_t index = hashFunctions[i](element) % filterSize;
            if (!filter[index]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Create a Bloom Filter with an initial size of 10 and 3 hash functions
    BloomFilter bloomFilter(10, 3);

    // Insert some elements
    bloomFilter.insert("apple");
    bloomFilter.insert("banana");
    bloomFilter.insert("orange");

    // Check for membership
    std::cout << "Contains 'apple': " << std::boolalpha << bloomFilter.contains("apple") << std::endl;
    std::cout << "Contains 'grape': " << std::boolalpha << bloomFilter.contains("grape") << std::endl;

    return 0;
}
