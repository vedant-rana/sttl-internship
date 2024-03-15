#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int x){
        this->val = x;
        this->next =nullptr;
    }
};

ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    l1 = reverseLinkedList(l1);
    l2 = reverseLinkedList(l2);

    int carry = 0;
    ListNode* result = nullptr;
    ListNode* current = nullptr;

     while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;

        if (result == nullptr) {
            result = new ListNode(sum % 10);
            current = result;
        } else {
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return reverseLinkedList(result);
}

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
     ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "Input Linked Lists:" << endl;
    printLinkedList(l1);
    printLinkedList(l2);

    ListNode* sumResult = addTwoNumbers(l1, l2);

    cout << "Sum of Linked Lists:" << endl;
    printLinkedList(sumResult);

    return 0;
}