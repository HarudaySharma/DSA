#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

// You are given an integer array height of length n. There are n vertical lines
// drawn such that the two endpoints of the ith line are (i, 0) and (i,
// height[i]).
//
// Find two lines that together with the x-axis form a container, such that the
// container contains the most water.
//
// Return the maximum amount of water a container can store.
//
// Notice that you may not slant the container.
//
//
//
// Example 1:
//
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array
// [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
// container can contain is 49.

class Solution {
    public:
        int maxArea(vector<int> &height) {
            int res = INT_MIN;
            int l = 0;
            int r = height.size() - 1;

            while(l < r) {
                if(height[l] < height[r]) {
                    res = max(res, height[l] * (r - l));
                    l++;
                }
                else {
                    res = max(res, height[r] * (r - l));
                    r--;
                }
            }

            return res;
        }
};
