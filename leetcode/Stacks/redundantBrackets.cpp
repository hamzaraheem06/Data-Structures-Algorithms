#include<iostream>
#include<stack> 

using namespace std;

// when we find a closing a bracket, the top of the stack should be an operator
// if its not its a redundant bracket


// ((a+b))

// stack: ( ( + 
// found a closing braket
    // --> top is operator so we pop all the operators in between as well as the corresponding operning bracket.
// found a closing bracket
    // --> top is closing bracket, means its redundant
    // consider this as writing ========= (a) which can simply be just written as a

class Solution {
    public: 
        bool isRedundant(string s) {
            stack<char> st;

            for (int i = 0; i < s.length(); i++) {
                char cur = s[i];
                if (cur == '(' || cur == '+' || cur == '-' || cur == '*' || cur == '/') {
                    st.push(cur);
                }
                else if (cur == ')') {
                    char top = st.top();
                    st.pop();
                    if (top == '(') return true;
                    while(st.top() != '(') {
                        st.pop();
                    }

                    st.pop();
                    
                }
            }

            return !st.empty();
        }
};

int main() {
    Solution s;

    cout << s.isRedundant("((a+b+c) + d)");

    return 0;
}