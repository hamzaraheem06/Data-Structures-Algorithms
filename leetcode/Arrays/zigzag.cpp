#include<iostream>
#include<vector>
#include<cstring> // For memset

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows == 1 || numRows >= n) return s;

        char grid[numRows][n];
        memset(grid, 0, sizeof(grid)); // Initialize all cells to '\0'

        bool down = true;
        int row = 0, col = 0;

        for (int i = 0; i < n; i++) {
            grid[row][col] = s[i];
            if (row == 0) down = true;
            if (row == numRows - 1) down = false;

            if (down) {
                row++;
            } else {
                row--;
                col++;
            }
        }

        string result;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '\0') {
                    result += grid[i][j];
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    cout << s.convert("PAYPALISHIRING", 4);
    return 0;
}