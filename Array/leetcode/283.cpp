#include "bits/stdc++.h"
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        // 1 2 0 3 12 => 1 2 12 3 0 -> 1 2 3 12;
        void moveZeroes(vector<int> &nums) {
            int zrsCount = countZeros(nums);
            if (zrsCount == nums.size())
                return;
            int i = 0;
            int rotations = zrsCount;
            while (rotations) {
                if (nums[i] == 0) {
                    reverse(nums, i, nums.size() - 1 - (zrsCount - rotations));
                    reverse(nums, i, nums.size() - 1 - (zrsCount - rotations + 1));
                    rotations--;
                }
                else {
                    i++;
                }
            }
        }

        void reverse(vector<int> &nums, int start, int end) {
            while (start < end) {
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start++;
                end--;
            }
            return;
        }

        int countZeros(vector<int> &nums) {
            int count = 0;
            for (auto el : nums) {
                if (el == 0)
                    count++;
            }
            return count;
        }
};
