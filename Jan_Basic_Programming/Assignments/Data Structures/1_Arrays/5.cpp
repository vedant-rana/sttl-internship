#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rotateArray(int arr[], int size, int k){
    int temp[size]={0};
    int tempIndex=0;

    for(int i=k; i<size; i++){
        temp[tempIndex++] = arr[i];
    }

    for(int i=0; i<k; i++){
        temp[tempIndex++] = arr[i];
    }

    for(int i=0; i<size; i++){
        arr[i] =temp[i];
    }
    
}

int main()
{
    int arr1[]= {1,2,3,4,5,6,7,8,9};

    int size = sizeof(arr1)/sizeof(arr1[0]);
    int k,j=0;
    cout<<"enter k : ";
    cin>>k;

    rotateArray(arr1, size, k);

    for(int i=0; i<size; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}