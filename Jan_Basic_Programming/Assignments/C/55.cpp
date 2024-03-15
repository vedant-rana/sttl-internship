#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Magic Sqaure

bool isMagicSquare(vector<vector<int>> &sq, int a, int b)
{
    int row1 = 0, row2 = 0, row3 = 0, col1 = 0, col2 = 0, col3 = 0, dia1 = 0, dia2 = 0;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            row1 += sq[0][j];
            row2 += sq[1][j];
            row3 += sq[2][j];

            col1 += sq[i][0];
            col2 += sq[i][1];
            col3 += sq[i][2];

            if(i==j){
                dia1+=sq[i][j];
            }

            if(i+j == 2){
                dia2+=sq[i][j];
            }
        }
    }
    
    if(row1 == row2 && row2 == row3 && row3 == col1 && col1 == col2 && col2 == col3 && col3==3*dia1 && dia1==dia2){
        return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> sq = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
    bool result = isMagicSquare(sq, 3, 3);

    if(result){
        cout<<"Given Square is a Magic Square"<<endl;
    }else{
        cout<<"Given Square is not a  Magic Square"<<endl;
    }
    return 0;
}