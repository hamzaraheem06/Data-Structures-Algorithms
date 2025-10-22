#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

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


// ILL come back to it after some more knowledge, its difficult man

class Solution {
public:

    void atKDistance(TreeNode* target, int k, vector<int>& result) {
        if (!target) return;

        if (k == 0) result.push_back(target->val);

        atKDistance(target->left, k - 1, result);
        atKDistance(target->right, k - 1, result); 
    }

    int findDepth(TreeNode* root, TreeNode* target, int depth = 0) {
        if (!root) return -1; // not found

        if (root == target)
            return depth;

        // search in left subtree
        int leftDepth = findDepth(root->left, target, depth + 1);
        if (leftDepth != -1)
            return leftDepth;  // found in left

        // search in right subtree
        return findDepth(root->right, target, depth + 1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        atKDistance(target, k, result); // from target

        int rem = abs(k - findDepth(root, target));

        if (rem == 0) result.push_back(root->val);
        else if ( rem > 0) {
            atKDistance(root, rem, result);
            int target_value = target->val;

            for (auto it = result.begin(); it != result.end(); ) {
            if (*it == target_value)
                it = result.erase(it); // erase returns next valid iterator
            else
                ++it;
    }
        }

        return result;

    }
};


// ---------- Build Binary Tree from Vector (Level Order) ----------
TreeNode* buildTree(const vector<string>& arr) {
    if (arr.empty() || arr[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // left child
        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        // right child
        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}

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
    // vector<int> result = s.nodesAtK(root, 2);

    // for (int num : result) {
    //     cout << num << "  ";
    // }

    delete root;
    return 0;
}