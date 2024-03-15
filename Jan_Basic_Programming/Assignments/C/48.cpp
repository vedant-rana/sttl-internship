#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
     int rows, n=1;

    cout << "Enter the Number Of rows for Hollow Triangle : ";
    cin >> rows;

    for(int i=0; i<rows; i++){
        for(int space=0; space<rows-i; space++){
            cout<<"  ";
        }
        for(int num=0; num<=i; num++){
            cout<<n<<" ";
        }
        cout<<endl;
        n++;
    }
    return 0;
}