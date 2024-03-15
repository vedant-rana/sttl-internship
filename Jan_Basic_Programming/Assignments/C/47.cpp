#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int rows;

    cout << "Enter the Number Of rows for Hollow Triangle : ";
    cin >> rows;

    for (int i = 0; i < rows; i++)
    {
        for (int space = 0; space < rows - i; space++)
        {
            cout << " ";
        }

        if (i != rows - 1)
        {

            for (int num = 0; num <= i; num++)
            {
                if (num == 0 || num == i)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        else
        {
            for (int j = 0; j < rows; j++)
            {
                cout << "* ";
            }
        }
        cout << endl;
    }

    return 0;
}