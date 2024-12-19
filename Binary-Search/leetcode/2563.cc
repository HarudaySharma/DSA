#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            const int num = nums[i];
            // first ele less than (upper - num);
            auto lIt = lower_bound(nums.begin() + i + 1, nums.end(), lower - num);
            int lPairs = (lIt - nums.begin()) - i - 1;
            // first ele greater than (upper - num);
            auto rIt = upper_bound(nums.begin() + i + 1, nums.end(), upper - num);
            int uPairs = (rIt - nums.begin()) - i - 1;

            count += (uPairs - lPairs);
        }

        return count;
    }
};
