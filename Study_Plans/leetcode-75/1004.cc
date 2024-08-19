#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int res = 0;
        while(r < nums.size()) {
            if(nums[r] == 0) 
                k--;
            if(k < 0) {
                while(nums[l] != 0)
                    l++;
                k++;
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};

