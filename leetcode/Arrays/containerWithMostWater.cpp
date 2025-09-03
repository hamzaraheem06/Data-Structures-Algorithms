#include<iostream>
#include<vector>

/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int g_max = INT_MIN;

        int l = 0, r = height.size() - 1;

        while (l < r) {
            int current_area = (r - l) * min(height[l], height[r]);

            g_max = max(g_max, current_area);

            if (height[r] < height[l]) {
                r --;
            } else {
                l ++;
            }
        }

        return g_max;
    }
};

int main() {
    
    return 0;
}