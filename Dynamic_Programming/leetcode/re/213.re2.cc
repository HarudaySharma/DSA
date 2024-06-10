#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    map<int, int> dp;
    int rec(int i, vector<int> &nums, int n) {
        if(i >= n) {
            return 0;
        }
        if(dp.count(i)) {
            return dp[i];
        }
        int mx = rec(i + 1, nums, n);
        mx = max(mx, nums[i] + rec(i + 2, nums, n));
        return dp[i] = mx;
    }

    int rob(vector<int>& nums) {
        int withFirst = rec(0, nums, nums.size() - 1);
        dp.clear();
        int withLast = rec(1, nums, nums.size());
        return max(withLast, withFirst);
    }
};

