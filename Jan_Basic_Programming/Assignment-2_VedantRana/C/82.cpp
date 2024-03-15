#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

class BloomFilter
{
public:
    BloomFilter(int size, int numHashFunctions) : filterSize(size), numHashFunc(numHashFunctions)
    {
        filter.reset();
        numInserted = 0;
    }

    void insert(const std::string &element)
    {
        for (int i = 0; i < numHashFunc; ++i)
        {
            int hashValue = hash(element, i);
            filter.set(hashValue);
        }
        numInserted++;
    }

    bool contains(const std::string &element)
    {
        for (int i = 0; i < numHashFunc; ++i)
        {
            int hashValue = hash(element, i);
            if (!filter.test(hashValue))
            {
                return false;
            }
        }
        return true;
    }

    double estimateFalsePositiveProbability(int numQueries)
    {
        double theoreticalProb = std::pow(1 - std::exp(-static_cast<double>(numHashFunc) * numQueries / filterSize), numHashFunc);
        return theoreticalProb * std::pow(1 - std::pow(1 - 1.0 / filterSize, numHashFunc * numInserted), numQueries);
    }

private:
    std::bitset<100> filter;
    int filterSize;
    int numHashFunc;
    int numInserted;

    size_t hash(const std::string &element, int index)
    {
        size_t seed = 0;
        std::hash<std::string> hasher;
        seed ^= hasher(element) + 0x9e3779b9 + (seed << 6) + (seed >> 2) + index;
        return seed % filterSize;
    }
};

int main()
{
    int filterSize = 100;
    int numHashFunctions = 3;

    BloomFilter bloomFilter(filterSize, numHashFunctions);

    bloomFilter.insert("apple");
    bloomFilter.insert("orange");
    bloomFilter.insert("banana");

    std::cout << "Contains 'apple': " << (bloomFilter.contains("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Contains 'grape': " << (bloomFilter.contains("grape") ? "Yes" : "No") << std::endl;

    int numQueries = 10;

    double falsePosProb = bloomFilter.estimateFalsePositiveProbability(numQueries);
    std::cout << "Estimated False Positive Probability: " << falsePosProb << std::endl;

    return 0;
}
