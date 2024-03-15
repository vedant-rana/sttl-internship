#include <iostream>
#include <math.h>
using namespace std;

int sign(double x)
{
    if (x < 0)
        return -1;
    if (x > 0)
        return 1;
    return 0;
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int select(int arr[], int left,
           int right, int k)
{
    while (right > left)
    {
        if (right - left > 600)
        {
            int n = right - left + 1;
            int i = k - left + 1;
            double z = log(n);
            double s = 0.5 * exp(2 * z / 3);
            double sd = 0.5 * sqrt(z * s * (n - s) / n) * sign(i - n / 2);

            int newLeft = max(left, (int)(k - i * s / n + sd));

            int newRight = min(right, (int)(k + (n - i) * s / n + sd));

            select(arr, newLeft, newRight, k);
        }

        int t = arr[k];
        int i = left;
        int j = right;
        swap(arr, left, k);
        if (arr[right] > t)
        {
            swap(arr, left, right);
        }

        while (i < j)
        {
            swap(arr, i, j);
            i++;
            j--;

            while (arr[i] < t)
                i++;
            while (arr[j] > t)
                j--;
        }

        if (arr[left] == t)
            swap(arr, left, j);
        else
        {
            j++;
            swap(arr, right, j);
        }
        if (j <= k)
            left = j + 1;
        if (k <= j)
            right = j - 1;
    }
    return arr[k];
}

int main()
{
    int arr[] = {7, 3, 4, 0, 1, 6};
    int n = sizeof(arr) / sizeof(int);

    int k = 2;
    int res = select(arr, 0, n - 1, k - 1);
    cout << "The " << k << "-th smallest element is "
         << res << endl;
    return 0;
}
