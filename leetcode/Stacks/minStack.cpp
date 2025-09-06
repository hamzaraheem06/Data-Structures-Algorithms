#include<iostream>
#include<stack>
#include<vector>

using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
    private:
        stack<vector<int>> st;

    public:
        MinStack() {
        }

        void push(int val) {
            if (st.empty()) {
                st.push({val, val});
                return;
            }
            vector<int> curTop = st.top();
            int min = (val < curTop[1])? val : curTop[1];

            st.push({val, min});
            
        }

        void pop() {
            st.pop();
        }

        int top() {
            return st.top()[0];
        }

        int getMin() {
            return st.top()[1];
        }
};


class MinStack2 {
    private:
        stack<int> st;
        stack<int> min_st;


    public:
        MinStack2() {
        }

        void push(int val) {
            if (st.empty()) {
                st.push(val);
                min_st.push(val);
                return;
            }

            st.push(val);
            if (val < min_st.top()) {
                min_st.push(val);
            } else {
                min_st.push(min_st.top());
            }
        }

        void pop() {
            st.pop();
            min_st.pop();
        }

        int top() {
            return st.top();
        }

        int getMin() {
            return min_st.top();
        }

};


int main() {
    
    return 0;
}