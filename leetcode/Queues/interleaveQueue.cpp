#include<iostream>
#include<queue>

using namespace std;

class Solution {
    public:
        queue<int> interleave(queue<int> q) {

            // NOTE: q will always have an even size
            int n = q.size();

            queue<int> first;
            int half = n / 2;

            for (int i = 0; i < half; i++) { // take the first half elements out of the queue
                first.push(q.front());
                q.pop();
            }

            for (int i = 0; i < n; i++) {
                if(i % 2) { // when odd index, take an element from q 
                    q.push(q.front());
                    q.pop();
                } else { // when even index, take an element from the seperated half
                    q.push(first.front());
                    first.pop();
                }
            }

            return q;
        }
};

int main() {
    queue<int> q({1, 2, 3, 4, 5, 6});

    Solution s;
    queue<int> result = s.interleave(q);

    while(!result.empty()){ cout << result.front(); result.pop();}
    return 0;
}