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


class Solution {
public:
    ListNode* addTwoNumbersShittyHamzaSolution(ListNode* l1, ListNode* l2) {
        int rem = 0;
        int sum = l1->val + l2->val + rem;
        rem = sum / 10; 
        sum = sum % 10;
        ListNode* res = new ListNode(sum);
        ListNode* tail = res;

        l1 = l1->next;
        l2 = l2->next;

        while(l1 && l2) {
            ListNode* node = new ListNode();
            sum = l1->val + l2->val + rem;
            rem = sum / 10;
            sum = sum % 10;
            node->val = sum;
            tail->next = node;
            tail = node;

            l1 = l1->next;
            l2 = l2->next;
        }

        // handle where l1 has remaning entries
        while(l1) {
            ListNode* node = new ListNode();
            sum = l1->val+ rem;
            rem = sum / 10;
            sum = sum % 10;
            node->val = sum;
            tail->next = node;
            tail = node;

            l1 = l1->next;
        }

        // handle where l2 has remaning entries
        while(l2) {
            ListNode* node = new ListNode();
            sum = l2->val+ rem;
            rem = sum / 10;
            sum = sum % 10;
            node->val = sum;
            tail->next = node;
            tail = node;

            l2 = l2->next;
        }

        // hanlde if there is some remainder left

        if (rem != 0) {
            ListNode* node = new ListNode(rem);
            tail->next = node;
            tail = node;
        }
        

        return res;
    }

    // What i pooped in above solution is that i have fucked DRY principle. 

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); 
        ListNode* tail = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {

            // handle all the addition part
            int sum = 0 + carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            // create a new node and assign it the value 
            ListNode* node = new ListNode(sum % 10);
            tail->next = node;
            
            // calculate sum for next step
            carry = sum / 10;

            // update the tail
            tail = node;
        }

        // currently the dummy is pointing to a dummy or what we can say is not required postion

        ListNode* result = dummy->next;

        delete dummy;

        return result;
    }
};

int main() {
    
    return 0;
}