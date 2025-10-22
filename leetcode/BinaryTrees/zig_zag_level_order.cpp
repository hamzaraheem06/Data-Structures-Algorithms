#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

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
        normal bfs
        use a direction flag, if the flag is true, reverse the level 
        else simple level
    */

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {{}};

        vector<vector<int>> result;
        queue<TreeNode*> q;

        q.push(root);
        bool isReverse = false;

        while(!q.empty()) {
            int size = q.size();
            
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front->val);

                if(front->left) q.push(front->left); 
                if(front->right) q.push(front->right); 
            }
            
            if (isReverse) {
                reverse(level.begin(), level.end());
            }

            result.push_back(level);
            isReverse = !isReverse;
        }

        return result;
    }
};

class SolutionDeque {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result;
        deque<TreeNode*> dq;
        dq.push_back(root);

        bool leftToRight = true;

        while (!dq.empty()) {
            int size = dq.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                if (leftToRight) {
                    // Pop from front
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    level.push_back(node->val);

                    // Push children left to right
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                } 
                else {
                    // Pop from back
                    TreeNode* node = dq.back();
                    dq.pop_back();
                    level.push_back(node->val);

                    // Push children right to left (to front)
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
            }

            result.push_back(level);
            leftToRight = !leftToRight; // alternate direction
        }

        return result;
    }
};
