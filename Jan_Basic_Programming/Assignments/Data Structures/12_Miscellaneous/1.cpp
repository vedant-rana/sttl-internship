#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string reverseSentence(string &s){
    string ans="";
    string temp="";
    stack<string> st;

    for(int i=0; i<s.length(); i++){
        temp+=s[i];
        if(s[i]==' ' || i+1 == s.length()){
            st.push(temp);
            temp="";
        }
    }

    while(!st.empty()){
        
        ans=ans+st.top()+" ";
        st.pop();
        
    }

    return ans;
}

int main()
{
    string s;

    cout<<"Enter Sentence to Reverse : ";
    getline(cin, s);

    string reverse = reverseSentence(s);
    cout<<reverse<<endl;
    return 0;
}