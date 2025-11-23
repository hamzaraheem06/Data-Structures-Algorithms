#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    char val;

    TrieNode(char val) : val(val), isEnd(false) {        
        
    }
};

class Trie {
private:
    TrieNode* root;

    void printNode(TrieNode* node, const string& prefix, bool isLast, ostream& out) const {
        // Print node except the root
        if (node->val != '\0') {
            out << prefix << (isLast ? "`- " : "|- ") << node->val;
            if (node->isEnd) out << "*";
            out << "\n";
        } else {
            out << "(root)\n";
        }

        // Children count
        int totalChildren = node->children.size();
        int counter = 0;

        // Iterate through children in sorted order for nicely ordered output
        vector<pair<char, TrieNode*>> sortedChildren(
            node->children.begin(), node->children.end()
        );

        sort(sortedChildren.begin(), sortedChildren.end());

        for (auto& [c, child] : sortedChildren) {
            bool lastChild = (++counter == totalChildren);

            string newPrefix = prefix;
            if (node->val != '\0') {
                newPrefix += (isLast ? "   " : "|  ");
            }

            printNode(child, newPrefix, lastChild, out);
        }
    }
    
    void printTree(ostream& out = cout) const {
        printNode(root, "", true, out);
    }

    void show_suggestions(vector<string> words) {
        for (int i = 0; i < words.size(); i++) {
            cout << i + 1 <<". " << words[i] << endl;
        }
    }

    void traverse_words(TrieNode* node, vector<string>& words, string prefix = "") {
        // if the node is the end marker, we add the prefix in the words list
        if(node->isEnd) {
            words.push_back(prefix);
        }

        // Iterate through children in sorted order for nicely ordered output
        vector<pair<char, TrieNode*>> sortedChildren(
            node->children.begin(), node->children.end()
        );

        sort(sortedChildren.begin(), sortedChildren.end());

        // for each children, we traverse recursively
        for(auto [ch, child] : sortedChildren) {
            traverse_words(child, words, prefix + ch);
        }

    }

    bool remove_word(TrieNode* node, const string &word, int index) {
        if (!node) return false; // safety

        // Case 1: reached end of word
        if (index == word.length()) {
            if (!node->isEnd) 
                return false; // word not found

            node->isEnd = false;

            // if no children, this node should be deleted
            return node->children.empty();
        }

        char ch = word[index];

        // character not found — nothing to remove
        if (node->children.find(ch) == node->children.end())
            return false;

        TrieNode* next = node->children[ch];

        bool shouldDeleteChild = remove_word(next, word, index + 1);

        // free child node if required
        if (shouldDeleteChild) {
            delete next;
            node->children.erase(ch);
        }

        // return TRUE if this node can also be removed
        return (!node->isEnd && node->children.empty());
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(const string& word) {
        TrieNode* cur = root;
        for (char ch : word) {
            if (cur->children.find(ch) == cur->children.end())
                cur->children[ch] = new TrieNode(ch);
            cur = cur->children[ch];
        }
        cur->isEnd = true;
    }


    vector<string> get_suggestions(string prefix) {
        TrieNode* curr = root; // iterating pointer

        for (char ch : prefix) { // reach to the end of the prefix
            if (curr->children.find(ch) == curr->children.end()) {
                return {};  // prefix not found → return empty suggestions
            }
            curr = curr->children[ch];
        }

        vector<string> words;

        traverse_words(curr, words, ""); // traverse the trie from the node

        return words;
    }   

    void type(string prefix) {
        cout << "User: " << prefix << endl;

        vector<string> words = get_suggestions(prefix);

        cout<<"Suggestions: \n";
        show_suggestions(words);

        cout << endl << endl;
    }



    void remove(string word) {
        remove_word(root, word, 0);
    }

    friend ostream& operator<<(ostream& out, const Trie& t) {
        t.printTree(out);
        return out;
    }
};

int main() {
    Trie t;
    t.insert("apple");
    t.insert("app");
    t.insert("application");
    t.insert("bat");
    t.insert("bath");

    cout << t;

    t.type("ba");
    t.type("appl");
    t.type("aq");

    t.remove("application");

    t.remove("app");

    t.remove("batman");


    cout << t;
}
