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

    /*
        Sorta extenstion to the same tree problem. 
        check if the tree is empty or single node, then it is symmetric
        else modify the same tree code to check the mirror trees.
    */

    bool check_equal(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true; // empty trees are equal

        if (!p || !q) return false; // if at any point one of the root become null, while other is not we return false

        return p->val == q->val && check_equal(p->left, q->right) && check_equal(p->right, q->left);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check_equal(p, q);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        return isSameTree(left, right);
    }
};

int main() {
    
    return 0;
}