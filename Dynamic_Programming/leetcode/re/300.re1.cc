#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        auto rec = [&](int lvl, auto &&rec) -> int {
            if(lvl < 0)
                return 0;
            if(dp[lvl] != -1)
                return dp[lvl];
            int ans = 1;
            for(int prev_taken = 0; prev_taken < lvl; prev_taken++) {
                if(nums[prev_taken] < nums[lvl]){
                    ans = max(ans, 1 + rec(prev_taken, rec));
                }
            }
            return dp[lvl] = ans;
        };

        int bestLen = 1;
        for(int i = 0; i < nums.size(); i++) {
            bestLen = max(bestLen, rec(i, rec));
        }
        return bestLen;
    }
};

