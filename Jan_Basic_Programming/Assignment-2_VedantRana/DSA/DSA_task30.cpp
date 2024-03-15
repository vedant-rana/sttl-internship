#include <iostream>
#include <bitset>
#include <functional>

class BloomFilter {
private:
    std::bitset<1000> filter;
    std::hash<std::string> hashFunction;

public:
    void insert(const std::string& element) {
        size_t hashValue = hashFunction(element);
        filter[hashValue % 1000] = 1;
    }

    bool contains(const std::string& element) const {
        size_t hashValue = hashFunction(element);
        return filter[hashValue % 1000] == 1;
    }
};

int main() {
    BloomFilter bloomFilter;

    bloomFilter.insert("apple");
    bloomFilter.insert("orange");

    std::cout << "Contains 'apple': " << std::boolalpha << bloomFilter.contains("apple") << std::endl;
    std::cout << "Contains 'banana': " << std::boolalpha << bloomFilter.contains("banana") << std::endl;

    return 0;
}
