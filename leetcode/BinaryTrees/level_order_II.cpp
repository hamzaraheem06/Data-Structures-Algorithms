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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> result;

        while(!q.empty()) {
            int size = q.size();
            
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                level.push_back(front->val);

                if (front->left) q.push(front->left); 
                if (front->right) q.push(front->right); 
            }

            result.push_back(level);
        }   

        reverse(result.begin(), result.end());

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

    vector<vector<int>> result = s.levelOrderBottom(root);

    for (auto &level : result) {
        for (int n : level) {
            cout << n << "  ";
        }
        cout << endl;
    }

    return 0;
}