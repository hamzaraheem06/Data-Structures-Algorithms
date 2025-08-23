#include<iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int val) {value = val; }
};

class LinkedList {
    Node* head;
    Node* tail;

    string toString(Node* head) const {
        if (!head->next) return to_string(head->value) + "--> nullptr\n"; // base condition

        return to_string(head->value) + "--> " + toString(head->next);
    }

    public: 
        LinkedList() {
            head = nullptr;
        }

        Node* front() {
            return head;
        }

        void push_front(int v) {
            Node* newNode = new Node(v);
            // new head node will point to last head
            newNode->next = head;
            // assigning new node as head
            head = newNode;
            if(newNode->next == nullptr) tail = newNode;
        }

        void push_back(int v) {
            Node* newNode = new Node(v);
            newNode->next = nullptr;

            if(!head) {
                head = newNode;
                tail = newNode;
                return;
            }

            // traverse to   last node
            // Node* it = head;
            // while(it->next != nullptr) {
            //     it = it->next;
            // }
            // it->next = newNode;

            // Now that we have tail, we can directly add to end without traversiong. 
            tail->next = newNode;

            tail = newNode;
        }

        void insert(int pos, int v) {
            if (pos < 1) return;

            if(pos == 1) {
                push_front(v);
                return;
            }

            Node* newNode = new Node(v);
            newNode->next = nullptr;

            Node* it = head;
            // go to one node back to where we want to insert, and make sure we do not exceed the end of the list
            for(int i = 1; i < pos - 1 && it; i++) {
                it = it->next;
            }

            if(!it) { //if the element is nullptr i.e. it is the end of list.
                cout<<"Position out of range!";
                delete newNode;
                return;
            }

            newNode->next = it->next;
            it->next = newNode;

            if(newNode->next == nullptr) tail = newNode;
        }

        void pop_front() {
            if (!head) return;

            Node* temp = head;

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

            Node* temp = head;

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

            Node* temp = head;

            for (int i = 1; i < pos - 1 && temp; i++) {
                temp = temp->next;
            }

            // if(!temp->next) {
            //     pop_back();
            //     return;
            // }

            if(!temp) return;

            
            Node* toDelete = temp->next;

            temp->next = temp->next->next;

            delete toDelete;
        }

        int position_of(int val) {
            Node* it = head;
            int pos = 1; 

            while(it && it->value != val ) {
                pos ++;
                it = it->next;
            }

            return (it != nullptr)? pos : -1;
        }

        int sum() {
            int sum = 0;
            Node* it = head;
            while(it) {
                sum += it->value;
                it = it->next;
            }

            return sum;
        }

        int sumRecursive(Node* head) {
            if (!head) return 0;

            return head->value + sumRecursive(head->next);
        }

        int sumRecursive() {
            int sum = sumRecursive(head);
            return sum;
        }

        void reverse() {

            if (!head || !head->next) return; // cannot reverse an empty or a single element list.

            Node* pre = nullptr;
            Node* cur = head;
            Node* next = head->next;
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

        // void display() {
        //     string list = "";
        //     Node* it = head;
        //     while(it->next != nullptr) {
        //         list.append(to_string(it->value));
        //         list.append("--> ");
        //         it = it->next;
        //     }

        //     list.append(to_string(it->value)).append("--> nullptr");


        //     cout<<list<<endl;
        // }
        
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
    list.push_back(2);
    list.push_back(3);
    list.push_front(3);
    list.insert(3, 5);

    cout << list;

    cout <<list.sumRecursive();

    return 0;
}