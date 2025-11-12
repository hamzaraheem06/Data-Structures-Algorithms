#include<iostream>
#include<vector>
#include<unordered_set>

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

    void traverse_left(TreeNode* root, vector<int> & result) {
        if (!root) return;

        // Stop if it's a leaf
        if (!root->left && !root->right) return;

        result.push_back(root->val);

        if (root->left)
            traverse_left(root->left, result);
        else
            traverse_left(root->right, result);
    }

    void insert_leaves(TreeNode* root, vector<int>& result) {
        if(!root) return;

        if(!root->left && !root->right) result.push_back(root->val);

        insert_leaves(root->left, result);
        insert_leaves(root->right, result);
    } 

    void traverse_right(TreeNode* root, vector<int> & result) {
        if (!root) return;

        // Stop if it's a leaf
        if (!root->left && !root->right) return;

        if (root->right)
            traverse_right(root->right, result);
        else
            traverse_right(root->left, result);

        result.push_back(root->val);
    }



    vector<int> boundaryTraversal(TreeNode *root) {
        if(!root->left && !root->right) return {root->val};
        vector<int> result;
        result.push_back(root->val);

        traverse_left(root->left, result);

        insert_leaves(root, result);

        traverse_right(root->right, result);

        return result;
    }
};

int main() {
    
    return 0;
}

