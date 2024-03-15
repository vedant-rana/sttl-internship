#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int sumOfDiagonal=0;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==j){
                sumOfDiagonal+=m1[i][j];
            }
        }
    }

    cout<<"Sum of Diagonal Digits : "<<sumOfDiagonal<<endl;
    return 0;
}