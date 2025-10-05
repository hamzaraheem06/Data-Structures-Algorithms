#include<iostream>
#include<queue>

// intuition: reverse the k elements first, then move the remaining to get the answers

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = q.size();
        if (n < k) return q;

        q = reverse(q, k); // recusively reverse k elements 
        // [1, 2, 3, 4, 5] ==> [4, 5, 3, 2, 1]

        // now we move the remaining elements to their original place
        int rem = n - k;

        for (int i = 0; i < rem; i++) {
            int front = q.front();
            q.pop();
            q.push(front);
        }

        // [4, 5, 3, 2, 1] ==> [3, 2, 1, 4, 5]

        return q;
        
    }

    queue<int> reverse(queue<int> q, int k) {
        if (q.empty() || k <= 0) return q;

        int front = q.front();
        q.pop();

        queue<int> rest = reverse(q, k - 1);

        rest.push(front);
        return rest;
    }   

};

using namespace std;
int main() {
    
    return 0;
}