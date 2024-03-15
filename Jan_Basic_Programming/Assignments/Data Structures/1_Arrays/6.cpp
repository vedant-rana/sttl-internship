#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {8,3,5,4,9,3,5,0};
    vector<int>ans;
    
    sort(arr.begin(), arr.end());

    int i=0;

    while(i<arr.size()-1){
        if(arr[i]!=arr[i+1]){
            ans.push_back(arr[i]);
        }
        i++;
    }

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}