#include<iostream>
#include<stack>

using namespace std;

class Solution {
    public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;

        stack<char> st;

        for (char p : s) {
            if (p == '(' || p == '[' || p == '{' ) {
                st.push(p);
            }
            else if (p == ')' || p == ']' || p == '}' ) {
                if(st.empty()) return false;

                if(p == ')' && st.top() == '(') {
                    st.pop();
                } else if(p == ']' && st.top() == '[') {
                    st.pop();
                } else if(p == '}' && st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution s1;
    cout << s1.isValid("()[]{}"); // 1
    cout << s1.isValid("(]"); // 0 
    cout << s1.isValid("("); // 0

    return 0;
}