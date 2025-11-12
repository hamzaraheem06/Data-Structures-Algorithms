#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

class Solution {
  public:

    // pair<sum, height>
    pair<int, int> solve(TreeNode* root) {
        if(!root) return {0, 0};
        // recursively solve left and right
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        // since we are looking for longest path, our checks will be based on the second value, i.e. the height. 
        if (left.second > right.second){
            return {left.first + root->val, 1 + left.second};
        } else if (left.second < right.second) {
            return {right.first + root->val, 1 + right.second};
        } else { // same height, return max sum
            return {max(left.first, right.first) 
                + root->val, 1 + left.second};
        }
    }

    int sumOfLongRootToLeafPath(TreeNode *root) {
        return solve(root).first;
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
    vector<optional<int>> arr = {3, 9, 1, 1, 5, nullopt, nullopt, 3, 7, 4, 5, nullopt, nullopt, nullopt, nullopt, nullopt, nullopt, nullopt, nullopt};
    TreeNode* root = buildTree(arr);
    display_tree(root);

    Solution s;

    int result = s.sumOfLongRootToLeafPath(root);

    cout << "Sum: " << result;

    return 0;
}