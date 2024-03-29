#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    int top_bottom(int i, vector<int> &nums, int n, vector<int> &dp) {
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int noTake = top_bottom(i + 1, nums, n, dp);
        int take = nums[i] + top_bottom(i + 2, nums, n, dp);
        return dp[i] = max(noTake, take);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int withFirst = top_bottom(0, nums, nums.size() - 1, dp);
        dp.resize(nums.size(), -1);
        int withoutFirst = top_bottom(1, nums, nums.size(), dp);
        return max(withFirst, withoutFirst);
    }
};
