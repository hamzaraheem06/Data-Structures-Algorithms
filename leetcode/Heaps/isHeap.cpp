#include<iostream>

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
    int count_nodes(TreeNode* root) {
        if (!root) return 0;

        return 1 + count_nodes(root->left) + count_nodes(root->right);
    }

    bool is_cbt(TreeNode* root, int max_index, int index = 0) {
        if (!root) return true; 

        if (index >= max_index) return false;

        return is_cbt(root->left, max_index, index * 2 + 1) && 
                is_cbt(root->right, max_index, index * 2 + 2); 
    }

    bool is_max(TreeNode* root) {
        if (!root) return true;
        // check children only if they exist
        if (root->left && root->val < root->left->val)  return false;
        if (root->right && root->val < root->right->val) return false;
        return is_max(root->left) && is_max(root->right);
    }

    bool isHeap(TreeNode* tree) {
        if (!tree) return true;

        int n = count_nodes(tree);

        return is_cbt(tree, n, 0) && is_max(tree);
    }
};

int main() {
    
    return 0;
}

 