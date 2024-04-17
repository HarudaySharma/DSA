#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subs;
    void rec(vector<int> &nums, int pos, vector<int> subset) {
        if(pos >= nums.size()) {
            subs.push_back(subset);
            return;
        }
        rec(nums, pos + 1, subset);
        subset.push_back(nums[pos]);
        rec(nums, pos + 1, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        rec(nums, 0, {});
        return subs;
    }
};

