#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//reverse first k elemets of queue

void printQueue(queue<int>& q) {
    queue<int> tempQueue = q; 

    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " "; 
        tempQueue.pop(); 
    }

    cout << endl;
}

void reverseFirstK(queue<int> &q, int k){
    stack<int> st;

    for(int i =0; i<k; i++){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    for(int i=0; i<q.size()- k ; i++){
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q1;
    int k;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    q1.push(60);

    printQueue(q1);

    cout<<"Enter k to reverse first k elemets : ";
    cin>>k;

    reverseFirstK(q1, k);

    printQueue(q1);
    
    
    return 0;
}