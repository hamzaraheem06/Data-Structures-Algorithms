#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class LinkedList {
    ListNode* head;
    ListNode* tail;

    string toString(ListNode* head) const {
        if (!head->next) return to_string(head->val) + "--> nullptr\n"; // base condition

        return to_string(head->val) + "--> " + toString(head->next);
    }

    public: 
        LinkedList() {
            head = nullptr;
        }

        ListNode* front() {
            return head;
        }

        void push_front(int v) {
            ListNode* newListNode = new ListNode(v);
            // new head ListNode will point to last head
            newListNode->next = head;
            // assigning new ListNode as head
            head = newListNode;
            if(newListNode->next == nullptr) tail = newListNode;
        }

        void push_back(int v) {
            ListNode* newListNode = new ListNode(v);
            newListNode->next = nullptr;

            if(!head) {
                head = newListNode;
                tail = newListNode;
                return;
            }

            // traverse to   last ListNode
            // ListNode* it = head;
            // while(it->next != nullptr) {
            //     it = it->next;
            // }
            // it->next = newListNode;

            // Now that we have tail, we can directly add to end without traversiong. 
            tail->next = newListNode;

            tail = newListNode;
        }

        void insert(int pos, int v) {
            if (pos < 1) return;

            if(pos == 1) {
                push_front(v);
                return;
            }

            ListNode* newListNode = new ListNode(v);
            newListNode->next = nullptr;

            ListNode* it = head;
            // go to one ListNode back to where we want to insert, and make sure we do not exceed the end of the list
            for(int i = 1; i < pos - 1 && it; i++) {
                it = it->next;
            }

            if(!it) { //if the element is nullptr i.e. it is the end of list.
                cout<<"Position out of range!";
                delete newListNode;
                return;
            }

            newListNode->next = it->next;
            it->next = newListNode;

            if(newListNode->next == nullptr) tail = newListNode;
        }

        void pop_front() {
            if (!head) return;

            ListNode* temp = head;

            head = head->next;

            delete temp;
        }

        void pop_back() {
            if (!head) return;

            if (!head->next) {
                delete head;
                head = nullptr;
                return;
            }

            ListNode* temp = head;

            while (temp->next->next) {
                temp = temp->next;
            }

            delete temp->next;
            temp->next = nullptr;

        }

        void erase(int pos) {
            if (pos < 1) return;

            if (pos == 1) {
                pop_front();
                return;
            }

            ListNode* temp = head;

            for (int i = 1; i < pos - 1 && temp; i++) {
                temp = temp->next;
            }

            // if(!temp->next) {
            //     pop_back();
            //     return;
            // }

            if(!temp) return;

            
            ListNode* toDelete = temp->next;

            temp->next = temp->next->next;

            delete toDelete;
        }

        int position_of(int val) {
            ListNode* it = head;
            int pos = 1; 

            while(it && it->val != val ) {
                pos ++;
                it = it->next;
            }

            return (it != nullptr)? pos : -1;
        }

        int sum() {
            int sum = 0;
            ListNode* it = head;
            while(it) {
                sum += it->val;
                it = it->next;
            }

            return sum;
        }

        int sumRecursive(ListNode* head) {
            if (!head) return 0;

            return head->val + sumRecursive(head->next);
        }

        int sumRecursive() {
            int sum = sumRecursive(head);
            return sum;
        }

        void reverse() {

            if (!head || !head->next) return; // cannot reverse an empty or a single element list.

            ListNode* pre = nullptr;
            ListNode* cur = head;
            ListNode* next = head->next;
            while (next != nullptr) {
                cur->next = pre;
                pre = cur;
                cur = next;
                next = next->next;
            }
            cur->next = pre;
            tail = head;
            head = cur;
        }

        ListNode* recursive_reverse(ListNode* head) {
            if (!head || !head->next) return head;

            ListNode* rest = recursive_reverse(head->next);

            ListNode* next = head->next;
            next->next = head;
            head->next = nullptr;

            return rest;
        }   // use stayingfun to visualize this. 

        void recursive_reverse() {
            head = recursive_reverse(head);
        }

        void swapPairs() {
            // If list is empty or has only one node, no swap needed
            if (!head || !head->next) {
                return;
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
                curr->next = after;  // Current points to next->next

                // Move pointers
                prev = curr;
                curr = after;
            }

            head = dummy.next;
        }

        void display() {
            string list = "";
            ListNode* it = head;
            while(it->next != nullptr) {
                list.append(to_string(it->val));
                list.append("--> ");
                it = it->next;
            }

            list.append(to_string(it->val)).append("--> nullptr");


            cout<<list<<endl;
        }
        
        // overloading the << operator to call toString automatically.
        friend ostream& operator<<(ostream& os, const LinkedList& list) {
            if (!list.head) {
                os << "nullptr";
            } else {
                os << list.toString(list.head);
            }
            return os;
        }
};

int main() {
    LinkedList list = LinkedList();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    // list.push_back(5);
    
    list.swapPairs();

    cout <<list;

    return 0;
}