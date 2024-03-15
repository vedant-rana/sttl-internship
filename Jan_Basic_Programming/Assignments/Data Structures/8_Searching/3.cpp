#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[] = {1, 2, 3, 3, 3, 3, 4, 5, 5, 6};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int k, count = 0, first = -1, second = -1;

    cout << "Enter num : ";
    cin >> k;

    for (int i = 0; i < size; i++)
    {
        if (arr1[i] == k)
        {
            if (first == -1)
            {
                first = i;
            }
            else
            {
                count++;
            }
        }
        if (arr1[i] > k)
        {
            break;
        }
    }
    second = first + count;

    if (first == -1)
    {
        cout << k << " is not exist in Array" << endl;
    }
    else
    {
        cout << "First Occurance index : " << first << "\nLast Occurance index: " << second << endl;
    }
    return 0;
}