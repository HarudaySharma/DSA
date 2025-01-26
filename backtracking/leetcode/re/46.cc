#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPerms;

        auto rec = [&](int i, auto &&rec) {
            if(i >= nums.size()) {
                allPerms.push_back(nums);
                return;
            }

            for(int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                rec(i + 1, rec);
                swap(nums[i], nums[j]);
            }

            return;
        };

        rec(0, rec);

        return allPerms;
    }
};


