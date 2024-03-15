#include <iostream>
#include <vector>
#include <omp.h>

void parallelPrefixSum(std::vector<int> &input, std::vector<int> &output)
{
    int n = input.size();

#pragma omp parallel for
    for (int i = 0; i < n; ++i)
    {
        output[i] = input[i];
    }

    for (int stride = 1; stride < n; stride *= 2)
    {
#pragma omp parallel for
        for (int i = stride; i < n; ++i)
        {
            output[i] += output[i - stride];
        }
    }

    int lastElement = output[n - 1];
#pragma omp parallel for
    for (int i = 1; i < n; ++i)
    {
        output[i] += lastElement;
    }
}

int main()
{

    std::vector<int> input = {2, 3, 1, 4, 6, 5, 8, 7};
    int n = input.size();

    std::vector<int> prefixSum(n);

    parallelPrefixSum(input, prefixSum);

    std::cout << "Input Array: ";
    for (int num : input)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Prefix Sum: ";
    for (int sum : prefixSum)
    {
        std::cout << sum << " ";
    }
    std::cout << std::endl;

    return 0;
}
