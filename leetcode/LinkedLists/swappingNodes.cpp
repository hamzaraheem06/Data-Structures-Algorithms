// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* s, * e;
        ListNode* temp = head;
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }

        s = temp;

        ListNode* fast = head;

        for (int i = 1; i <= k; i++) {
            fast = fast->next;
        }  
        
        ListNode* slow = head;

        while(fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        e = slow->next;

        int val = e->val;

        e->val = s->val;
        
        s->val = val;

        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    int k = 2;
    head = sol.swapNodes(head, k);

    // cout << "After swapping " << k << "th node from start and end: ";
    printList(head);

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}