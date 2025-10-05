#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int g_max = INT_MIN;

        int c_max = 1;

        for (int i = 0; i < n; i++) {
            c_max *= nums[i];

            if (g_max < c_max) {
                g_max = c_max;
            } else {
                c_max = nums[i];
            }

        }

        g_max = max(g_max, c_max);

        return g_max;
    }
};

int main() {
    vector<int> arr({0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0});
    Solution s;
    cout << s.maxProduct(arr);

    return 0;
}   