#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int longestLen = 0;
            bool zeroInSubArray = false;

            int l = 0, r = 0;
            while(r < nums.size()) {
                if(nums[r] == 0) {
                    if(zeroInSubArray) {
                        while(nums[l] != 0)
                            l++;
                        l++;
                    }
                    else {
                        zeroInSubArray = true;
                    }
                }
                longestLen = max(longestLen, r - l + 1);
                r++;
            }

            return longestLen;
        }
};

