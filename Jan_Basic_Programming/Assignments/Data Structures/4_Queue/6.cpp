#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

class Deque
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Deque()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
    }

    void pushFront(int val)
    {
        if (isFull())
        {
            cout << "Deque is full" << endl;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = MAX_SIZE - 1;
        }
        else
        {
            front--;
        }
        arr[front] = val;
    }

    void pushBack(int value)
    {
        if (isFull())
        {
            cout << "Deque overflow!" << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == MAX_SIZE - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = value;
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "Deque underflow!" << endl;
        }

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void popBack()
    {
        if (isEmpty())
        {
            cout << "Deque underflow!" << endl;
        }

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = MAX_SIZE - 1;
        }
        else
        {
            rear--;
        }
    }

    void display()
    {
        if(isEmpty()){
            cout<<"Queue is Empty !!"<<endl;
            return;
        }

        int i = front;

        while (true)
        {
            
            cout << arr[i] << " ";
            if(i == rear){
                break;
            }
            i = (i + 1) % MAX_SIZE;

        }
        cout << endl;
    }
};

int main()
{
    Deque d1;

    d1.pushBack(10);
    d1.pushBack(20);
    d1.pushFront(30);
    d1.pushFront(40);
    d1.pushBack(50);

    d1.display();

    d1.popBack();

    d1.display();

    d1.popFront();
    d1.display();

    return 0;
}