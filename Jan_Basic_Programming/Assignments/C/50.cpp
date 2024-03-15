#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
     int rows, n=1;

    cout << "Enter the Number Of rows for Diamond Triangle : ";
    cin >> rows;

    for(int row=1; row<(2*rows); row++){
        if(row<=rows){
            for(int space=1; space<=rows-row; space++){
                cout<<" ";
            }
            for(int star=1; star<=row; star++){
                cout<<"* ";
            }
        }else{
            for(int space=1; space<=row-rows; space++){
                cout<<" ";
            }
            for(int star=1; star<=(2*rows - row); star++){
                cout<<"* ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}