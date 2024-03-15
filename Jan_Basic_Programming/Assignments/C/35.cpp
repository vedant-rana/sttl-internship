#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Inserion Sort
void insertionSort(vector<int> &arr, int len)
{
    int j, curr;
    for (int i = 1; i<len; i++)
    {
        curr = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

int main()
{
    vector<int> arr = {3, 6, 4, 8, 9, 7, 2};

    insertionSort(arr, arr.size() );

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}