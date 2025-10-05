#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> flatten(vector<vector<int>> &list) {
    vector<int> result;
    for (vector<int> elem: list) { // n^2
        for (int num : elem) {
            result.push_back(num);
        }
    }

    sort(result.begin(), result.end()); // n log(n)

    return result;
}

int main() {
    vector<vector<int>> input = {{1, 1}, {2}, {3, 4, 5}, {0}, {2}};

    vector<int> result = flatten(input);

    for (int num: result) {
        cout << num << "  ";
    }

    return 0;
}