#include <iostream>

class LinearCongruentialGenerator
{
public:
    LinearCongruentialGenerator(unsigned long long seed = 1)
        : X(seed) {}

    unsigned long long next()
    {
        X = (a * X + c) % m;
        return X;
    }

    void reset(unsigned long long seed)
    {
        X = seed;
    }

private:
    unsigned long long X;
    const unsigned long long a = 6364136223846793005ULL;
    const unsigned long long c = 1ULL;
    const unsigned long long m = 0xFFFFFFFFFFFFFFFFULL;
};

int main()
{
    LinearCongruentialGenerator lcg;

    for (int i = 0; i < 10; ++i)
    {
        std::cout << lcg.next() << std::endl;
    }

    return 0;
}
