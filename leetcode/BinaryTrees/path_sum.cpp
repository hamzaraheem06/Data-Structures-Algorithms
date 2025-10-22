#include<iostream>
#include<vector>
#include<queue>
#include <optional> // for std::optional

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // Check if we reached a leaf node
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // Recurse for left and right subtrees
        int remaining = targetSum - root->val;
        return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
    }
};


int main() {
    return 0;
}