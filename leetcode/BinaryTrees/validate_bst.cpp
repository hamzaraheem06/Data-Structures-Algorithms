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
    // Rule for a valid binary tree:
    // For each node, the value of node should be greater than its left child and smaller than right child;

    // speaking in another way, a value for a node must be in a particular range; 
    // left child of a node cannot exceed the parent's value, however it can be anything in range (-inf, parent_value)

    // Similarly, right child cannot have value less than the parent's value, but can have any value (parent_value, +inf)

    // if a node's value doesnt satisfy this range, it is not a valid node;

    bool validate_tree(TreeNode* root, long min, long max) {
        if (!root) return true;

        if (root->val <= min || root->val >= max) return false;

        //max value for a left child is roots value
        // min value for right child is roots value
        return validate_tree(root->left, min, root->val) && validate_tree(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return validate_tree(root, LONG_MIN, LONG_MAX);
    }
};

int main() {
    
    return 0;
}