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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while(true) {
            ListNode* tail = prev;
            for (int i = 1; i <= k && tail; i++) {
                tail = tail->next;
            }
            
            if (!tail) break;

            ListNode* rest = tail->next;
            
            tail->next = nullptr;

            ListNode* start = prev->next;

            ListNode* newHead = recursive_reverse(start);

            prev->next = newHead;

            start->next = rest;

            prev = start;
        }

        return dummy->next;
    }

    ListNode* recursive_reverse(ListNode* head) {
            if (!head || !head->next) return head;

            ListNode* rest = recursive_reverse(head->next);

            ListNode* next = head->next;
            next->next = head;
            head->next = nullptr;

            return rest;
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
    head->next->next->next->next->next = new ListNode(6);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    int k = 2;
    head = sol.reverseKGroup(head, k);

    cout << "Result: ";
    printList(head);

    return 0;
}