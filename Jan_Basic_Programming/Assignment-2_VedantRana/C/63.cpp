#include <iostream>
#include <vector>
#include <functional>
#include <limits>

class CountMinSketch
{
public:
    CountMinSketch(int depth, int width) : depth(depth), width(width)
    {
        sketch.resize(depth, std::vector<int>(width, 0));
        hashFunctions.resize(depth, std::hash<int>());
    }

    void increment(int element)
    {
        for (int i = 0; i < depth; ++i)
        {
            int hashValue = hashFunctions[i](element);
            int index = hashValue % width;
            sketch[i][index]++;
        }
    }

    int estimateCount(int element) const
    {
        int minCount = std::numeric_limits<int>::max();

        for (int i = 0; i < depth; ++i)
        {
            int hashValue = hashFunctions[i](element);
            int index = hashValue % width;
            minCount = std::min(minCount, sketch[i][index]);
        }

        return minCount;
    }

private:
    int depth;
    int width;
    std::vector<std::vector<int>> sketch;
    std::vector<std::hash<int>> hashFunctions;
};

int main()
{
    CountMinSketch countMin(4, 8);

    countMin.increment(42);
    countMin.increment(42);
    countMin.increment(7);
    countMin.increment(7);
    countMin.increment(7);

    int count1 = countMin.estimateCount(42);
    int count2 = countMin.estimateCount(7);

    std::cout << "Estimated count of 42: " << count1 << std::endl;
    std::cout << "Estimated count of 7: " << count2 << std::endl;

    return 0;
}
