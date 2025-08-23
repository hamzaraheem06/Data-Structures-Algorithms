#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void mergeShit(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Naive solution
        // put all the elements of nums2 inside the nums1 and then use the sort function
        // Time complexity: O ( nlogn )
        // Space complexity: O (1)

        for(int i = 0; i < n; i++) {
            nums1[m+i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = 0, j = 0;
        vector<int> arr;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            arr.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            arr.push_back(nums2[j]);
            j++;
        }
        nums1 = arr;
    }

    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start from the end of the two arrays
        int p1 = m - 1; // Pointer for nums1
        int p2 = n - 1; // Pointer for nums2
        int p = m + n - 1; // Pointer for the merged array

        // While there are elements to be processed in nums2
        while (p2 >= 0) {
            // If nums1 is exhausted, or nums2's element is larger, place nums2's element
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
    }
};

int main() {
    vector<int> nums1{1,2,4,0,0,0};
    vector<int> nums2{2,5,6};

    Solution s1 = Solution();

    s1.merge(nums1, 3, nums2, 3);

    for(int num : nums1) cout<<num << " ";

    return 0;
}