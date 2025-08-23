#include<vector>
#include<iostream>

using namespace std;

//We will be using DNF Algorithm to solve this problem, as it is designed
        // to sort array with three distinct elements. 

        // left = 0, mid = 0, right = len(nums) - 1
        // we will be moving the mid pointer across the array:
        // if we encounter a 0, we swap the mid with left and increment both
        // if we encounter a 1, we will just increment mid
        // if we encounter a 2, we will swap mid with right and increment mid by 1 and 
        // decrement right by 1

        // why? This is because we are using left to manage 0s, mid to manage 1s and right for 2s.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high --;
            }
        }
    }
};

