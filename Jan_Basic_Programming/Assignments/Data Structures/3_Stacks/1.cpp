#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
    int st[50];
    int top =-1;
    int size = 50;

public:
    void push(int data){
        if(top>=size){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        st[top]= data;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }

    void peak(){
        cout<<st[top]<<endl;
    }

    void display(){
        if(top<=-1){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        int i=top;
        while(i>-1){
            cout<<st[i]<<" ";
            i--;
        }
        cout<<endl;
    }
};

int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);   
    s1.push(30);   
    s1.push(40);   

    s1.display();

    s1.pop();

    s1.display();

    s1.peak();

    return 0;
}