#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int q[100];
    int size = 100;
    int front = -1, rear = -1;

public: 
    void enqueue(int data){
        if(rear == size-1){
            cout<<"Queue Overflow."<<endl;
            return;
        }
        if(front==-1 && rear ==-1){
            front++;
            rear++;
            q[rear] = data;
            return;
        }
        rear++;
        q[rear]=data;
    }

    void dequeue(){
        if(front == -1 || front == rear+1){
            cout<<"queue is empty"<<endl;
            return;
        }
        front++;
    }

    void getFront(){
        cout<<"front : "<<q[front]<<endl;
    }

    void getRear(){
        cout<<"rear : "<<q[rear]<<endl;
    }

    void display(){
        if(front == -1 || front == rear+1){
            cout<<"queue is empty"<<endl;
            return;
        }

        int i=front;
        while(i<=rear){
            cout<<q[i]<<" ";
            i++;
        }
        cout<<endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.display();

    q.getFront();
    q.getRear();

    return 0;
}