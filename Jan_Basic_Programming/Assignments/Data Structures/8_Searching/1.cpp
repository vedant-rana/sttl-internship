#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Linear Search

int main()
{
    vector<int> arr = {3,6,4,8,9,7,2};
    int search, index=-1;
    cout<<"Enter Number to Search in Array: ";
    cin>>search;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] == search){
            index = i;
            break;
        }
    }

    if(index == -1){
        cout<<search<<" not found in array."<<endl;
    }else{
        cout<<search<<" found at index : "<<index<<endl;
    }
    return 0;
}