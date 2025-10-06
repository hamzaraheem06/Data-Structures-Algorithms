#include<iostream>

using namespace std;

// Circular linked list is an extension to singly linked list, with the extension that the next of the last pointer points to the head of the list.

// every node has a successor, the last node is succeeded by the first node.
// every node has a predecessor, the first node is predeceeded by the last node.

// representation: 
// 1 --> 2 --> 3 --> 4 --
// ^                    /
//  \                  /
//    ----------------

// its very obvious through representation that how can we get a circular linked list out the singly linked list, we need to set the next of the last node to the head of the list.

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};


class CircularLinkedList {
    private: 
        Node* list; // points to the last node of the non-empty linked list.
        int length;

    public:
        CircularLinkedList() {
            list = nullptr;
            length = 0;
        }

        bool empty() {
            return list == nullptr;
        }

        void display() {
            if (empty()) {
                cout << "NULL";
                return;
            }

            Node* temp = list->next;

            do {
                cout << temp->val << " --> ";
                temp = temp->next;
            } while(temp != list->next);
            cout << endl;
            return;
        }

        void push_front(int val) {
            Node* newNode = new Node(val);
            if (empty()) {
                list = newNode;
                list->next = list; // points to itself
                return;
            }

            // insert newNode after last but before head
            newNode->next = list->next;
            list->next = newNode;
        }

        void push_back(int val) {
            Node* newNode = new Node(val);
            if (empty()) {
                list = newNode;
                list->next = list; // points to itself
                return;
            }

            newNode->next = list->next;
            list->next = newNode;
            list = newNode;
        }

        void pop_front() {
            if (empty()) return;

            // Case: only one node
            if (list == list->next) {
                delete list;
                list = nullptr;
                return;
            }

            Node* head = list->next;

            list->next = head->next;

            delete head;

            head = nullptr;
        }

        void pop_back() {

            if (empty()) return;

            // Case: only one node
            if (list == list->next) {
                delete list;
                list = nullptr;
                return;
            }

            Node* temp = list->next;

            while(temp->next != list) temp = temp->next;

            temp->next = list->next;

            delete list;

            list = temp;
        }
        
};

int main() {
    CircularLinkedList cl;

    cl.push_front(1);
    // cl.display();
    cl.push_front(2);
    // cl.display();
    cl.push_front(3);
    // cl.display();  
    cl.push_back(4);
    // cl.display(); 
    cl.push_back(3);
    cl.display(); 

    cl.pop_front();
    cl.display();

    cl.pop_front();
    cl.display();

    cl.pop_back();
    cl.display();

    cl.pop_back();
    cl.display();

    cl.pop_back();
    cl.display();

    cl.pop_back();
    cl.display();

    return 0;
}