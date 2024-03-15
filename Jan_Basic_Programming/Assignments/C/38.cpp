#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Merge sort

void mergeArrays(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int leftlen = mid - s + 1, rightLen = e - mid;
    vector<int> leftArr(leftlen);
    vector<int> rightArr(rightLen);

    int mainArrayIndex = s;
    for (int i = 0; i < leftlen; i++)
    {
        leftArr[i] = arr[mainArrayIndex++];
    }

    for (int i = 0; i < rightLen; i++)
    {
        rightArr[i] = arr[mainArrayIndex++];
    }

    int indexOfLeft = 0, indexOfRight = 0, mergeArrayIndex = s;

    while (indexOfLeft < leftlen && indexOfRight < rightLen)
    {
        if (leftArr[indexOfLeft] < rightArr[indexOfRight])
        {
            arr[mergeArrayIndex++] = leftArr[indexOfLeft++];
        }
        else
        {
            arr[mergeArrayIndex++] = rightArr[indexOfRight++];
        }
    }

    while (indexOfLeft < leftlen)
    {
        arr[mergeArrayIndex++] = leftArr[indexOfLeft++];
    }

    while (indexOfRight < rightLen)
    {
        arr[mergeArrayIndex++] = rightArr[indexOfRight++];
    }
}

void mergeSortArray(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // Sort left part of array
    mergeSortArray(arr, s, mid);

    // Sort left part of array
    mergeSortArray(arr, mid + 1, e);

    // merge Both left and right array
    mergeArrays(arr, s, e);
}

int main()
{
    vector<int> arr = {3, 6, 4, 8, 9, 7, 2};
    mergeSortArray(arr, 0, arr.size() - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}