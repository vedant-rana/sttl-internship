#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getSearchedElement(vector<int>arr, int search, int size){
    int low=0, high =size-1, mid;

    while(low<=high){
        mid = low + (high-low)/2;

        if(arr[mid] == search){
            return mid;
        }else if(arr[low] <= arr[mid]){
            if(arr[low]<= search && search<=arr[high]){
                high = mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(arr[mid]<=search && search<=arr[high]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr= {7,8,9,1,2,3,4,5,6};

    int search;

    cout<<"Enter Number to Search : ";
    cin>>search;

    cout<<"Index of "<<search<<" : "<<getSearchedElement(arr, search, arr.size())<<endl;
    return 0;
}