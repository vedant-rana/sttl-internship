#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Bubble Sort

int main()
{
    
    vector<int> arr ={2,4,3,6,8,6};

    for(int i=0; i<arr.size()-1; i++){
        for(int j=0; j<arr.size()-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    for(auto i : arr){
        cout<<i<<" ";
    }
 return 0;
}