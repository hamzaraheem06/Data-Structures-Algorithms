#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            
            // Process each level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); 
                q.pop();
                
                // If it's the last node in level, add to result
                if (i == size-1) {
                    result.push_back(node->val);
                }
                
                // Add children to queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
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
    vector<optional<int>> arr = {3, 7, 8, 5, 9, nullopt, 11,nullopt, nullopt,  nullopt, nullopt, 5, 12, 17};
    TreeNode* root = buildTree(arr);
    display_tree(root);

    Solution s;

    vector<int> result = s.rightSideView(root);
    cout << result.size() << endl;
    for (int val : result) {
        cout<< val << " ";
    }

    return 0;
}