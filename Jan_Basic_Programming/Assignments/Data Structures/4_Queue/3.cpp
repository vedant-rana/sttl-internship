#include <iostream>
using namespace std;

//circular queue


class CircularQueue {
private:
    const int n = 10;
    int arr[10];
    int front = -1;
    int rear = -1;

public:
    void add(int x) {
        if (front == -1 && rear == -1) {
            front = rear = 0;
            arr[rear] = x;
        } else if (((rear + 1) % n) == front) {
            cout << "Queue is Full !!" << endl;
        } else {
            rear = (rear + 1) % n;
            arr[rear] = x;
        }
    }

    void remove() {
        if (front == -1 && rear == -1) {
            cout << "Queue is Empty !!" << endl;
        } else if (front == rear) {
            front = rear = -1;
            return;
        } else {
            front = (front + 1) % n;
        }
    }

    int peek() {
        if (front == -1 && rear == -1) {
            cout << "Queue is Empty!!" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    void display() {
        if (front == -1 && rear == -1) {
            cout << "Queue is Empty!!" << endl;
        } else {
            int i = front;
            while (i != rear) {
                cout << arr[i] << " ";
                i = (i + 1) % n;
            }
            cout << arr[i] << endl;
        }
    }
};

int main() {
    CircularQueue list;
    
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);
    list.add(60);
    
    list.display();
    cout << list.peek() << endl;

    list.remove();
    list.display();

    return 0;
}
