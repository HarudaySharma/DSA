#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // need some checking
    bool bottom_top(vector<int> &nums, int n, int target) {
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
        int minD = INT_MAX;
        for(int s1 = 0; s1 <= target / 2; s1++) {
            if(dp[n - 1][s1]) {
                int s2 = target - s1;
                minD = min(minD, abs(s1 - s2));
            }
        }
        return minD;
    }

    int minSubsetSumDifference(vector<int>& arr, int n) {
        int totSum = 0;
        for(auto point : arr)
            totSum += point;
        return bottom_top(arr, n, totSum);
    }
};
