#include<iostream>
#include<vector>

using namespace std;

// There is a pattern :-
    // if the array is rotated and sorted, there can at most 1 consecutive comparision that result in greater than. 

    // Example 1:
    // [3,4,5,1,2] 
    // 3 > 4 false
    // 4 > 5 false
    // 5 > 1 true
    // 1 > 2 false
    // 2 > 3 false
    // = only one true
    // sorted array is [1, 2, 3, 4, 5]
    // it is rotated by 3 positiona.

    // Example 2: 
    // [2,1,3,4]
    // 2 > 1 true
    // 1 > 3 false
    // 3 > 4 false
    // 4 > 2 true
    // = two trues 
    // hence, not rotated and sorted

    // Example 3: 
    // [1,2,3]
    // 1 > 2 false
    // 2 > 3 false
    // 3 > 1 true
    // = onle only true
    // sorted array is [1, 2, 3]
    // rotated by 0 positions.

    // Example 4:
    // [1, 1, 1]
    // 1 > 1 false
    // 1 > 1 false
    // 1 > 1 false
    // 1 > 1 false
    // = 0 trues
    // sorted array is [1, 1, 1]
    // rotated by 0 positions
    

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i ++) {
            count += (int) nums[i] > nums[ (i + 1) % n];
        }

        return (count > 1) ? false : true;
    }
};

int main() {
    vector<int> nums1{3,4,5,1,2};
    vector<int> nums2{2,1,3,4};
    vector<int> nums3{1, 1, 1, 1};

    Solution s = Solution();

    cout<< s.check(nums1)<<endl;
    cout<< s.check(nums2)<<endl;
    cout<< s.check(nums3)<<endl;
    return 0;
}