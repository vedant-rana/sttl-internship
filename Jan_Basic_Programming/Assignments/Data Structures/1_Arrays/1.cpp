#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9};

    int sum =0;

    for(auto i:arr){
        sum +=i;
    }

    cout<<"Sum of All elements : "<<sum<<endl;
    return 0;
}