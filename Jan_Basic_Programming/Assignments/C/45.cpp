#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isLowertriangular( vector<vector<int>> &m, int a, int b){
    bool isLT=true;
    for(int i=0; i<a; i++){
        for(int j=i+1; j<b; j++){
            if(m[i][j] != 0){
                isLT = false;
                break;
            }
        }
    }
    return isLT;
}
int main()
{
    vector<vector<int>> m = {{1,0,1},{3,4,0},{1,0,6}};
    bool isLowerTri = isLowertriangular(m, 3,3);

    if(isLowerTri){
    cout<<"Given Metrix is an Lower Triangular"<<endl;
    }else{
    cout<<"Given Metrix is not an Lower Triangular"<<endl;
    }

    return 0;
}