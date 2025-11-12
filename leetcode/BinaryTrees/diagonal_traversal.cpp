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
    vector<vector<int>> diagonalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        // col -> list of (row, val)
        map<int, vector<pair<int,int>>> col_map;
        // queue of (node, col, row)
        queue<tuple<TreeNode*, int, int>> q;
        q.push(make_tuple(root, 0, 0));

        int min_col = INT_MAX;
        int max_col = INT_MIN;
        int min_row = INT_MAX;
        int max_row = INT_MIN;

        while (!q.empty()) {
            auto [node, col, row] = q.front(); q.pop();

            // Upper and lower bounds for diagnonals;

            min_col = min(min_col, col);
            max_col = max(max_col, col);
            min_row = min(min_row, row);
            max_row = max(max_row, row);

            col_map[col].push_back({row, node->val});
            if (node->left)  q.push(make_tuple(node->left,  col - 1, row + 1));
            if (node->right) q.push(make_tuple(node->right, col + 1, row + 1));
        }

        for (int i = 1; i < max_col; i++) {
            for(int j = i ; j >= min_col; j++) {
                for (int k = i; )
            }
        }

        /*
        for (auto &entry : cols) - Iterates through the map cols where:

        Each entry has:
        entry.first: column number
        entry.second: vector of pairs (row, value) ->>> [vec]
        sort(vec.begin(), vec.end()) - Sorts nodes in each column by row, it tie values

        After sorting, creates final column vector from the vec vector
        */

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

    vector<vector<int>> result = s.diagonalTraversal(root);

    for (vector<int>& row : result) {
        for(int val: row) cout << val << " ";
    }

    return 0;
}