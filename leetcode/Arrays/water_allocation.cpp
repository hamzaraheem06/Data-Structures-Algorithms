#include <bits/stdc++.h>
using namespace std;

struct Town {
    int min_i;
    int max_i;   // if no max, you may treat as very large
    int p_i;
};

vector<int> allocateWater(vector<Town> towns, int L) {
    int n = towns.size();
    vector<int> allocated(n);

    // Step 1: Give minimum water
    int sum_min = 0;
    for(int i = 0; i < n; i++) {
        allocated[i] = towns[i].min_i;
        sum_min += towns[i].min_i;
    }

    // If total minimum required water is more than available
    if(L < sum_min) {
        cout << "Infeasible: not enough water to satisfy minimum requirements\n";
        return {};
    }

    int R = L - sum_min; // remaining water

    // Max-heap based on priority
    priority_queue< tuple<int,int,int> > pq;
    // tuple: (priority, index, remaining_capacity)

    for(int i = 0; i < n; i++) {
        int rem = towns[i].max_i - towns[i].min_i;
        if(rem > 0) {
            pq.push( make_tuple(towns[i].p_i, i, rem) );
        }
    }

    // Step 2: Distribute remaining water to highest priority towns
    while(R > 0 && !pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int priority = get<0>(top);
        int idx = get<1>(top);
        int rem = get<2>(top);

        int give = min(R, rem);
        allocated[idx] += give;
        R -= give;
        rem -= give;

        if(rem > 0) {
            pq.push( make_tuple(priority, idx, rem) ); // push town back with less capacity
        }
    }

    return allocated;
}


int main() {
    vector<Town> towns = {
        {5, 10, 10}, // min=5, max=10, priority=10
        {3, 8, 5},   // min=3, max=8, priority=5
        {4, 7, 1}    // min=4, max=7, priority=1
    };

    int L = 20;

    vector<int> result = allocateWater(towns, L);

    if(!result.empty()) {
        cout << "Allocations:\n";
        for(int i = 0; i < result.size(); i++) {
            cout << "Town " << i << ": " << result[i] << "\n";
        }
    }
    return 0;
}
