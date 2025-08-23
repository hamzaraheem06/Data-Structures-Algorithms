#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(nums.size());
        int non = 0;
        int zero = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                non ++;
                arr.insert(arr.begin() + non, nums[i]) ;
            } else {
                zero ++;
                arr.insert(arr.begin() + n - zero, 0);
            }
        }

        arr.resize(n);
        nums = arr;
    }
};

int main() {
    
    return 0;
}