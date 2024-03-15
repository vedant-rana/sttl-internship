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

class circularLinkedList{
    private: 
    Node* head;
    Node* tail;

    public:
    circularLinkedList(){
        this->head = nullptr;
    }

    void insertAtEnd(int data){
        Node* n= new Node(data);

        if(head == nullptr){
            head = n;
            tail=n;
            tail->next=head;
            n->next=n;
            return;
        }

        n->next = tail->next;
        tail->next = n;
        tail = tail->next;

    }

    void deleteAtEnd(){
        if(head==nullptr){
            return;
        }

        if(head->next == head){
             Node * t = head;
            head = nullptr;
            delete t;
        }

        Node* temp = head;
        while(temp->next != tail){
            temp = temp-> next;
        }

        Node* dn = tail;
        temp->next = tail->next;
        tail = temp;
        delete dn;
    }

    void print(){
        Node *temp = head;
        while(temp->next != head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        cout<<temp->data<<endl;
       }
};


int main()
{
    circularLinkedList l1;

    l1.insertAtEnd(10);
    l1.insertAtEnd(20);
    l1.insertAtEnd(30);
    l1.insertAtEnd(40);
    l1.insertAtEnd(50);

    l1.print();

    l1.deleteAtEnd();

    l1.print();
    
    return 0;
}