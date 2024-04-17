#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void rec(vector<int> &nums, int low, int high) {
        if(low >= high){
            res.push_back(nums);
            return;
        }
        for(int i = low; i < high; i++) {
            if(i != low)
                swap(nums[low], nums[i]);
            rec(nums, low + 1, high);
            if(i != low)
                swap(nums[low], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        rec(nums, 0, nums.size());
        return res;
    }
};

