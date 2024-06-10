#include <bits/stdc++.h>
#include <vector>
using namespace std; 

class Solution {
public:

    map<int, int> dp;
    int rec(int i, vector<int> &nums, int maxMoney) {
        if(i >= nums.size()) {
            return 0;
        }
        if(dp.count(i)) {
            return dp[i];
        }
        int mx = rec(i + 1, nums, maxMoney);
        mx = max(mx, nums[i] + rec(i + 2, nums, maxMoney));
        return dp[i] = mx;
    }

    int rob(vector<int>& nums) {
        return rec(0, nums, 0);
    }
};

