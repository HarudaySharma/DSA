#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int top_bottom(int n, vector<int> &nums, unordered_map<int,int> &mp) {
        if(n < 0)
            return 0;
        if(n == 0)
            return nums[n];
        if(mp.count(n))
            return mp[n];
        int pick = nums[n] + top_bottom(n - 2, nums, mp);
        int nopick = top_bottom(n - 1, nums, mp);
        mp[n] = max(pick, nopick);
        return mp[n];
    }

    int bottom_top(vector<int> &nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int mx = INT_MIN;
        for(int i = 1; i < nums.size(); i++) {
            int take = nums[i] + i - 2 < 0 ? 0 : dp[i - 2];
            int noTake = dp[i - 1];
            dp[i] = max(take, noTake);
            mx = max(mx, dp[i]);
        }
        // mx == INT_MIN => only 1 ele in nums
        return mx == INT_MIN ? nums[0] : mx;
    }

    int spaceOptimised(vector<int> &nums, int start, int end) {
        int prev2 = 0;
        int prev1 = nums[start];
        int mx = prev1;
        for(int i = start + 1; i < end; i++) {
            int take = nums[i] + prev2;
            int noTake = prev1;
            prev2 = prev1;
            prev1 = max(take, noTake);
            mx = max(prev1, mx);
        }
        return mx;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return max(spaceOptimised(nums, 0, nums.size() - 1), spaceOptimised(nums, 1, nums.size()));
    }
};

