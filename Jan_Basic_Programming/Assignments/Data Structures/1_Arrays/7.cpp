#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1 = {0, 2, 3, 5};
    vector<int> arr2 = {0, 1, 4, 5, 7};
    vector<int> ans;

    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i++]);
        }
        else if (arr1[i] > arr2[j])
        {
            ans.push_back(arr2[j++]);
        }
        else
        {
            ans.push_back(arr1[i++]);
            j++;
        }
    }
    while(i<arr1.size()){
        ans.push_back(arr1[i++]);
    }

    while(j<arr2.size()){
        ans.push_back(arr2[j++]);
    }

    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}