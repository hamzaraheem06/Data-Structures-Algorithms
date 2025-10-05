#include<iostream>
#include<queue>

using namespace std;

queue<int> reverse(queue<int> q) {

    if (q.empty()) return q;

    int front = q.front();

    q.pop();

    queue<int> rest = reverse(q);
    rest.push(front);

    return rest;
}

int main() {
    queue<int> q({1, 2, 3, 4});

    q = reverse(q);

    while (!q.empty()) {
        cout << q.front() << "   ";
        q.pop();
    }

    return 0;
}