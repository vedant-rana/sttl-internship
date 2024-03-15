#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> generateBinary(int n){
    queue<string> q;
    vector<string> ans;

    q.push("1");

    while(n){
        string s1=q.front();
        ans.push_back(s1);
        q.pop();

        string s2 = s1;
        
        q.push(s1.append("0"));
        q.push(s2.append("1"));
        n--;
    }

    return ans;
}

int main()
{
    int n;
    cout<<"Enter the num : ";
    cin>>n;

    vector<string>b = generateBinary(n);

    for(auto i:b ){
        cout<<i<<endl;
    }
    cout<<endl;
    return 0;
}