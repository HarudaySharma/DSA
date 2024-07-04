#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            // already visited checks and
            vector<int> dp(nums.size(), false);

            auto rec = [&](int idx, auto &&rec) {

                if(idx > nums.size()) {
                    return false;
                }
                if(idx == nums.size() - 1) {
                    return true;
                }

                if(dp[idx])
                    return false;

                // mark checked
                dp[idx] = true;

                // transition
                for(int i = 1; i <= nums[idx]; i++) {
                    if(!dp[idx + i]) {
                        if(rec(idx + i, rec)) 
                            return true;
                    }
                }

                return false;
            };

            return rec(0, rec);
        }
};

