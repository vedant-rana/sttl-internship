

#include <bits/stdc++.h>
using namespace std;

class BloomFilter
{
private:
    bitset<1000> filter;
    hash<string> hashFunction1;
    hash<string> hashFunction2;
    hash<string> hashFunction3;

public:
    void add(const string &element)
    {
        size_t hash1 = hashFunction1(element) % 1000;
        size_t hash2 = hashFunction2(element) % 1000;
        size_t hash3 = hashFunction3(element) % 1000;

        filter[hash1] = true;
        filter[hash2] = true;
        filter[hash3] = true;
    }

    bool contains(const string &element)
    {
        size_t hash1 = hashFunction1(element) % 1000;
        size_t hash2 = hashFunction2(element) % 1000;
        size_t hash3 = hashFunction3(element) % 1000;

        return filter[hash1] && filter[hash2] && filter[hash3];
    }
};

int main()
{
    BloomFilter bloomFilter;

    bloomFilter.add("apple");
    bloomFilter.add("banana");
    bloomFilter.add("cherry");

    cout << "Contains 'apple': " << bloomFilter.contains("apple") << endl;
    cout << "Contains 'orange': " << bloomFilter.contains("orange") << endl;

    return 0;
}
