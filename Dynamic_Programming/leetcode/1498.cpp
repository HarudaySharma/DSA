#include <bits/stdc++.h>
#include <vector>
using namespace std;

// not solved
class Solution {
public:
    int count = 0;
    int top_bottom(int n, vector<int> &nums, int target, int mini, int maxi) {
        if(n == 0)
            return mini + maxi == target ? 1 : 0;
        if(mini + maxi == target)
            count += 1;
        int noTake = top_bottom(n - 1, nums, target, mini, maxi);
        int take = top_bottom(n - 1, nums, target, min(mini, nums[n]), max(maxi, nums[n]));
        return count += noTake + take;
    }
    int numSubseq(vector<int>& nums, int target) {

        return top_bottom(nums.size() - 1, nums, target, INT_MAX, INT_MIN);
    }
};
