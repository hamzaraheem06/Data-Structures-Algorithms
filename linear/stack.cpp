#include<iostream>
#include<stack>

using namespace std;
int main() {
    // note: Declaring a stack: stack< DataType > iden;

    stack<int> st;

    // note: Inserting an element: new elements can only be inserted at the top of the stack by using push()

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // note: Accessing an element: Only the top element of the stack can be accessed using top()

    int top = st.top();

    cout << "The top of the stack is: " << top <<endl; 
    // Output: The top of the stack is: 40

    // note: Deleting an element: only the top element of the stack can be deleted by using pop()

    st.pop();

    top = st.top(); // New Top

    cout << "The top of the stack after popping once is : " << top <<endl; 
    // Output: The top of the stack after popping once is : 30

    // note: empty() checks if the stack is empty or not.

    cout << st.empty() << endl;
    // Output: 0 ( false )

    // note: size() returns the number of elements that are currently in the stack

    cout << st.size() << endl;
    // Output: 3

    // note: Traversing the stack:
    // Since no other element than the top can be accessed, we cannot directly traverse a stack. 
    // However, we can create a copy of the stack and then access top from it and then remove the top. 
    // In this way, we can effectively traverse a stack.

    stack<int> temp(st); // copy constructor

    while(!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }

    cout << endl;

    // Output: 
    // 30
    // 20
    // 10

    // note: swap() swaps the content of two stacks.

    stack<int> funny;

    funny.push(69);
    funny.push(88);
    funny.push(420);
    
    st.swap(funny); // swapped the contents

    // Printing the new content
    stack<int> iter(st); // copy constructor

    while(!iter.empty()) {
        cout << iter.top() << endl;
        iter.pop();
    }

    // Output: 
    // 420
    // 88
    // 69

    return 0;
}