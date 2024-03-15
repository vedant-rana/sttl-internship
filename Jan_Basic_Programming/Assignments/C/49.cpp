#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int rows, n = 1;

    cout << "Enter the Number Of rows for Hollow Triangle : ";
    cin >> rows;

    for (int i = 0; i < rows; i++)
    {
        for (int num = 0; num <= i; num++)
        {
            if(n>9){
            cout << n << " ";
            }else{
            cout << n << "  ";
            }
            n++;
        }
        cout << endl;
    }
    return 0;
}