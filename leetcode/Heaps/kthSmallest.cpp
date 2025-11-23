#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    /*
    Algorithm (arr, k):
        1. Put first k elements in the heap
        2.  Travel remaining elements in arr
            if num is greater than root,
                we continue to traverse
            else 
                replace root with the num

        3. return the root of the heap after the traversal has been done;

        // and remember, insertion in heap means heapifying;
    */

    int kthSmallest(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n || n == 0) return INT_MIN;

        vector<int> heap;
        // inserting k elements in heap
        for (int i = 0; i < k; i++) {
            heap.push_back(nums[i]);
        }

        // heapifying the current window
        for (int i = k - 1; i >= 0; i--) {
            heapify(heap, i, k - 1);
        }

        // if num is greater we skip, else we replace and heapify again to ensure the correctness;
        for (int i = k; i < n; i++) {
            if (heap[0] < nums[i]) continue;

            heap[0] = nums[i];
            heapify(heap, 0, k - 1);
        }

        return heap[0];
    }

    void heapify(vector<int>& heap, int i, int n) {
        int lci = i * 2 + 1;
        int rci = i * 2 + 2;
        int best = i;

        if (lci <= n && heap[lci] > heap[best]) best = lci;

        if (rci <= n && heap[rci] > heap[best]) best = rci;

        if (best != i) {
            swap(heap[i], heap[best]);
            heapify(heap, best, n);
        }

    }
};

int main() {
    vector<int> nums{8, 7, 19, 14, 20, 16};

    Solution s;
    cout << "Result: " << s.kthSmallest(nums, 3);
    return 0;
}