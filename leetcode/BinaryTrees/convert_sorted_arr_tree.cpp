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
    /*
    // note:  from leetcode solution: Vansh Rana 

    Intuition

We want to convert a sorted array into a height-balanced binary search tree (BST). A height-balanced BST requires that the left and right subtrees of every node differ in height by at most 1.
By choosing the middle element of the array as the root, we ensure that the left and right subtrees have roughly equal size, maintaining balance.
Approach

    If the input array is empty, return null.
    Recursively pick the middle element of the current subarray as the root node.
    Recursively build the left subtree from the subarray before the middle element.
    Recursively build the right subtree from the subarray after the middle element.
    Return the constructed node.

Complexity

    Time complexity: O(n), because each element of the array is visited exactly once.
    Space complexity: O(h), where (h) is the height of the tree (due to recursion stack). In the worst case of a skewed recursion, (h = \log n).


    */

    TreeNode* bst(vector<int> & nums, int start, int end) {
        if (start > end) return nullptr; // base case

        int mid = (start + end) / 2;

        TreeNode* node = new TreeNode(nums[mid]);

        node->left = bst(nums, start, mid - 1);
        node->right = bst(nums, mid + 1, end);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;

        return bst(nums, 0, nums.size() - 1);
    }
};

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

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    Solution s;

    TreeNode* root = s.sortedArrayToBST(nums);

    display_tree(root);

    return 0;
}