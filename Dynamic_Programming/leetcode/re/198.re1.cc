#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int top_bottom(int i, int sum, int n, vector<int> &nums, map<pair<int, int>, int> &dp) {
        if(i == n)
            return sum;
        if(dp.count({i, sum}))
            return dp[{i, sum}];
        int NOT_ROB = top_bottom(i + 1, sum , n, nums, dp);
        int ROB = top_bottom(i + 1, sum + nums[i], n, nums, dp);
        return dp[{i, sum}] = max(NOT_ROB, ROB);
    }
    int rob(vector<int>& nums) {
        map<pair<int, int>, int> dp;
        return top_bottom(0, 0, nums.size(), nums, dp);
    }
};
