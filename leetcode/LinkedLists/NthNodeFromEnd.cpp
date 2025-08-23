#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// we will be using two pointers, these pointers will be at a lenght n from each other, in this way we when the fast pointer reaches the last position. The slow pointer should be at (n + 1)th position from end of the list.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head ) return head;
        
        ListNode* fast = head;

        for (int i = 1; i <= n; i++) {
            fast = fast->next;
        }

        if (!fast) { // handles the case when we want to remove the head of the linked list
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }

        ListNode* slow = head;

        while(fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* toDelete = slow->next;

        slow->next = slow->next->next;

        delete toDelete;
    }
};

int main() {
    
    return 0;
}