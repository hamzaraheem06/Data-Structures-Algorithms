#include<iostream>
#include<cmath>

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
    ListNode* middleNode(ListNode* head) {
        // Naive Solution would be:
        // find the number of elements in the linked list
        // use ceil( (n + 1) / 2 ) to find the middle index, and traverse to that node and return it.

        // int n = 1;

        // ListNode* temp = head;

        // while(temp) {
        //     n ++;
        //     temp = temp->next;
        // }

        // int mid = ceil((n + 1) / 2);

        // temp = head;

        // for (int i = 1; i < mid; i++) {
        //     temp = temp->next;
        // }

        // return temp;

        // This Solution is taking O (n) [to find the number of elements] + O (n / 2) [to traverse to mid]

        // Better Approach:

        // Hare and tortoise algorithm
        // slow ( tortoise ) moves slow i.e. one step at a time
        // fast ( hare ) moves fast i.e. two steps at a time.

        // if hare moves 50 steps, the tortoise will move half i.e. 50 / 2 = 25 steps.

        // Consequently, when the hare will be at the end of the list. The tortoise will be at the half way mark, i.e. middle of the linked list.

        ListNode* hare = head;
        ListNode* tortoise = head;

        while (hare && hare->next) {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }

        return tortoise;
    }
};

int main() {
    
    return 0;
}