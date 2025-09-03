#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// create a dummy node to keep the order of list while swapping. 
// make the dummy point to head of the original list

// make a cur pointer (swapping node) with next pointer (to be swapped with node).

// make a prev pointer to keep track of the cur pointer, 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If list is empty or has only one node, no swap needed
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy(0); // Dummy node to handle head updates
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* next = curr->next; // Next node to swap with
            ListNode* after = next->next;

            // Swap nodes
            prev->next = next;    // Previous points to next
            next->next = curr;    // Next points to current
            curr->next = after;  // Current points to after

            // Move pointers
            prev = curr;
            curr = after;
        }

        return dummy.next; // Return new head
    }


    ListNode* swapPairsReverse(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode* rest = swapPairsReverse(head->next);

        ListNode* next = head->next;
        next->next = head;
        head->next = rest;

        head = next; 
        return head;
    }
};
int main() {
    // LinkedList list;
    // list.push_back(1);
    // list.push_back(2);
    // list.push_back(3);
    // list.push_back(4);
    // // list.push_back(5);

    // Solution s = Solution();

    // s.swapPairs(list.front());

    // cout << list;

    return 0;
}