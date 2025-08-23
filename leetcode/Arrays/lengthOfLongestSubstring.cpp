#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

// ""bbtablud""

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        int g_max = INT_MIN;
        int l = 0;

        unordered_set<char> seen;

        for (int r = 0; r < s.length(); r++) {
            char newChar = s[r];

            while(seen.count(newChar) != 0) {
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);

            g_max = max(g_max, r - l + 1);
        }

        return g_max;
    }
};

int main() {
    Solution s1;
    cout<<s1.lengthOfLongestSubstring("bbtablud");

    return 0;
}