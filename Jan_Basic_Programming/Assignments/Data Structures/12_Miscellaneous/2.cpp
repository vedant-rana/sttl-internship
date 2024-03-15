#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrom(string s){
    string temp=s;
    reverse(temp.begin(), temp.end());

    return s==temp;
}

int main()
{
    string s1="abcdcb";

    if(isPalindrom(s1)){
        cout<<"String is Palindrome."<<endl;
    }else{
        cout<<"String is not Palindrome."<<endl;
    }
    return 0;
}