#include <iostream>
#include <bitset>
#include <vector>
#include <functional>

class BloomFilter {
private:
    std::vector<std::bitset<100>> filter;
    std::vector<std::function<int(const std::string&)>> hashFunctions;
    int numHashFunctions;

public:
    BloomFilter(int numHashFunc) : numHashFunctions(numHashFunc) {
        filter.resize(numHashFunc);
        initializeHashFunctions();
    }

    void add(const std::string& element) {
        for (int i = 0; i < numHashFunctions; i++) {
            int index = hashFunctions[i](element) % 100;
            filter[i].set(index);
        }
    }

    bool contains(const std::string& element) const {
        for (int i = 0; i < numHashFunctions; i++) {
            int index = hashFunctions[i](element) % 100;
            if (!filter[i].test(index)) {
                return false; 
            }
        }
        return true; 
    }

private:
    void initializeHashFunctions() {
        
        hashFunctions.emplace_back(std::hash<std::string>());
        hashFunctions.emplace_back([](const std::string& s) {
            int hash = 0;
            for (char c : s) {
                hash = (hash * 31) + c;
            }
            return hash;
        });
        
    }
};

int main() {
    BloomFilter bloomFilter(3);

    
    bloomFilter.add("apple");
    bloomFilter.add("banana");
    bloomFilter.add("cherry");

    
    std::cout << "Contains 'apple': " << (bloomFilter.contains("apple") ? "Yes" : "No") << "\n";
    std::cout << "Contains 'grape': " << (bloomFilter.contains("grape") ? "Yes" : "No") << "\n";

    return 0;
}
