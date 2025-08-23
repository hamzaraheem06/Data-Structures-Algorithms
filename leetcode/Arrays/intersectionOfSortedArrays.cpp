#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    // Brute force: 
    // match all the pairs of elements and append in the result. 
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // O (n^2) solution
        vector<int> result; 

        for(int i = 0; i < nums1.size(); i++) {
            if (
                (find(result.begin(), result.end(), nums1[i]) == result.end()) && // if the element is already in the result, we dont iterate ahead, since unique elements are required
                (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()) 
             ) {
                result.push_back(nums1[i]);
            }
        }

        return result;
    }

    vector<int> intersectionWithSorting(vector<int>& nums1, vector<int>& nums2) {
        // O (nlogn) solution

        // sort the arrays:
        //      -> then use two pointers, each to start of each array.
        //      -> if the both elements are same, insert the element in the set and move the pointers to next elements
        //      -> if either pointed element is smaller than the other, we increment the respective pointer
        // convert the set to array and return it.

        unordered_set<int> result; // since sets are built to contain unique elements.

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        int n = nums1.size();
        int m = nums2.size(); 
    
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                result.insert(nums1[i]);
                i++;
                j++;
            } 
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }

        return vector<int>(result.begin(), result.end());
    }

    vector<int> intersectionUsingPureSet(vector<int>& nums1, vector<int>& nums2) {
        // Copy unordered_sets to vectors and sort
        vector<int> sorted1(nums1.begin(), nums1.end());
        vector<int> sorted2(nums2.begin(), nums2.end());
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());

        vector<int> result;

        // Perform intersection
        set_intersection(sorted1.begin(), sorted1.end(),
                            sorted2.begin(), sorted2.end(),
                            std::back_inserter(result));
                        
        return result;
    }   
};

int main() {
    Solution s1 = Solution();  
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};
    vector<int> result = s1.intersectionUsingPureSet(nums1, nums2);

    for(int i = 0; i < result.size(); i++) {
        cout<< result[i] << " ";
    }
    return 0;
}