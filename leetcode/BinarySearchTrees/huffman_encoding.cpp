#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<functional>

using namespace std;

struct HuffNode{
    char ch; // character
    int f; // freq

    HuffNode* left;
    HuffNode* right;

    HuffNode() {}

    HuffNode(int freq) : ch(), f(freq), left(nullptr), right(nullptr) {}
    HuffNode(char ch, int freq) : ch(ch), f(freq), left(nullptr), right(nullptr) {}

};

struct Compare {
    bool operator()(const HuffNode* a, const HuffNode* b) const {
        if (a->f != b->f)
            return a->f > b->f; // lower freq has higher priority
        if (a->ch == '\0' && b->ch != '\0')
            return true;  // internal nodes go after leaves
        if (a->ch != '\0' && b->ch == '\0')
            return false;
        return a->ch > b->ch; // lexicographically smaller first
    }
};

class HuffManEncoder {
private:
    HuffNode* root;
    priority_queue<HuffNode*, vector<HuffNode*>, Compare> pq;
    map<char, string> codes;


    map<char, int> scan_text(string text) {
        if(text.empty()) return {};

        int n = text.length();

        map<char, int> freq_map;

        for (int i = 0; i < n; i++) {

            if(freq_map.find(text[i]) == freq_map.end()) {
                freq_map[text[i]] = 0;
            }

            freq_map[text[i]]  += 1;

        }

        return freq_map;
    }

    void load_priority_queue(map<char, int> mapping) {
        
        for (auto& entry: mapping) {
            HuffNode* newNode = new HuffNode(entry.first, entry.second);

            pq.push(newNode);
        }
    }

    void build_tree() {

        while (pq.size() > 1) {
            HuffNode* left = pq.top(); pq.pop();
            HuffNode* right = pq.top(); pq.pop();
            HuffNode* merged = new HuffNode('\0', left->f + right->f);
            merged->left = left;
            merged->right = right;
            pq.push(merged);
        }

        if (!pq.empty()) {
            root = pq.top(); pq.pop();
        } else {
            root = nullptr;
        }
    }

    void build_codes_recursive(HuffNode* root, const string& prefix) {
        if(!root) return; // empty case

        // if leaf, we have the code for the character at leaf
        if(!root->left && !root->right) {
            codes[root->ch] = prefix.empty() ? "0" : prefix;
            return;
        }

        build_codes_recursive(root->left, prefix + '0'); // left = 0
        build_codes_recursive(root->right, prefix + '1'); // right = 1
    }

    void build_codes() {
        codes.clear();
        if(!root) return;

        build_codes_recursive(root, "");
    }

    string encode_text(string text) {
        string encoded = "";
        for (char c : text) {
            auto code = codes.find(c);

            if(code != codes.end()) encoded += code->second;
        }

        return encoded;
    }

    string decode_text(HuffNode* root, string s) {
        string ans = "";
        struct HuffNode* curr = root;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                curr = curr->left;
            else
                curr = curr->right;

            // reached leaf node
            if (curr->left == nullptr && curr->right == nullptr) {
                ans += curr->ch;
                curr = root;
            }
        }
        // cout<<ans<<endl;
        return ans + '\0';
    }


    void display_tree(HuffNode* root, int space = 0, int indent = 5) {

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
        cout << root->ch <<", "<< root->f << "\n";

            // Print left child
        display_tree(root->left, space);
    }

public:

    HuffManEncoder(): root(nullptr) { }

    ~HuffManEncoder() {
        // recursive delete to avoid memory leak
        std::function<void(HuffNode*)> freeTree = [&](HuffNode* node){
            if (!node) return;
            freeTree(node->left);
            freeTree(node->right);
            delete node;
        };
        freeTree(root);
    }

    string encode(string text) {
        map<char, int> mapping = scan_text(text);

        if(mapping.empty()) {
            cout<< "Empty message. " << endl;
            return "";
        }

        load_priority_queue(mapping);

        build_tree();

        build_codes();

        // print codes
        cout << "Codes:\n";
        for (auto &p : codes) cout << p.first << ": " << p.second << "\n";

        string encoding = encode_text(text);

        return encoding;
    }

    string decode(string bits) {
        if(bits.empty()) {
            cout << "Empty stream." << endl;
            return "";
        }

        string decoding = decode_text(root, bits);

        return decoding;
    }

    void display() {
        display_tree(root);
    }

};

int main() {
    string message = "Eerie eyes seen near lake.";

    HuffManEncoder encoder;

    string encoded_message = encoder.encode(message);

    cout << "Encoding: " << encoded_message << endl;
    cout << "Encoding Size: " << encoded_message.length() << endl;

    string decoded_message = encoder.decode(encoded_message);
    cout << "Decoding: " << decoded_message << endl;
    return 0;
}