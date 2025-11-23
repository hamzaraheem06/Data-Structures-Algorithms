#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int first(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;        // keep searching left
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int last(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;         // keep searching right
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums, target);
        if (f == -1) return {-1, -1};
        int l = last(nums, target);
        return {f, l};
    }

};

int main() {
    vector<int> nums{5,7,7,8,8,10};
    Solution s;

    vector<int> result = s.searchRange(nums, 8);

    cout << result[0] << ", " << result[1];

    return 0;
}