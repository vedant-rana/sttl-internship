#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class LinkedList{
    private:
    Node* head;

    public:
    LinkedList(){
        this->head = nullptr;
    }

    void insertAtEnd(int data){
        Node* n = new Node(data);

        if(head==nullptr){
            head=n;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = n;
    }

    void printList(){
        Node* temp = head;

        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    Node* getMiddle(){
        Node* s=head;
        Node* f =head;

        while(f != nullptr && f->next != nullptr){
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};

int main()
{
    LinkedList l1;
    l1.insertAtEnd(10);
    l1.insertAtEnd(20);
    l1.insertAtEnd(30);
    l1.insertAtEnd(40);
    l1.insertAtEnd(50);
    l1.insertAtEnd(50);

    l1.printList();

    int middle = l1.getMiddle()->data;
    cout<<middle<<endl;

    return 0;
}