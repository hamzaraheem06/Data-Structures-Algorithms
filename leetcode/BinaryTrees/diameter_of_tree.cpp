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
    Diameter: longest path between two nodes in the tree

    What i am thinking rn is diameter = max path length in right subtree from root + max path lenght on left subtree from root;

    However, it is not necessary that the longest path passes through the root, so we have to also find the diamter of the right and left subtree, and then return the maximum value.
    */
    int height(TreeNode* root) {
        if (!root) return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);


        return max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
    }

    /*
    Time complexity:
    we are traversing the tree once so that is O(n)


    for each of that, we are calling the height function which traverses the tree again 

    so the overall time complexity is: O (n^2)

    How can we make it O (n)?? see we are calling height again which is increasing our TC, can we merge that when we back track we return the diameter along with the height? yes, we can return a pair (diameter, height) instead of a single value
    */

    pair<int, int> diameter(TreeNode* root) {
        if (!root) return pair<int, int>(0, 0);

        pair<int, int> left = diameter(root->left);
        pair<int, int> right = diameter(root->right);

        int myDiameter = left.second + right.second;

        int result = max(left.first, max(right.first, myDiameter));

        int myheight = 1 + max(left.second, right.second);

        return pair<int, int>(result, myheight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};

int main() {
    
    return 0;
}