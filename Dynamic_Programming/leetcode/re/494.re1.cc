#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int j = 2 * sum + 1;
        vector<vector<int>> dp(nums.size(), vector<int>(j, -1));// [-sum, +sum];

        auto rec = [&](int i, int target, auto &&rec) -> int {
            int shifted_target = target + sum; // as target range from [-sum, +sum]

            // base case
            if(i >= nums.size())
                return target == 0 ? 1 : 0;

            // out of bound checks
            if(shifted_target < 0 || shifted_target >= j)
                return 0;

            // cache check
            if(dp[i][shifted_target] != -1)
                return dp[i][shifted_target];

            // rec calls
            int sub = rec(i + 1, target - nums[i], rec);
            int add = rec(i + 1, target + nums[i], rec);

            return dp[i][shifted_target] = sub + add;
        };
        
        return rec(0, target, rec);
    }
};

