#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool helper(int cr, int target, vector<int>& nums, unordered_set<int> &mp) {
        if(cr > target)
            return false;
        if(cr == target)
            return true;
        if(mp.count(cr))
            return false;
        mp.insert(cr);
        for(int i = 1; i <= nums[cr]; i++) {
            if(!mp.count(cr + i)) {
                if(helper(i, target, nums, mp))
                    return true;
            }
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        int target = nums.size() - 1;
        unordered_set<int>mp;
        return helper(0, target, nums, mp);
    }
};
