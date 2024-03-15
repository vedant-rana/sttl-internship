#include<iostream>
#include <unordered_map>
using namespace std;
//Roman to decimal

int romanToDecimal(string &s){
    unordered_map<char, int> mp={
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result=0;

    for(int i=0; i<s.length(); i++){
        if(i+1<s.length() && mp[s[i]]<mp[s[i+1]]){
            result-=mp[s[i]];
        }else{
            result+=mp[s[i]];
        }
    }
    return result;
}
int main()
{
    string s="MCDXCVIII";
    cout<<"Decimal : "<<romanToDecimal(s);
    return 0;
}