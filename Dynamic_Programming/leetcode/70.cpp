#include "bits/stdc++.h"
#include <vector>
using namespace std;

class Solution {
public:
    int helper(int curr, int target, vector<int>&store) {
        if(target == curr)
            return 1;
        if(store[curr] != 0)
            return store[curr];
        if(curr + 1 <= target)
            store[curr] += helper(curr + 1, target, store);
        if(curr + 2 <= target)
            store[curr] += helper(curr + 2, target, store);
        return store[curr];
    }

    int climbStairs(int n) {
        vector<int>store(n, 0);
        return helper(0, n, store); 
    }
};
