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

/*
A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
*/


class Solution {
  public:

    pair<bool, int> solve(TreeNode* root) {
        if(!root) return {true, 0};

        if(!root->left && !root->right) return {true, root->val};

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.first && right.first && (root->val == left.second + right.second)) {
            return {true, left.second + right.second + root->val};
        }

        return {false, 0};
    }

  // is sum of right subtree and left subtree not left and right node
    bool isSumTree(TreeNode* root) {
        return solve(root).first;
    }
};

int main() {
    
    return 0;
}

