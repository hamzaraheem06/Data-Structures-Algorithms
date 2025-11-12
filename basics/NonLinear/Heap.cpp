#include<iostream>
#include<vector>

using namespace std;

/*
    Heaps are a complete binary trees, this makes using arrays a good option over using a Linked List (Nodes) based implementation.

    Node at i'th index will be have children with indexes:
        Left child = (i * 2 + 1)th index
        Right Child = (i * 2 + 2)th index

    Node at i'th index will have parent at [(i - 1) / 2]th index.

*/


class Heap {
    private:
        vector<int> tree;
        bool is_max;
    public:

    Heap( bool is_max = true) : is_max(is_max) {
    }

    /*
    push logic:

    1. Add the node at the next available spot i.e. Complete tree property
    2. get the parent of the current node
    3. check the heap property ( max or min heap property)
    4. If !head_property: 
        swap the parent with current element
    5. the checks will continue till we compare with the root to ensure that all the nodes are correctly placed.

    */
    void push(int val) {
        // first add the value at available spot
        tree.push_back(val);

        int it = tree.size() - 1; // current element index

        while (it > 0) {
            int parent = (it - 1) / 2; // get the parent 
            
            // compare the values
            if ((is_max  && tree[parent] < tree[it]) ||
                (!is_max && tree[parent] > tree[it])) 
            { 
                swap(tree[parent], tree[it]);
                it = parent; // update the value
            } else {
                break;
            }
        }
    }

    /*
    
    pop logic:

    we will always return the root of the heap

    1. swap the root value with the last value of the tree; ( insuring complete property ), and then pop_back the vector
    2. get the childrens of the root; 
    3. check if the root is greater than both; 
    4. if yes
            return
       else 
            bubble dowzn ( swap the value with greatest children)
    */

    int pop() {
        if (tree.empty()) {
            cout << "Empty Heap.\n";
            return -1;
        }

        int n = tree.size() - 1; 
        int value = tree[0];

        swap(tree[0], tree[n]);
        tree.pop_back();

        int it = 0;

        while (true) {
            int left  = it * 2 + 1;
            int right = it * 2 + 2;
            int n = tree.size();

            if (left >= n) break; // no children

            // pick child based on heap type
            int best = left;
            if (right < n) {
                if (is_max) {
                    if (tree[right] > tree[left])
                        best = right;
                } else {
                    if (tree[right] < tree[left])
                        best = right;
                }
            }

            // check heap property
            if (is_max && tree[it] >= tree[best]) break;
            if (!is_max && tree[it] <= tree[best]) break;

            swap(tree[it], tree[best]);
            it = best;
        }

        return value;
    }

    static void heapify(vector<int>& nums) {
        int n = nums.size() - 1;
        
        for (int i = n; i >= 0; i--) {
            heap_shi(nums, i, n);
        }
    }

    static void heap_shi(vector<int>& nums, int i, int n) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int best = i;

        if (left <= n && nums[left] < nums[best])
            best = left;

        if (right <= n && nums[right] < nums[best])
            best = right;

        if (best != i) {
            swap(nums[i], nums[best]);
            heap_shi(nums, best, n);
        }
    }

    void display() {
        for (int i = 0; i < tree.size(); i++) cout << tree[i] << " ";

        cout << "\n";
    }
};

int main() {
    Heap hp(false);


    hp.push(3);
    hp.display();
    hp.push(10);
    hp.display();
    hp.push(1);
    hp.display();
    hp.push(2);
    hp.display();
    cout << "Pop Value: " << hp.pop() << endl;
    hp.display();
    cout << "Pop Value: " << hp.pop() << endl;
    hp.display();
    cout << "Pop Value: " << hp.pop() << endl;
    hp.display();
    cout << "Pop Value: " << hp.pop() << endl;

    vector<int> nums{3, 1, 6, 10, 12, 2, 8};
    Heap::heapify(nums);

    for (int i = 0; i < nums.size(); i ++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}