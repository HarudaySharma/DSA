#include <bits/stdc++.h>
#include <vector>
using namespace std;

// NOT CHECKED (PROBABLY)
class Solution {
    public:
        int top_bottom(int i, int target, int &n, vector<int> &nums,map<pair<int, int>, int>  &dp) {
            if(i == n)
                return target == 0;
            if(dp.count({i, target}))
                return dp[{i, target}];
            int add = top_bottom(i + 1, target + nums[i], n, nums, dp);
            int sub = top_bottom(i + 1, target - nums[i], n, nums, dp);
            return dp[{i, target}] = add + sub;

        }

        int findTargetSumWays(vector<int>& nums, int target) {
            int n = nums.size();
            map<pair<int, int>, int> dp;
            return top_bottom(0, target, n, nums, dp);
        }
};
