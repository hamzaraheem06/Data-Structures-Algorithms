#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T val;
    Node* left;
    Node* right;

    Node(T val) : val(val), left(nullptr), right(nullptr) {}
};

// Display tree sideways
void display_tree(Node<char>* root, int space = 0, int indent = 5) {
    if (!root) return;
    space += indent;
    display_tree(root->right, space);
    cout << endl;
    for (int i = indent; i < space; i++)
        cout << " ";
    cout << root->val << "\n";
    display_tree(root->left, space);
}

// Postorder traversal
void post_fix(Node<char>* root) {
    if (!root) return;
    post_fix(root->left);
    post_fix(root->right);
    cout << root->val << " ";
}

int main() {
    // Correctly allocate root
    Node<char>* root = new Node('-');

    root->left = new Node('+');
    root->right = new Node('3');
    root->left->left = new Node('3');
    root->left->right = new Node('*');
    root->left->right->left = new Node('5');
    root->left->right->right = new Node('2');

    cout << "Tree Structure:\n";
    display_tree(root);

    cout << "\nPostfix Expression: ";
    post_fix(root);

    return 0;
}
