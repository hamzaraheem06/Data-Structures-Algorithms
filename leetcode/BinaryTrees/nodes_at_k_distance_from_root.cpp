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

    void nodes_at_k(TreeNode* root, int k, vector<int>& nums) {
        if (!root || k < 0) return;

        if (k == 0) nums.push_back(root->val);

        nodes_at_k(root->left, k - 1, nums);
        nodes_at_k(root->right, k - 1, nums);
    }

    vector<int> nodesAtK(TreeNode* root, int k) {
        vector<int> result;
        nodes_at_k(root, k, result);
        return result;
    }


};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5); 
    root->left->left = new TreeNode(6); 
    root->left->right = new TreeNode(2); 
    root->left->right->left = new TreeNode(7); 
    root->left->right->right = new TreeNode(4); 
    
    root->right = new TreeNode(1); 
    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(0);

    Solution s;
    vector<int> result = s.nodesAtK(root, 2);

    for (int num : result) {
        cout << num << "  ";
    }

    delete root;
    return 0;
}