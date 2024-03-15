#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int i=0, j=arr.size()-1;
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}