#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    int pivotElem = arr[s];
    int count = 0;

    //find correct index for pivot element using counting small elem then pivot elem
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElem)
        {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);


    //arranging elemets which are lesser and greater than pivot elem to left and right respectively
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] > arr[pivotIndex])
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int pivot = partition(arr, s, e);

    // apply quick sort on left and right part of Pivot
    quickSort(arr, s, pivot - 1);

    quickSort(arr, pivot + 1, e);
}

int main()
{
    vector<int> arr = {3, 6, 4, 8, 9, 7, 2};
    quickSort(arr, 0, arr.size() - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}