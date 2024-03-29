#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int rec(int lvl, vector<int> &nums,  int n) {
        if(lvl < 0)
            return 0;

        if(dp[lvl] != -1)
            return dp[lvl];

        // transition
        int ans = 1;
        for(int prev_taken = 0; prev_taken < lvl; prev_taken++) {
            if(nums[prev_taken] < nums[lvl])
                ans = max(ans, 1 + rec(prev_taken, nums, n));
        }
        return dp[lvl] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        int bestLen = 0;
        for(int i = 0; i < n; i++) {
            bestLen = max(bestLen, rec(i, nums, n));
        }
        return bestLen;
    }
};
