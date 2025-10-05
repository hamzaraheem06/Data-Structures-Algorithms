#include<iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> reverse(queue<int> q) {
    if (q.empty() || q.size() == 1) return q;

    stack<int> st;

    while(!q.empty()) { 
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    return q;
}

int main() {
    // note: Declaring a queue: queue< DataType > iden;

    queue<int> q;

    // note: Inserting an element: new elements can only be inserted at the end of the queue by using push()

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    

    // note: Accessing an element: Only the front element of the queue can be accessed using front()

    // int front = q.front();

    // cout << "The front of the queue is: " << front <<endl; 
    // Output: The front of the queue is: 10

    // note: Deleting an element: only the front element of the queue can be deleted by using pop()

    // q.pop();

    // front = q.front(); // New front

    // cout << "The front of the queue after popping once is : " << front <<endl; 
    // Output: The top of the queue after popping once is : 20

    // note: empty() checks if the queue is empty or not.

    // cout << q.empty() << endl;
    // Output: 0 ( false )

    // note: size() returns the number of elements that are currently in the queue

    // cout << q.size() << endl;
    // Output: 3

    // note: Traversing the queue:
    // Since no other element than the front can be accessed, we cannot directly traverse a queue. 
    // However, we can create a copy of the queue and then access front from it and then remove the front. 
    // In this way, we can effectively traverse a queue.

    // queue<int> temp(q); // copy constructor

    // while(!temp.empty()) {
    //     cout << temp.front() << endl;
    //     temp.pop();
    // }

    cout << endl;

    // Output: 
    // 20
    // 30
    // 40

    // note: .back() returns the last element that was inserted in the queue

    int back = q.back();

    // cout << "The back of the queue is: " << back << endl;
    // Output: The back of the queue is: 40

    queue<int> result = reverse(q);

    queue<int> temp(result); // copy constructor

    while(!temp.empty()) {
        cout << temp.front() << endl;
        temp.pop();
    }

    // 40
    // 30
    // 20
    // 10

    return 0;
}