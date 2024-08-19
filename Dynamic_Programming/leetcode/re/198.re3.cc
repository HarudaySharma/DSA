#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // either rob the current house or rob the adjacent one
        // choose the one giving the max profit.

        vector<int> dp(nums.size(), -1);
        auto rec = [&](int idx, auto &&rec) -> int {
            if(idx >= nums.size())
                return 0;
                
            if(dp[idx] != -1)
                return dp[idx];

            // rob the current one
            dp[idx] = rec(idx + 2, rec) + nums[idx];
            // rob the adjacent one
            dp[idx] = max(dp[idx], rec(idx + 1, rec));

            return dp[idx];
        };

        return rec(0, rec);
    }
};

