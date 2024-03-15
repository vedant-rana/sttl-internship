#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printTranspose(vector<vector<int>> m1, int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {

            cout << m1[j][i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printTranspose(m1, 3, 3);
    return 0;
}