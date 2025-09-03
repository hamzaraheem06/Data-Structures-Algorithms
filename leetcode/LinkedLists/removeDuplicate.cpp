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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* cur = head;
        ListNode* next = cur->next;

        while(cur) {
            while(next && next->val == cur->val) {
                next = next->next;
            }

            cur->next = next;
            cur = next;
            if (next) next = next->next;
        }

        return head;
    }
};

// Gpt solution

class SolutionGPT {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next; // skip duplicate
            } else {
                cur = cur->next; // move forward
            }
        }
        return head;
    }
};


int main() {
    
    return 0;
}