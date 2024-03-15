#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void getKthLargetsSmallest(vector<int> &nums, int k){
    set<int> st;
    for(auto i: nums){
        st.insert(i);
    }

    auto it = st.begin();
    advance(it, k-1);
    cout<<k<<"th Smallest : "<<*it<<endl;

    auto it1 = st.begin();
    advance(it1, st.size()-k);
    cout<<k<<"th Largest : "<<*it1<<endl;

}

int main()
{
    // vector<int> nums={3,4,2,5,6,3,7,8};
    vector<int> nums={1,2,2,3,4,5,5,5,5,6};

    getKthLargetsSmallest(nums, 2);
    return 0;
}