#include "bits/stdc++.h"
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int l = 0;
        int r = height.size() - 1;

        while(l < r) {
            int len = r - l;;
            if(height[l] < height[r]) {
                maxA = max(maxA, height[l] * len);
                l++;
            } else {
                maxA = max(maxA, height[r] * len);
                r--;
            }
        }

        return maxA;
    }
};


