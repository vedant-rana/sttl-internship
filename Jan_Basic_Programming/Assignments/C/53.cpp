#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

int findLcm(int a, int b) {
    return (a * b) / findGCD(a, b);
}

int getLCM(vector<int> &arr) {
    int lcm = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        lcm = findLcm(lcm, arr[i]);
    }
    return lcm;
}

int getGcd(vector<int> &arr) {
    int gcd = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        gcd = findGCD(gcd, arr[i]);
    }
    return gcd;
}


int main()
{
    vector<int> nums = {4, 8, 16};
    // int gcd = getGcd(nums);
    int lcm = getLCM(nums);
    int gcd = getGcd(nums);

    cout<<lcm<<endl;
    cout<<gcd<<endl;
    return 0;
}