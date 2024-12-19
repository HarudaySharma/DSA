#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int x = 0; x < nums.size(); x++) {
            int i = x + 1;
            int j = nums.size() - 1;
            while(i < j) {
                int sum = nums[x] + nums[i] + nums[j];
                if(sum == 0) {
                    res.push_back(vector<int>{nums[x], nums[i], nums[j]});
                    while(i < j - 1 && nums[i] == nums[i + 1]) {
                        i++;
                    }
                    while(j > 0 && nums[j - 1] == nums[j]) {
                        j--;
                    }
                    i++, j--;
                } else if(sum < 0) {
                    i++;
                } else {
                    j--;
                }
            }
            while(x < nums.size() - 1 && nums[x] == nums[x + 1]) {
                x++;
            }
        }

        return res;
    }
};

