#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printVector(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout<< vec[i]  << " ";
    }

    cout<< endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    nums.push_back(5);

    nums.insert(nums.begin() + 3, 5); // insert 5 at index 3.

    printVector(nums);

    nums.erase(nums.begin() + 3); // deletes the element at 3rd index

    printVector(nums);

    // cout<<nums.empty();

    reverse(nums.begin(), nums.end());

    printVector(nums);

    sort(nums.begin(), nums.end(), greater<int>());
    
    printVector(nums);
    return 0;
}