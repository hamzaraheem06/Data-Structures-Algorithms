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
Empty trees are equal

for two trees to be equal, they should have same value at a particular node;

Recursively, we can say: Two trees are equal if roots have same values, and the left nodes have same value and right nodes have same value;

If at any point, one node became null while other is not null, trees have unidentical structure, hence we return false

*/
    bool check_equal(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true; // empty trees are equal

        if (!p || !q) return false; // if at any point one of the root become null, while other is not we return false

        return p->val == q->val && check_equal(p->left, q->left) && check_equal(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check_equal(p, q);
    }
};


// Insert function (pass root by reference!)
void insert(TreeNode*& root, int value) {
    if (!root) {
        root = new TreeNode(value);
        return;
    }

    TreeNode* temp = root;
    while (true) {
        if (value > temp->val) {
            if (temp->right)
                temp = temp->right;
            else {
                temp->right = new TreeNode(value);
                break;
            }
        } else {
            if (temp->left)
                temp = temp->left;
            else {
                temp->left = new TreeNode(value);
                break;
            }
        }
    }
}

// Create BST from vector
TreeNode* createTree(const vector<int>& nums) {
    TreeNode* root = nullptr;
    for (int num : nums) {
        insert(root, num);
    }
    return root;
}


int main() {
    vector<int> num1 = {1, 2, 3};
    vector<int> num2 = {1, 2, 3};

    TreeNode* tree1 = createTree(num1);
    TreeNode* tree2 = createTree(num2);

    Solution s;
    cout << "Is Equal? " << (s.isSameTree(tree1, tree2) ? "Yes" : "No") << endl;

    // Cleanup memory (simple version)
    delete tree1;
    delete tree2;

    return 0;
}