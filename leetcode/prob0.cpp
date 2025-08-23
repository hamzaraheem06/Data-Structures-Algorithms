#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// int singleNumber(vector<int> &vec) {
//     unordered_map<int, int> map;

//     for (int i = 0; i < vec.size(); i++) {
//         map[vec[i]]++;
//     }

//     for (auto i = map.begin(); i != map.end(); i++) 
//         if (i->second == 1) return i->first;
    
//     return -1;
// }   

int singleNumber(vector<int> &vec) {
    int result = 0;

    for (int i = 0; i < vec.size(); i ++) {
        result = result ^ vec[i];
    }

    return result;
}

int main() {
    vector<int> vec{1, 2, 3, 1, 3, 4};
    // cout<<singleNumber(vec);

    for(int num: vec) {
        cout<<num;
    }
    return 0;
}