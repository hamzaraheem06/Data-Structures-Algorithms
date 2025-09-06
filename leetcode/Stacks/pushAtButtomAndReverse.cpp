#include<iostream>
#include<stack>

using namespace std;

// Damn Hamza shiiiii

// recursively iterate the stack, store the current val before passing the rest to next call, and then push 

stack<int> insertBottom(stack<int> st, int x) {
    if (st.empty()) {
        st.push(x);
        return st;
    }

    int cur = st.top();
    st.pop();
    stack<int> rest = insertBottom(st, x);

    rest.push(cur); 

    return rest;
}

// recursively add at bottom

stack<int> reverse(stack<int> st) {
    if (st.empty()) return st;

    int val = st.top();
    st.pop();

    stack<int> rest = reverse(st);

    rest = insertBottom(rest, val);

    return rest;
}


int main() {
    stack<int> st({7, 1, 4, 5});
    
    stack<int> result = reverse(st);

    stack<int> temp(result); // copy constructor

    while(!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }

    cout << endl;

    return 0;
}