#include<iostream>
#include<unordered_set>
#include<algorithm>

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

    // Unordered set solution

    // we create a set that contains pointers to all the visited nodes
    // if during traversing, we find a node that is present in the visited nodes set,
    // we return true.

    // else if we get out of the loop, i.e. traversed the whole linked list or reached the end of the list,
    // we return false

    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;

        ListNode* temp = head;

        while(temp) {
            if (set.find(temp) != set.end()) return true; 
                
            set.insert(temp);

            temp = temp->next;
        }

        return false;
    }


    // Hare and tortoise algorithm
    // slow ( tortoise ) moves slow i.e. one step at a time
    // fast ( hare ) moves fast i.e. two steps at a time.

    // if there is a loop in the linked list, there will be a point when both pointers are at same node,
    // hence we return true


    // if the loop breaks i.e. fast has reached end ( a list that has an end, does not have a cycle )
    // hence we return false

    bool hasCycle2(ListNode *head) {

        if(!head || !head->next) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }

        return false;
    }
};

int main() {
    
    return 0;
}