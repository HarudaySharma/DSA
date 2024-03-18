#include <bits/stdc++.h>
#include <climits>
#include <unordered_set>
using namespace std;

// * NOT WORKING
class Solution {
public:
    int helper(int cr, int target, vector<int>& nums, unordered_set<int> &mp, int &minJ) {
        if(cr > target)
            return -1;
        if(cr == target)
            return cr;
        if(mp.count(cr))
            return -1;
        mp.insert(cr);
        for(int i = 1; i <= nums[cr]; i++) {
            if(!mp.count(cr + i)) {
                int mj = helper(cr + i, target, nums, mp, minJ);
                if(mj != -1)
                    minJ = min(mj, minJ);
            }
        }
        return -1;
    }

    bool jump(vector<int>& nums) {
        int target = nums.size() - 1;
        unordered_set<int>mp;
        int minJ = INT_MAX;
        helper(0, target, nums, mp, minJ);
        return minJ;
    }
};

