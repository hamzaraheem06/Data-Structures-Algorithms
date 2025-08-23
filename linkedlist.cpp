#include<iostream>

using namespace std;

struct Node {
    int value;
    Node* next_ptr;
};

class LinkedList {
    Node* head;

    public:
        LinkedList() {
            head = NULL;
        }

        void addAtBeginning(int value) {
            Node* newNode = new Node(); // creating a new node in dynamic memory 
            newNode->value = value; // assigning the new value to be added to the new node.
            newNode->next_ptr = head;   // since the new node will contain the adress of the next node, which in case of adding at begining is the head of the linkedlist
            head = newNode; // since we are adding a node at beginning so we make the new node the new head of the linkedlist 
        }

        void addAtEnd(int value) {
            Node* newNode = new Node(); // creating the new node
            newNode->value = value; // assigning the new node the value to be stored
            newNode->next_ptr = NULL; // making the next_ptr member null since it is the end of the list

            if(!head){ //if the list is empty, we make the new node the head of the list. 
                head = newNode;
                return;
            }

            Node* temp = head; // traversing to the last node
            while(temp->next_ptr) {
                temp= temp->next_ptr;
            }

            temp->next_ptr = newNode; // giving the current last node, the address of the new node added at the beginning.  
        }

        void addAtPosition(int value, int position) {
            if(position < 1) {
                cout<<"Please enter a valid position. (>=1)";
                return;
            } 

            if(position == 1) {
                this->addAtBeginning(value);
                return;
            }

            Node* newNode = new Node();
            newNode->value = value;
            
            Node* temp = head;
            // Traverse to the node before the desired position
            for(int i = 1; i < position - 1 && temp; ++i) {
                temp = temp->next_ptr; // getting the pointer to the element just before the desired location.
            }

            if(!temp) { //if the next_pointer of the position-1 element is null i.e. it is last element.
                cout<<"Position out of range!";
                delete newNode;
                return;
            }

            newNode->next_ptr = temp->next_ptr;
            temp->next_ptr = newNode;
        }

        void displayList() {
            if(!head) {
                cout<<"The list is empty.";
                return;
            }

            Node* temp = head;
            
            while(temp) {
                cout<<temp->value<<"->";
                temp = temp->next_ptr;
            }
            cout<<"NULL"<<endl;
        }

        void deleteFromBeginning() {
            if(!head) {
                cout<<"The list is empty.";
                return;
            }

            Node* temp = head; 
            head = temp->next_ptr;
            delete temp;
        }

        void reverse ()  {
            Node* prev = nullptr;
            Node* cur = head;
            Node* next = head->next_ptr;

            while (head) {
                cur->next_ptr = prev;
                prev = cur;
                cur = next;
                next = next->next_ptr;
            }

            cur->next_ptr = prev;

            head = cur;
        }

        void deleteFromEnd() {
            if(!head) {
                cout<<"The list is empty.";
                return;
            }

            if(!head->next_ptr) { //if there is only one node in the list
                delete head;
                head = NULL;
                return;
            }

            Node* temp = head;
            while(temp->next_ptr->next_ptr) {
                temp = temp->next_ptr;
            }

            delete temp->next_ptr;

            temp->next_ptr = NULL;
        }

        void deleteFromPosition(int postion) {
            if (postion < 0 ) {
                cout<<"Invalid postion.";
                return;
            }
            
            if(postion == 1 ){
                deleteFromBeginning();
            }

            Node* temp = head;
            for( int i = 1; i < postion - 1 && temp ; i++) {
                temp = temp->next_ptr;
            }

            if(!temp || !temp->next_ptr) {
                cout<<"Position out of range."<<endl;
                return; 
            }

            Node* nodeToDelete = temp->next_ptr;
            temp->next_ptr = temp->next_ptr->next_ptr;

            delete nodeToDelete;

        }

    // Cleanup
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next_ptr;
            delete temp;
        }
    }
};


int main() {
    LinkedList list1;

    // Insert elements at the end
    list1.addAtEnd(10);
    list1.addAtEnd(20);

    // Insert element at the beginning
    list1.addAtBeginning(5);

    // Insert element at a specific position
    list1.addAtPosition(15, 3);
 
    cout << "Linked list after insertions: ";
    list1.displayList();

    // Delete element from the beginning
    list1.deleteFromBeginning();
    cout << "Linked list after deleting from beginning: ";
    list1.displayList();

    // Delete element from the end
    list1.deleteFromEnd(); 
    cout << "Linked list after deleting from end: ";
    list1.displayList();

    // Delete element from a specific position
    list1.deleteFromPosition(2);
    cout << "Linked list after deleting from position 2: ";
    list1.displayList();

    return 0;
}
