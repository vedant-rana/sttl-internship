#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9};
    vector<int> arr2 = {8,3,5,4,9,3,5,0};


    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i=0, j=0;

    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            i++;
        }else if(arr1[i]> arr2[j]){
            j++;
        }else{
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }
    cout<<endl;
    
    return 0;
}