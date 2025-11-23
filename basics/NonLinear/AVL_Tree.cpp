#include<iostream>
#include<algorithm> // for std::max
using namespace std;

struct TreeNode {
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), height(0), left(nullptr), right(nullptr) {} // leaf height = 0
};

class AVL {
private:
    TreeNode* root;

    int get_height(TreeNode* node) {
        return node ? node->height : -1; // null height = -1 (consistent with leaf=0)
    }

    int balance_factor(TreeNode* root) {
        return get_height(root->left) - get_height(root->right);
    }

    bool is_balance(TreeNode* root) {
        if (!root) return true;
        int bf = balance_factor(root);
        return bf >= -1 && bf <= 1;
    }

    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);

        if (val < root->val)
            root->left = insert(root->left, val);
        else if (val > root->val)
            root->right = insert(root->right, val);
        else
            return root; // ignore duplicates

        root->height = 1 + max(get_height(root->left), get_height(root->right));

        if (!is_balance(root)) {
            if(is_left_heavy(root)) { // if left heavy, do right rotation
                // before doing the outer shift, check which children is inserting weight if any

                if (balance_factor(root->left) < 0) { // checking if the left is right heavy or not
                    root->left = leftRotate(root->left);
                }

                root = rightRotate(root);
            } else if(is_right_heavy(root)) { // if right heavt, do left rotation

                if (balance_factor(root->right) > 0) { // checking if the right is left heavy or not
                    root->right = rightRotate(root->right);
                }

                root = leftRotate(root);
            }
        }
            
        return root;
    }

    bool is_left_heavy(TreeNode* root) {
        return root && balance_factor(root) > 1;
    }

    bool is_right_heavy(TreeNode* root) {
        return root && balance_factor(root) < -1;
    }

    TreeNode* leftRotate(TreeNode* root) {
        if (!root) return root;

        TreeNode* newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;

        return newRoot;
    }

    TreeNode* rightRotate(TreeNode* root) {
        if(!root) return root;

        TreeNode* newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;

        return newRoot;
    }

    // Display tree in a tree-like (sideways) structure
    void display_tree(TreeNode* root, int space = 0, int indent = 5) {

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

    TreeNode* minimum(TreeNode* root) {
        if (!root) {
            cout << "Empty tree. \n";
            return nullptr;
        }
            
        TreeNode* temp = root;
        while(temp->left) {
            temp = temp->left;
        }

            return temp;
        }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        // standard BST delete (recursive)
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // node found
            if (!root->left || !root->right) {
                TreeNode* child = root->left ? root->left : root->right;
                delete root;
                return child;
            } else {
                // two children: get inorder successor
                TreeNode* succ = minimum(root->right);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }

        // update height
        root->height = 1 + max(get_height(root->left), get_height(root->right));

        if (!is_balance(root)) {
            if(is_left_heavy(root)) { // if left heavy, do right rotation
                // before doing the outer shift, check which children is inserting weight if any

                if (balance_factor(root->left) < 0) { // checking if the left is right heavy or not
                    root->left = leftRotate(root->left);
                }

                root = rightRotate(root);
            } else if(is_right_heavy(root)) { // if right heavt, do left rotation

                if (balance_factor(root->right) > 0) { // checking if the right is left heavy or not
                    root->right = rightRotate(root->right);
                }

                root = leftRotate(root);
            }
        }

        return root;
    }

public:
    AVL() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void remove(int val) {
        root = deleteNode(root, val);
    }

    void display() {
        display_tree(root);
    }
};

int main() {
    AVL tree;
    int nums[] = {15, 18, 16, 7, 3};

    for (int num : nums) {
        cout << "Inserting " << num << endl;
        tree.insert(num);
        tree.display();
    }

    int deletion[] = {16, 18};

    for (int num : deletion) {
        cout << "Deleting " << num << endl;
        tree.remove(num);
        tree.display();
    }

    return 0;
}