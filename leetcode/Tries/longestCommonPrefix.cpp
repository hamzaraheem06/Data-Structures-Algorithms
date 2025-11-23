#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

// ************* Solution Without Using a Trie ( Very computation heavy code) : beats only 5% of the users on leetcode

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {

//         int max_length = -1;

//         for(string s : strs) {
//             int n = s.length();
//             max_length = max(max_length, n);
//         }

//         string ans = "";

//         for (int i = 0; i < max_length; i++) {
//             if(strs[0].length() < i) return ans;

//             char ch = strs[0][i];
//             for(string word : strs) { 
//                 if (word[i] != ch) 
//                     return ans;
//             }

//             ans += ch;

//         }

//         return ans;
//     }
// };

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    char val;

    TrieNode(char val) : val(val), isEnd(false) {        
        
    }
};

class Solution {
public:

    string solve(TrieNode* root, string prefix) {
        if(!root) return prefix;

        if (root->val != '\0') {
            prefix += root->val;
        }

        if (root->children.size() > 1 || root->isEnd) return prefix;

        vector<pair<char, TrieNode*>> sortedChildren(
            root->children.begin(), root->children.end()
        );

        return solve(sortedChildren[0].second, prefix);
    }

     void insert(TrieNode* root,  string& word) {
        TrieNode* cur = root;
        for (char ch : word) {
            if (cur->children.find(ch) == cur->children.end())
                cur->children[ch] = new TrieNode(ch);
            cur = cur->children[ch];
        }
        cur->isEnd = true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('\0'); 

        for (string word : strs) {
            insert(root, word);
        }

        return solve(root, "");
    }
};

int main() {
    

    return 0;
}