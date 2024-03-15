#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (!head || !head->next) {
        
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next) {
        if (slow == fast) {
            
            return true;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    
    return false;
}

int main() {
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;  

    
    bool hasCycleResult = hasCycle(head);

    if (hasCycleResult) {
        cout << "The linked list has a cycle.\n";
    } else {
        cout << "The linked list does not have a cycle.\n";
    }

    
    ListNode *current = head;
    ListNode *nextNode;

    while (current) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
