#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Memory allocation and deallocation in cpp

int main()
{
    int* n1 = new int(23);

    cout<<"Dynamically allocated address in Heap : "<<n1<<endl;
    cout<<"value of declared integer: "<<*n1<<endl;

    delete n1;
    cout<<"value of n1: "<<*n1<<endl;
    cout<<"address of n1 : "<<n1<<endl;   
    return 0;
}