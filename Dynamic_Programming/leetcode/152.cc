#include <bits/stdc++.h>
#include <climits>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long maxPr = INT_MIN;
        long suffixPr = 1;
        long prefixPr = 1;
        for(int i = 0; i < n; i++) {
            suffixPr *= nums[i];
            prefixPr *= nums[n - i - 1];
            
            maxPr = max(maxPr, max(suffixPr, prefixPr));

            if(nums[i] == 0) {
                suffixPr = 1;
            }
            if(nums[n - i - 1] == 0) {
                prefixPr = 1;
            }
        }
        return maxPr == INT_MIN ? 0 : maxPr;
    }
};

