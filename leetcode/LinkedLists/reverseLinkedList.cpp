#include<iostream>

using namespace std;

//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Lets take an example: 

// 1 --> 2 --> 3 --> 4 --> 5 --> NULL

// reversed => 5 --> 4 --> 3 --> 2 --> 1 --> NULL

// can you see the difference? 
// firstly, all the links have been reversed 4 --> 5 changed to 5 --> or 4 <-- 5, and lastly the head of the list is now at the first element


class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = head->next;
        while (next) {
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }
        cur->next = pre; // handle the last connection
        delete next;
        head = cur;

        return head;
    }
};

int main() {
    
    return 0;
}

// Edge Case Check

// if (!head || !head->next) return;
// If the list is empty or has only one node, do nothing.

// Pointer Initialization
// ListNode* pre = nullptr;
// ListNode* cur = head;
// ListNode* next = head->next;

//        5 --> 6 --> 7 --> 8 --> nullptr
// pre   cur   next

// pre: Tracks the previous node (starts as nullptr).
// cur: Current node (starts at head).
// next: Next node (starts at head->next).

// Main Loop
// while (next != nullptr) {
//     cur->next = pre;
//     pre = cur;
//     cur = next;
//     next = next->next;
// }
// For each node:
// Reverse the link (cur->next = pre).
// Move pre and cur forward.
// Advance next.

// 1. first iteration: 
// nullptr <-- 5   6 --> 7 --> 8 --> nullptr
//           pre  cur   next
// 2. second iteration: 
// nullptr <-- 5 <-- 6   7 --> 8 --> nullptr
//                       pre  cur   next
// 3. third iteration: 
// nullptr <-- 5 <-- 6 <-- 7    8 --> nullptr
//                        pre  cur   next
// ==> next is at nullptr loop breaks
// notice that there is still one non-connected node

// Final Node
// cur->next = pre;
// nullptr <-- 5 <-- 6 <-- 7 <-- 8  nullptr
//                        pre  cur   next

// Delete the unused next pointer
// delete next;
// nullptr <-- 5 <-- 6 <-- 7 <-- 8  
//                        pre  cur

// Update Head
// head = cur;

// you know why head is there brooooooooo.
