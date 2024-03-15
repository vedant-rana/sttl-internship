#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printSubOfMetrix(vector<vector<int>> &m1, vector<vector<int>> &m2, int a, int b)
{

    vector<vector<int>>sub(a, vector<int>(b, 0));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            sub[i][j] = m1[i][j] - m2[i][j];
            // cout<<sum[i][j]<<" ";
        }
        // cout<<endl;
    }

     for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
           
            cout<<sub[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> m2 = {{1, 2, 1}, {4, 2, 3}, {1, 1, 0}};

    printSubOfMetrix(m1, m2, 3, 3);

    return 0;
}