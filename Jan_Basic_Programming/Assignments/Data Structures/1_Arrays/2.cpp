#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {8,3,5,4,9,3,5,0};

    int max= INT_MIN;

    for(auto i:arr){
        if(i>max){
            max = i;
        }
    }

    cout<<"Max of All : "<< max<<endl;
    
    return 0;
}