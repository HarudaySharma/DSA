#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        auto rec = [&] (int curr, vector<int> ans, auto &&rec) {
            if(curr == nums.size()){
                res.push_back(ans);
                return; 
            }
            // include
            ans.push_back(nums[curr]);
            rec(curr + 1, ans, rec);
            // don't include (skip the dups also)
            ans.pop_back();
            while(curr + 1 < nums.size() && nums[curr] == nums[curr + 1]) curr++;
            rec(curr + 1, ans, rec);
            return;
        };
        rec(0, {}, rec);
        return res;
    }
};

