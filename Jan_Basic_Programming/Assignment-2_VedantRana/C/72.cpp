#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

using namespace std;

void fft(vector<complex<double>> &a, bool inverse = false)
{
    int n = a.size();
    if (n <= 1)
    {
        return;
    }

    vector<complex<double>> aEven(n / 2);
    vector<complex<double>> aOdd(n / 2);

    for (int i = 0; i < n / 2; ++i)
    {
        aEven[i] = a[i * 2];
        aOdd[i] = a[i * 2 + 1];
    }

    fft(aEven, inverse);
    fft(aOdd, inverse);

    double theta = 2 * M_PI / n * (inverse ? -1 : 1);
    complex<double> omegaN(cos(theta), sin(theta));
    complex<double> omega = 1;

    for (int i = 0; i < n / 2; ++i)
    {
        complex<double> t = omega * aOdd[i];
        complex<double> a0 = aEven[i] + t;
        complex<double> a1 = aEven[i] - t;

        a[i] = a0;
        a[i + n / 2] = a1;

        omega *= omegaN;
    }
}

int main()
{
    vector<complex<double>> input = {{1, 0}, {2, 0}, {3, 0}, {4, 0}};

    fft(input);

    cout << "FFT result:" << endl;
    for (const auto &value : input)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
