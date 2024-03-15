#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getMajority(vector<int> &nums){
    unordered_map<int, int> c;

    for(auto i: nums){
        c[i]++;
        if(c[i]> nums.size()/2){
            return i;
        }
    }
    return -1;
}


int main()
{
    vector<int> nums={1,2,3,4,4,4,4,4,6};
    int majority = getMajority(nums);

    cout<<majority<<endl;
    return 0;
}