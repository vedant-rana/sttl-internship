#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2)
{
    vector<int> merged;

    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            merged.push_back(nums1[i]);
            i++;
        }
        else
        {
            merged.push_back(nums2[j]);
            j++;
        }
    }

    while (i < nums1.size())
    {
        merged.push_back(nums1[i]);
        i++;
    }

    while (j < nums2.size())
    {
        merged.push_back(nums2[j]);
        j++;
    }

    int totalSize = merged.size();
    if (totalSize % 2 == 0)
    {
        return (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
    }
    else
    {
        return merged[totalSize / 2];
    }
}

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);

    cout << "Median of the two sorted arrays is: " << median << endl;

    return 0;
}
