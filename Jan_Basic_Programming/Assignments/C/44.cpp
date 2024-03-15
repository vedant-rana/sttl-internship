#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isUppertriangular( vector<vector<int>> &m, int a, int b){
    bool isUT=true;
    for(int i=0; i<a; i++){
        for(int j=0; j<i; j++){
            if(m[i][j] != 0){
                isUT = false;
                break;
            }
        }
    }
    return isUT;
}
int main()
{
    vector<vector<int>> m = {{1,2,3},{0,4,5},{1,0,6}};
    bool isUpperTri = isUppertriangular(m, 3,3);

    if(isUpperTri){
    cout<<"Given Metrix is an upper Triangular"<<endl;
    }else{
    cout<<"Given Metrix is not anupper Triangular"<<endl;
    }

    return 0;
}