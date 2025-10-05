#include<iostream>
#include<vector>

using namespace std;

vector<int> findAllOccurances(vector<int> &nums, int key) {
    int n = nums.size();
    if (!n) return {}; // if empty array return empty list of indices

    vector<int> result;

    for (int i = 0; i < n; i++ ) { // linearly iterate through the list and match against the key
        if (nums[i] == key) result.push_back(i);
    } 

    return result;
}

void display(vector<int> arr) {

    string res = "[ ";
    for (int i = 0; i < arr.size(); i++) {
        res.append(std::to_string(arr[i])); 
        if (i != arr.size() - 1) res.append(", ");
    }
    res.append(" ]");
    cout<<res<<endl; 
}

// Helper function: compare vectors
bool areEqual(vector<int>& a, vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// -------- Test Cases --------

// Test 1: multiple occurrences
void testCase1() {
    vector<int> nums{12, 23, 1, 34, 1, 4, 5, 1, 4, 69};
    vector<int> expected{2, 4, 7};
    vector<int> result = findAllOccurances(nums, 1);

    if (areEqual(result, expected)) {
        cout << "Test 1 (multiple occurrences) passed!" << endl;
    } else {
        cout << "Test 1 (multiple occurrences) failed!" << endl;
    }
}

// Test 2: key absent
void testCase2() {
    vector<int> nums{12, 23, 1, 34, 1, 4, 5, 1, 4, 69};
    vector<int> expected{};
    vector<int> result = findAllOccurances(nums, 420);

    if (areEqual(result, expected)) {
        cout << "Test 2 (key absent) passed!" << endl;
    } else {
        cout << "Test 2 (key absent) failed!" << endl;
    }
}

// Test 3: empty array
void testCase3() {
    vector<int> nums{};
    vector<int> expected{};
    vector<int> result = findAllOccurances(nums, 1);

    if (areEqual(result, expected)) {
        cout << "Test 3 (empty array) passed!" << endl;
    } else {
        cout << "Test 3 (empty array) failed!" << endl;
    }
}

int main() {
    testCase1();
    testCase2();
    testCase3();
    return 0;
}