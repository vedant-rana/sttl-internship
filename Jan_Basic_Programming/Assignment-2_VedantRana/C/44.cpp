#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int power(int x, unsigned int y, int p)
{
    int result = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
        {
            result = (result * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return result;
}

bool isPrime(int n, int k)
{

    if (n <= 1 || n == 4)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }

    int d = n - 1;
    while (d % 2 == 0)
    {
        d /= 2;
    }

    for (int i = 0; i < k; i++)
    {

        int a = 2 + rand() % (n - 4);

        int x = power(a, d, n);

        if (x == 1 || x == n - 1)
        {
            continue;
        }

        for (int r = 1; r < n - 1; r++)
        {
            x = (x * x) % n;
            if (x == 1)
            {
                return false;
            }
            if (x == n - 1)
            {
                break;
            }
        }

        if (x != n - 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cout << "Enter a number to test for primality: ";
    cin >> n;

    int k = 5;

    if (isPrime(n, k))
    {
        cout << n << " is likely a prime number." << endl;
    }
    else
    {
        cout << n << " is composite." << endl;
    }

    return 0;
}
