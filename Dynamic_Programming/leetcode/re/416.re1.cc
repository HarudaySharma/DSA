#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums)
            sum += num;
        // if sum can't be partitioned
        if((sum & 1) != 0) {
            return false;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));

        auto rec = [&](int i, int target, auto &&rec) -> bool {
            if(i >= nums.size() && !(target == 0)) {
                return false;
            }
            if(i >= nums.size() && target == 0) {
                return true;
            }
            if(target < 0) {
                return false;
            }
            if(target == 0) {
                return true;
            }
            if(dp[i][target] != -1) {
                return dp[i][target];
            }

            dp[i][target] = rec(i + 1, target, rec) ||
                rec(i + 1, target - nums[i], rec);
            return dp[i][target];
        };

        return rec(0, sum / 2, rec);

    }
};

