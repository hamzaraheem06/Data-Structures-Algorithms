#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> result;
        queue<int> negatives;
        int n = arr.size();

        for (int i = 0; i < k; i++) {
            if (arr[i] < 0)
                negatives.push(i);
        }

        for (int i = k; i <= n; i++) {
            // Add result for current window
            if (!negatives.empty())
                result.push_back(arr[negatives.front()]);
            else
                result.push_back(0);

            // Remove elements out of this window
            while (!negatives.empty() && negatives.front() <= i - k)
                negatives.pop();

            // Add next element if in bounds
            if (i < n && arr[i] < 0)
                negatives.push(i);
        }

        return result;
    }
};

int main() {
    vector<int> q({-8, 2, 3, -6, 10});

    Solution s;
    vector<int> result = s.firstNegInt(q, 2);

    for (int num : result) cout << num << "  "; 

    return 0;
}   