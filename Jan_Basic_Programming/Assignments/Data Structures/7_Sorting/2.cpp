#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Selection Sort


int main()
{
    vector<int> arr ={2,4,3,6,8,6};

    for(int i=0; i<arr.size()-1; i++){
        int min = i;
        for(int j=i; j<arr.size(); j++){
            if(arr[j]<arr[min]){
                min =j;
            }
        }
        swap(arr[i], arr[min]);
    }

    for(auto i : arr){
        cout<<i<<" ";
    }

 return 0;
}