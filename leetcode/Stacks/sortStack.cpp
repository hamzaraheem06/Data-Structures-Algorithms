#include<iostream>
#include<stack>

using namespace std;

// recursively iterate over the stack by popping, and add each element at the correct place in the sorted array. 

// We are assuming, recurssing returns us a sorted array we dont know how but it does. now the element that has currently been popped needs to be placed at correct place in the sorted array.

class Solution {
    public:
        stack<int> sort(stack<int> st) {
            if (st.empty()) return st;

            int val = st.top();
            st.pop();

            stack<int> rest = sort(st);

            insert(rest, val);

            return rest;
        }

        void insert(stack<int> &st, int val) {
            if (st.empty()) {
                st.push(val);
                return;
            }  
            int top = st.top();

            if ( top  <= val) {
                st.push(val);
            } else {
                st.pop();
                insert(st, val);
                st.push(top);
            }

        }
};

int main() {
    Solution s;
    stack<int> st({7, 1, 4, 5, 12, 1, 12, -2});
    
    stack<int> result = s.sort(st);

    stack<int> temp(result); // copy constructor

    while(!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }

    cout << endl;
    return 0;
}