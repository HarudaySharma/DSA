#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool deleted = false;
        int maxLen = 0;
        int l = 0, r = 0;
        while(r < nums.size()) {
            if(nums[r] == 0 && !deleted) {
                deleted = true;
            }
            else if(nums[r] == 0 && deleted) {
                maxLen = max(maxLen, r - l - 1);
                // go to the neares 0 from the start
                while(nums[l] != 0){
                    l++;
                }
                // substring to be considered will start from l++
                l++;
            }
            r++;
        }
        maxLen = max(maxLen, r - l - 1);
        return maxLen;
    }
};
