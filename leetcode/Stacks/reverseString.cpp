#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
    // Use a stack, first push all the elements in the stack, when you will pop you will get the reversed output

public:
    void reverseString(vector<char>& s) {
        if (s.size() == 1) return;

        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
        }

        for (int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }

        for(char ch : s) cout << ch;
        cout << endl;
    }
};

int main() {
    Solution s;
    vector<char> s1 = {'h','e','l','l','o'};
    s.reverseString(s1);
    return 0;
}