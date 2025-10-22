#include<iostream>
#include<vector>
using namespace std;


struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
    private: 
        Node* root;

        Node* recursiveInsert(Node* root, int value) {
            if(!root) {
                root = new Node(value);
                return root;
            }

            if (value < root->val)
                root->left = recursiveInsert(root->left, value);
            else
                root->right = recursiveInsert(root->right, value);
            return root;
        }

        // go to root, print it, go to left subtree, go to right subtree
        // Root -> Left -> Right
        void pre_order(Node* root) {
            if (!root) return;
            cout << root->val << " ";

            pre_order(root->left);
            pre_order(root->right);
        } 


        // Traverse left subtree, print it, go to root, print, go to right subtree
        //  Left -> Root -> Right
        void in_order(Node* root) {
            if(!root) return;
            in_order(root->left);
            cout << root->val << " ";

            in_order(root->right);
        }

        // Traverse left subtree, then right and then root;
        // Left -> Right > Root;
        void post_order(Node* root) {
            if(!root) return;

            post_order(root->left);
            post_order(root->right);
            cout << root->val << " ";
        }

        int depth_of_node(Node* root, int val, int depth = 0) {
            if (!root) return -1;

            if (root->val == val) return depth;

            if (root->val > val) return depth_of_node(root->left, val, depth + 1);
            else return depth_of_node(root->right, val, depth + 1);
        }

        int height_of_node(Node* root) {
            if (!root) return 0;

            return 1 + max(height_of_node(root->left), height_of_node(root->right));
        }

        // Display tree in a tree-like (sideways) structure
        void display_tree(Node* root, int space = 0, int indent = 5) {

            if (root == nullptr)
                return;

            // Increase distance between levels
            space += indent;

            // Print right child first
            display_tree(root->right, space);

            // Print current node after spacing
            cout << endl;
            for (int i = indent; i < space; i++)
                cout << " ";
            cout << root->val << "\n";

            // Print left child
            display_tree(root->left, space);
        }

        bool check_equal(Node* root1, Node* root2) {
            if(!root1 && !root2) return true;

            return root1->val == root2->val && check_equal(root1->left, root2->left) && check_equal(root1->right, root2->right);
        }

        bool check_valid(Node* root, int minVal = INT_MIN, int maxVal = INT_MAX) {
            if (!root) return true;

            if (root->val <= minVal || root->val >= maxVal)
                return false;

            return check_valid(root->left, minVal, root->val) &&
                check_valid(root->right, root->val, maxVal);
        }

    
    public:
        BinarySearchTree() : root(nullptr) {}

        BinarySearchTree(vector<int> &arr) : root(nullptr) {
            for (int num: arr) {
                this->rec_insert(num);
            }
        }

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


        void rec_insert(int val) {
            root = recursiveInsert(root, val);
        }


        Node* minimum() {
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

        Node* maximum() {
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

        Node* successor(int key) {
            if(!root) {
                cout << "Empty tree.\n";
                return nullptr;
            }

            Node* cur = search(key);

            Node* s = cur->right;

            while(s) {
                s = s->left;
            }

            return s;
        }

        Node* predecessor(int key) {
            if(!root) {
                cout << "Empty tree.\n";
                return nullptr;
            }

            Node* cur = search(key);

            Node* p = cur->left;

            while(p) {
                p = p->right;
            }

            return p;
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

        int depth(int val) {
            return depth_of_node(root, val);
        }

        int height(int val) {
            Node* cur = search(val);

            if (!cur) return -1;

            return height_of_node(cur);
        }

        void preOrder() {
            pre_order(root);
        }

        void inOrder() {
            in_order(root);
        }

        void postOrder() {
            post_order(root);
        }

        bool equal(BinarySearchTree& other) {
            return check_equal(root, other.root);
        }

        bool isValid() {
            return check_valid(root);
        }

        void display() {
            display_tree(root);
        }

};

int main() {
    // BinarySearchTree tree;
    
    // tree.insert(50);
    // tree.insert(30);
    // tree.insert(70);
    // tree.insert(20);
    // tree.insert(40);
    // tree.insert(60);
    // tree.insert(45);
    // tree.insert(65);

    // tree.display(tree.root);

    // tree.remove(50);

    vector<int> nums1{8, 5, 7, 2, 10, 12};
    vector<int> nums2{8, 5, 7, 2, 10, 12};
    BinarySearchTree t1(nums1);

    BinarySearchTree t2(nums2);

    cout << "BST 1: "<< endl;
    t1.display();


    cout << "BST 2: "<< endl;
    t2.display();

    cout << "Are equal? " <<  t1.equal(t2) << endl;

    cout << "T1 is valid? " << t1.isValid() << endl;

    // cout << "Min is " << tree.min()->val << endl;
    // cout << "Max is " << tree.max()->val << endl;

    // Node* searchedNode = tree.search(40);

    // cout << (searchedNode ? "Key exists." : "Key doesn't exist.") << endl; 
    
    return 0;

}