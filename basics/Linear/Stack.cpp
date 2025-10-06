#include<iostream>
#include<vector>

using namespace std;

class Stack {
    private:
        int n; // keeps the track of number of elements, as well as the top of the stack
        vector<int> st;

    public:
        Stack() {
            n = 0;
        }

        Stack(const Stack& stack) {
            st = vector<int>(stack.st);
            n = stack.n;
        }

        void push(int val) {
            st.push_back(val);
            n ++;
        }

        int top() {
            if (empty()) throw runtime_error("Empty stack. \n");
            return st[n - 1];
        }

        bool empty() {return n == 0;}

        void pop() {
            if (empty()) throw runtime_error("Empty stack. \n");

            st.pop_back();
            n --;
        }

        int size() {
            return n;
        }
};

// implement using linked list

int main() {
    Stack myst;

    myst.push(1);
    myst.push(2);
    
    Stack iter(myst); // copy constructor

    try {
        while(!iter.empty()) {
            cout << iter.top() << endl;
            iter.pop();
        }
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what();
    }

    return 0;
}