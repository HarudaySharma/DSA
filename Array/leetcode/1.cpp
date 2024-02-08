#include "bits/stdc++.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    // i + j = target;
    // i = j - target?
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            auto it = hash.find(target - nums[i]);
            if(it != hash.end()) {
                vector<int> pair{i, it->second};
                return pair;
            }
        }
        vector<int> pair{-1, -1};
        return pair;
    }
};
