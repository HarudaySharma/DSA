#include <bits/stdc++.h>
#include <climits>
using namespace std;

/* Given an integer array nums, return true if there exists a triple of indices
 * (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such
 * indices exists, return false. */

class Solution {
    private:
        // T: O(N)
        // S: O(N)
        bool approach1(vector<int> &nums) {
            int n = nums.size();
            vector<int> prevMin(n, INT_MAX);
            vector<int> nextMax(n, INT_MIN);

            for(int i = 0, j = n - 1; i < n - 1; i++, j--) {
                prevMin[i + 1] = min(nums[i], prevMin[i]);
                nextMax[j - 1] = max(nums[j], nextMax[j]);
            }

            for(int i = 1; i < n - 1; i++) {
                if(prevMin[i] < nums[i] && nums[i] < nextMax[i])
                    return true;
            }

            return false;
        }

        // T: O(N)
        // S: O(1)
        bool approach2(vector<int> &nums) {
            // calculate min and max as we go through
            // at any point we need the min and max there is
            // from left to right
            // min can be found!!
            // what about maximum?
            // how ?
            // maximum must be calculated beforehand for every position
            // how about 2 pointers
            // instead of finding maximum value
            // we operate on maximum value at each index
            // i.e the element we are currently visiting will be the largest of the triplet.
            // therefore, we must know the smallest and second largest el beforehand
            // how?
            // keep track of these numbers using two pointers.

            int n = nums.size();

            int x = INT_MAX;
            int y = INT_MAX;

            for(int i = 0; i < n; i++) {
                if(nums[i] < x) {
                    x = nums[i];
                }
                else if(nums[i] != x && nums[i] < y) {
                    y = nums[i];
                }
                else if(x < y && y < nums[i]) {
                    return true;
                }
            }

            return false;
        }


    public:
        bool increasingTriplet(vector<int> &nums) {
            return approach2(nums);
        }
};

