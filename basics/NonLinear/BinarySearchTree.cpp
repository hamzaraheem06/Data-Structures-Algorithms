#include<iostream>
using namespace std;


struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
    private: 
    public:
    Node* root;
        BinarySearchTree() : root(nullptr) {}

        void insert(int value) {
            Node* newNode = new Node(value);
            if (!root) {
                root = newNode;
                return;
            }
            
            Node* temp = root;

            while (temp) {
                if (value > temp->val ) {
                    if (temp->right)
                        temp = temp->right;
                    else {
                        temp->right = newNode; 
                        return;
                    }
                } else {
                    if (temp->left) 
                        temp = temp->left;
                    else {
                        temp->left = newNode;
                        return;
                    }
                }  
            } 
        }


        Node* min() {
            if (!root) {
                cout << "Empty tree. \n";
                return nullptr;
            }
            
            Node* temp = root;
            while(temp->left) {
                temp = temp->left;
            }

            return temp;
        }

        Node* max() {
             if (!root) {
                cout << "Empty tree. \n";
                return nullptr;
            }
            
            Node* temp = root;
            while(temp->right) {
                temp = temp->right;
            }

            return temp;
        }

        Node* search(int key) {
            if (!root) {
                cout << "Empty tree. \n";
                return nullptr;
            }

            Node* cur = root;

            while(cur) {
                if(cur->val == key) return cur;
                else if (cur->val > key) cur = cur->left;
                else cur = cur->right;
            }

            return nullptr;
        }

        Node* searchTree(Node* x, int key) {
            if (!x || x->val == key) return x;

            if(x->val > key) return searchTree(x->left, key);
            else return searchTree(x->right, key);
        }

        void remove(int key) {
            if (!root) {
                cout << "Tree is empty.\n";
                return;
            }

            Node* parent = nullptr;
            Node* cur = root;

            // Find the node and its parent
            while (cur && cur->val != key) {
                parent = cur;
                if (key < cur->val)
                    cur = cur->left;
                else
                    cur = cur->right;
            }

            if (!cur) {
                cout << "Key not found.\n";
                return;
            }

            // Case 1: Node has no children (leaf)
            if (!cur->left && !cur->right) {
                if (!parent) {
                    root = nullptr; // root node
                } else if (parent->left == cur) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
                delete cur;
            }

            // Case 2: Node has one child
            else if (!cur->left || !cur->right) {
                Node* child = (cur->left) ? cur->left : cur->right;
                if (!parent) {
                    root = child; // deleting root
                } else if (parent->left == cur) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
                delete cur;
            }

            // Case 3: Node has two children
            // replace cur value with its successor, then delete the successor node
            else {
                Node* successorParent = cur;
                Node* successor = cur->right;

                // Find inorder successor (smallest in right subtree)
                while (successor->left) {
                    successorParent = successor;
                    successor = successor->left;
                }

                cur->val = successor->val; // replace value

                // Delete successor node
                if (successorParent->left == successor)
                    successorParent->left = successor->right;
                else
                    successorParent->right = successor->right;

                delete successor;
            }

            cout << "Deleted " << key << " successfully.\n";
        }

        // Display tree in a tree-like (sideways) structure
        void display(Node* root, int space = 0, int indent = 5) {

            if (root == nullptr)
                return;

            // Increase distance between levels
            space += indent;

            // Print right child first
            display(root->right, space);

            // Print current node after spacing
            cout << endl;
            for (int i = indent; i < space; i++)
                cout << " ";
            cout << root->val << "\n";

            // Print left child
            display(root->left, space);
        }

};

int main() {
    BinarySearchTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(45);
    tree.insert(65);

    tree.display(tree.root);

    tree.remove(50);

    tree.display(tree.root);

    // cout << "Min is " << tree.min()->val << endl;
    // cout << "Max is " << tree.max()->val << endl;

    // Node* searchedNode = tree.search(40);

    // cout << (searchedNode ? "Key exists." : "Key doesn't exist.") << endl; 
    
    return 0;

}