#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result;
        unordered_map<int, int> map;

        int n = arr.size();

        for (int i = 0; i < k; i++) {
            map[arr[i]] += 1;
        }
        
        result.push_back(map.size());

        for (int i = k ; i < n; i++) {
            int cur = arr[i - k];
            map[cur] -= 1;

            if (map[cur] == 0) {
                map.erase(cur);
            }

            map[arr[i]] += 1;

            result.push_back(map.size());
        }

        return result;
    }
};
