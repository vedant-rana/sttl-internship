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

int getLength(Node *n)
{
    int count = 0;
    while (n != nullptr)
    {
        count++;
        n = n->next;
    }
    return count;
}

int intersectionPoint(Node *n1, Node *n2)
{
    // get length of both list
    int l1 = getLength(n1);
    int l2 = getLength(n2);

    // create two pointer 1,2 ; 1 will always points to the large list
    Node *ptr1, *ptr2;
    int diff = 0;

    if (l1 > l2)
    {
        diff = l1 - l2;
        ptr1 = n1;
        ptr2 = n2;
    }
    else
    {
        diff = l2 - l1;
        ptr1 = n2;
        ptr2 = n1;
    }

    // move ptr1 till diff = 0
    while (diff)
    {
        ptr1 = ptr1->next;
        if (ptr1 == nullptr)
        {
            return -1;
        }
        diff--;
    }

    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->data == ptr2->data)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Node *head2 = new Node(70);
    head2->next = new Node(60);
    head2->next->next = head->next->next->next;

    cout << intersectionPoint(head, head2) << endl;
    return 0;
}

/*
10 - 20 - 30 - 40 - 50
                |
                60
                |
                70
*/