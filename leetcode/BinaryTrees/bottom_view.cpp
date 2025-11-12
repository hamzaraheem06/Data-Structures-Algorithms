#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
    vector<int> bottomView(TreeNode* root) {
        /*
            highest row entry for each column;
        */

        vector<int> result;
        if (!root) return result;

        // col -> list of (row, val)
        map<int,pair<int,int>> bottom_node;
        // queue of (node, col, row)
        queue<tuple<TreeNode*, int, int>> q;
        q.push(make_tuple(root, 0, 0));

        while (!q.empty()) {
            auto [node, col, row] = q.front(); q.pop();

            // update the top node if the key is not present or, the row is less than the previously added node's row;
            if (!bottom_node.count(col) || row > bottom_node[col].first) {
                bottom_node[col] = {row, node->val};
            }
            if (node->left)  q.push(make_tuple(node->left,  col - 1, row + 1));
            if (node->right) q.push(make_tuple(node->right, col + 1, row + 1));
        }

        for (auto &entry : bottom_node) {
            result.push_back(entry.second.second);
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

    vector<int> result = s.bottomView(root);
    cout << result.size() << endl;
    for (int val : result) {
        cout<< val << " ";
    }

    return 0;
}