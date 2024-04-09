#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int l = 0, r = 0;
        int sum = 0;
        while(r < nums.size()) {
            sum += nums[r];
            while(sum >= target) {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l++];
            }
            if(minLen == 1)
                return 1;
            r++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
