#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Pascal Triangle 

int getnCr(int n, int r){
    if(r>n){
        return 0;
    }

    if(r==0 || r==n){
        return 1;
    }

    return getnCr(n-1, r-1) + getnCr(n-1, r);
}


int main()
{
    int rows;

    cout<<"Enter the Number Of rows for Pascal Triangle : ";
    cin>>rows;

    for(int i=0; i<rows; i++){
        for(int space=0; space<rows-i; space++){
            cout<<" ";
        }
        for(int num=0; num<=i; num++){
            cout<<getnCr(i,num)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}