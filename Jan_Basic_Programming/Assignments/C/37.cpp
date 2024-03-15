#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
// Binary Search

void binarySearch(vector<int> &arr, int search, int s, int e)
{
    if (s > e)
    {
        cout << search << " is not Found" << endl;
        return;
    }

    int mid = s + (e - s) / 2;

    if (arr[mid] == search)
    {
        cout << search << " is found in Array" << endl;
    }
    else if (arr[mid] > search)
    {
        binarySearch(arr, search, s, mid - 1);
    }
    else
    {
        binarySearch(arr, search, mid + 1, e);
    }
};

int main()
{
    vector<int> arr = {3, 6, 4, 8, 9, 7, 2};
    int search, index = -1, start = 0, end = arr.size() - 1;
    cout << "Enter Number to Search in Array: ";
    cin >> search;
    sort(arr.begin(), arr.end());

    binarySearch(arr, search, start, end);

    return 0;
}