#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxNum = INT_MIN;
        for(auto num : nums)
            maxNum = max(maxNum, num);
        int maxCount = 0;
        long long subArrayCount = 0;
        for(int left = 0, right = 0; right < nums.size(); right++) {
            if(nums[right] == maxNum)
                maxCount += 1;
            while(maxCount >= k){
                subArrayCount += nums.size() - right;
                if(nums[left++] == maxNum)
                    maxCount -= 1;
            }
        }
        return subArrayCount;
    }
};
