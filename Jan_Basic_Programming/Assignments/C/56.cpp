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

    void inserAtFirst(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head=newNode;
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

    void deleteAtFront(){
        if(head == nullptr){
            return;
        }
        Node* temp = head;
        head =head->next;

        delete temp;
    }

    void deleteAtEnd(){
        if(head == nullptr){
            return;
        }
        if(head->next == nullptr){
            Node * t = head;
            head = nullptr;
            delete t;
        }
        
        Node* temp = head;

        while(temp->next->next !=nullptr){
            temp = temp->next;
        }

        Node* n = temp->next;
        temp->next = nullptr;

        delete n;
    }

    void printList(){
        Node* temp = head;

        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    LinkedList l1;
    l1.insertAtEnd(10);
    l1.insertAtEnd(20);
    l1.insertAtEnd(30);

    l1.inserAtFirst(40);
    l1.inserAtFirst(50);

    l1.printList();

    l1.deleteAtEnd();
    l1.printList();
    l1.deleteAtFront();
    l1.printList();
    
    return 0;
}