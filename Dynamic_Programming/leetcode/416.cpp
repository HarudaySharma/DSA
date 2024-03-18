#include <bits/stdc++.h>
#include <vector>
using namespace std;
    
class Solution {
public:
    bool top_bottom(int i, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(target == 0 && i < 0) return true;
        if(target < 0 || i < 0) return false;
        if(nums[i] == target) return true;
        if(dp[i][target] != -1) return dp[i][target];
        bool noTake = top_bottom(i - 1, target, nums, dp);
        bool take = false;
        if(nums[i] <= target)
            take = top_bottom(i - 1, target - nums[i], nums, dp);
        return dp[i][target] = noTake || take;
    }

    bool bottom_top(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for(int i = 0; i < n; i++)
            dp[i][0] = true;
        if(nums[0] <= target)
            dp[0][nums[0]] = true;
        for(int i = 1; i < n; i++) {
            for(int x = 1; x <= target; x++) {
                bool noTake = dp[i - 1][x];
                bool take = false;
                if(nums[i] <= x)
                    take = dp[i - 1][x - nums[i]];
                dp[i][x] = noTake || take;
            }
        }
        return dp[n - 1][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto num : nums)
            totalSum += num;
        if(totalSum % 2 != 0)
            return false;
        //find totalSum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(totalSum / 2 + 1, -1));
        return top_bottom(nums.size() - 1, totalSum / 2, nums, dp);
        // return bottom_top(nums, totalSum / 2);
    }
};
