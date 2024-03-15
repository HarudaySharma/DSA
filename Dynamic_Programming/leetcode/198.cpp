#include "bits/stdc++.h"
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>
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

    int spaceOptimised(vector<int> &nums) {
        int prev2 = 0;
        int prev1 = nums[0];
        int mx = prev1;
        for(int i = 1; i < nums.size(); i++) {
            int take = nums[i] + prev2;
            int noTake = prev1;
            prev2 = prev1;
            prev1 = max(take, noTake);
            mx = max(prev1, mx);
        }
        return mx;
    }

    int rob(vector<int>& nums) {
        //unordered_map<int, int> mp;
        //top_bottom(nums.size() - 1, nums, mp);
        //return bottom_top(nums);
        return spaceOptimised(nums);
    }
};
