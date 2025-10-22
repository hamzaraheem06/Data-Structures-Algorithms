#include<iostream>
#include<vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public: 
    // inorder traversal:
    // Left -> Root -> Right

    /*
    We understand the basic inorder traversal algorithm

    We write the simple algo for inorder, modify its signature to accept the reference of the resulting vector

    and then instead of printing the value of root as in simple algo, we push the vlaue in the vector

    After the traversal will be completed, we will have the answer in the result vector
    */

    void inorder(TreeNode* root, vector<int> &result) {
        if (!root) return;

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);

    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        inorder(root, result);
        return result;
    }
};


// Insert function (pass root by reference!)
void insert(TreeNode*& root, int value) {
    if (!root) {
        root = new TreeNode(value);
        return;
    }

    TreeNode* temp = root;
    while (true) {
        if (value > temp->val) {
            if (temp->right)
                temp = temp->right;
            else {
                temp->right = new TreeNode(value);
                break;
            }
        } else {
            if (temp->left)
                temp = temp->left;
            else {
                temp->left = new TreeNode(value);
                break;
            }
        }
    }
}

// Create BST from vector
TreeNode* createTree(const vector<int>& nums) {
    TreeNode* root = nullptr;
    for (int num : nums) {
        insert(root, num);
    }
    return root;
}


int main() {
    vector<int> num1 = {1, 2, 3};
    vector<int> num2 = {1, 2, 3};

    TreeNode* tree1 = createTree(num1);

    Solution s;

    vector<int> result = s.inorderTraversal(tree1);

    for (int num: result) {
        cout << num << "  ";
    }

    // Cleanup memory (simple version)
    delete tree1;

    return 0;
}