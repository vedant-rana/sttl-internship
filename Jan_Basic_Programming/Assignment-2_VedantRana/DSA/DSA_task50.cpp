#include <iostream>
#include <cstdint>

class Node {
public:
    int data;
    Node* xorPointer;

    Node(int value) : data(value), xorPointer(nullptr) {}
};

class XORLinkedList {
private:
    Node* head;

public:
    XORLinkedList() : head(nullptr) {}

    
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->xorPointer = head;
        
        if (head != nullptr) {
            head->xorPointer = XOR(head->xorPointer, newNode);
        }

        head = newNode;
    }

    
    void display() const {
        Node* current = head;
        Node* prev = nullptr;
        Node* next;

        while (current != nullptr) {
            std::cout << current->data << " ";

            
            next = XOR(prev, current->xorPointer);

            prev = current;
            current = next;
        }

        std::cout << "\n";
    }

private:
    
    Node* XOR(Node* a, Node* b) const {
        return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
    }
};

int main() {
    XORLinkedList xorList;

    
    xorList.insert(10);
    xorList.insert(20);
    xorList.insert(30);
    xorList.insert(40);

    
    std::cout << "XOR Linked List: ";
    xorList.display();

    return 0;
}
