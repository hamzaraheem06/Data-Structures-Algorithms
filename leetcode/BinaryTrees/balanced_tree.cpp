#include<iostream>
#include<cmath>
#include<queue>
#include<optional>

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
Balanced Binary Tree:
The height difference between the left and right subtree of every node is at most 1.
*/

class Solution {
    public: 
    // // O (n^2) TC solution

    // int height(TreeNode* root) {
    //     if (!root) return 0;        

    //     return 1 + max(height(root->left), height(root->right));
    // }


    // bool isBalanced(TreeNode* root) {
    //     if (!root || (!root->left && !root->right)) return true;

    //     bool isLeft = isBalanced(root->left);
    //     bool isRight = isBalanced(root->right);

    //     int hl = height(root->left);
    //     int hr = height(root->right);

    //     return isLeft && isRight && abs(hl - hr) <= 1;
    // }


    pair<bool, int> balanaced(TreeNode* root) {
        if (!root) return {true, 0};

        if (!root->left && !root->right) return {true, 1};

        pair<bool, int> isLeft = balanaced(root->left);
        pair<bool, int> isRight = balanaced(root->right);

        bool result = isLeft.first && isRight.second && abs(isLeft.second - isRight.second) <= 1;

        int ch = 1 + max(isLeft.second, isRight.second);

        return {result, ch};
    }

    bool isBalanced(TreeNode* root) {
        return balanaced(root).first;
    }

};
TreeNode* buildTree(const vector<optional<int>>& arr) {
    if (arr.empty() || !arr[0].has_value())
        return nullptr;

    TreeNode* root = new TreeNode(arr[0].value());
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size() && !q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i].has_value()) {
            curr->left = new TreeNode(arr[i].value());
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i].has_value()) {
            curr->right = new TreeNode(arr[i].value());
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    vector<optional<int>> arr = {3,9,20,nullopt,nullopt,15,7};
    TreeNode* root = buildTree(arr);

    Solution s;

    cout << (s.isBalanced(root)) ? "Balanced" : "Not Balanced";
    return 0;
}