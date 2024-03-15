#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCount = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                product *= nums[i];
            }
            else {
                zeroCount += 1;
            }
        }
        vector<int> res;
        if(zeroCount) {
            if(zeroCount > 1) {
                res.resize(nums.size(), 0);
                return res;
            }
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) {
                    res.push_back(product);
                }
                else {
                    res.push_back(0);
                }
            }
            return res;
        }
        for(int i = 0; i < nums.size(); i++) {
            res.push_back(product / nums[i]);
        }
        return res;
    }
};
