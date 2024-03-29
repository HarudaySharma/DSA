#include <bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> dp;
    void populateDPArray(vector<int> &nums, int index = 0, int sum = 0) {
        if(index >= nums.size())
            return;
        sum += nums[index];
        dp.push_back(sum);
        populateDPArray(nums, index + 1, sum);
    }

public:
    NumArray(vector<int>& nums) {
        populateDPArray(nums);
    }
    
    int sumRange(int left, int right) {
        int l = 0;
        if(left > 0)
            l = dp[left - 1];
        int r = dp[right];
        return r - l;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
