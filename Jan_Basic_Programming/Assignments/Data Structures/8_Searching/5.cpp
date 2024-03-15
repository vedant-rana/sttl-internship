#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int interpolatioSearch(vector<int> arr,int search, int l, int h){
    //equation of pos = l + ((search-arr[l])/(arr[h]-arr[l]))*(h-l)

    int pos;

    if(l<=h && arr[l]<=search && search<=arr[h]){
        pos = l + (((double)(h - l) / (arr[h] - arr[l])) * (search - arr[l]));

        if(search == arr[pos]){
            return pos;
        }else if(search > arr[pos]){
            return interpolatioSearch(arr, search, pos+1, h);
        }else if(search<arr[pos]){
            return interpolatioSearch(arr, search, l, pos-1);
        }
    }
    return -1;
}


int main()
{
    vector<int> arr = {1,2,4,8,12,20,30};
    int search;

    cout<<"Enter Number to Search : ";
    cin>>search;

    cout<<"Index of "<<search<<" : "<<interpolatioSearch(arr, search, 0, arr.size()-1)<<endl;
    return 0;
}