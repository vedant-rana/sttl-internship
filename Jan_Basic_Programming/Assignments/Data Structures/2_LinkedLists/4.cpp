#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void printList(Node *&head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool detectCycle(Node *head)
{
    if (head == nullptr)
    {
        return false;
    }

    Node *fast = head, *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    printList(head);

    head->next->next->next->next->next->next = head->next->next;

    if (detectCycle(head))
    {
        cout << "Loop exist !!" << endl;
    }
    else
    {
        cout << "Loop not exist !!" << endl;
    }

    return 0;
}

/*
10 -> 20 -> 30 ->40
            |     |
            60 <- 50
*/