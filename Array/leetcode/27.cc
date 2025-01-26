#include "bits/stdc++.h"
#include <utility>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int matchCount = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val) {
                if(nums.size() - 1 - matchCount < 0)
                    break;
                swap(nums[i], nums[nums.size() - 1 - matchCount]);
                if(nums[i] == val) {
                    break;
                }
                matchCount += 1;
                i--;
            }
        }

        return matchCount;
    }
};

