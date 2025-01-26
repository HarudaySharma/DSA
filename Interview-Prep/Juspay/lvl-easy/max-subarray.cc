#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// Given an integer array nums, find the
// subarray
// with the largest sum, and return its sum.
//
//
//
// Example 1:
//
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
//
// Example 2:
//
// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(maxSum < sum) {
                maxSum = sum;
            }
            if(sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};
