#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            result[(i + k ) % n] = nums[i];
        }

        nums = result;
    }

    void rotateUsingReverse(vector<int>& nums, int k) {
        int n = nums.size(); // 7
        k = k % n; // 3 % 7 = 3

        reverse(nums, 0, n - 1); // 7 6 5 4 3 2 1
        reverse(nums, 0, k - 1); // 5 6 7 4 3 2 1
        reverse(nums, k, n - 1); // 5 6 7 1 2 3 4
    }

    // helper reverse function

    void reverse(vector<int>& nums, int s, int e) {
        while(s < e) {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }

};

int main() {
    vector<int> nums{1,2, 3, 4, 5, 6, 7};

    Solution s1 = Solution();
    s1.rotateUsingReverse(nums, 3);

    for(int num : nums) cout<< " "<< num;

    return 0;
}