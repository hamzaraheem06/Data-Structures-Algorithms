// #include<iostream>
// #include<cmath>

// #include "ArrayList.cpp"

// using namespace std;


// /// @brief Searching algorithm that runs on O (log n) time and constant space complexities.
// /// @param array sorted array
// /// @param size size of the array to be search
// /// @param target value to be search
// /// @return returns the index of the target value if found, else -1
// int binarySearch(int array[], int size, int target) {
//     // initialize the pointers
//     int left = 0;
//     int right = size - 1;
//     int mid;

//     while (left <= right) {
//         // calculate the mid
//         mid = (left + right) / 2;
        
//         // check the mid
//         if (array[mid] == target) return mid;
//         // compare the mid value with the target
//         else if (array[mid] > target) right = mid - 1;
//         else left = mid + 1;
//     }

//     return -1; // return -1, if not found
// }

// string toBinary(int n) {
//     string result = "";
//     while (n > 0) {
//         result = to_string(n & 1) + result;
//         n >>= 1;
//     }

//     return result;
// }

// int toDecimal(string binary) {
//     int result = 0;
//     int n = binary.length();
//     for (int i = 0; i < n; i++) {
//         result += (binary[i] - '0') * pow(2, n - i - 1);
//     }
//     return result;
// }

// bool isPowerOfTwo(int n) {
//     // for n to be power of 2, there should only be one set bit. 

//     int count = 0;

//     while(n > 0) {
//         count += (n & 1);
//         n >>= 1;
//     }

//     return count == 1;
// }

// int bitwiseComplement(int n) {
//     string result = "";

//     while (n > 0) {
//         result = to_string((n & 1)) + result;
//         n >>= 1;
//     }

//     for (char &ch: result) {
//         ch = (ch == '0') ? '1' : '0';
//     }

//     return stoi(result, nullptr, 2); 
// }

// bool isPrime(int n) {
//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0) return false;
//     }

//     return true;
// }

// long long factorial( int n) {
//     // long long fact = 1;
//     // for (int i = n; i > 0;  i--) fact *= i;

//     // return fact;

//     if (n <= 1) return 1;
//     return n * factorial(n - 1);
// }

// int main() {
//     // ArrayList myArr(2);
    
//     // myArr.append(4);
//     // myArr.append(19);
//     // myArr.append(19);
//     // myArr.append(19);

//     // myArr.reverse();

//     // myArr.display();
// }

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start from the end of the two arrays
        int p1 = m - 1; // Pointer for nums1
        int p2 = n - 1; // Pointer for nums2
        int p = m + n - 1; // Pointer for the merged array

        // While there are elements to be processed in nums2
        while (p2 >= 0) {
            // If nums1 is exhausted, or nums2's element is larger, place nums2's element
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
}

int main() {
    vector<int> nums1{1,2,4,0,0,0};
    vector<int> nums2{2,5,6};

    merge1(nums1, 3, nums2, 3);

    for(int num : nums1) cout<<num << " ";

    return 0;
}