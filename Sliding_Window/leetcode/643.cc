#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;
        double sum = 0;
        int left = 0, right = 0;
        while(right < nums.size()) {
            sum += nums[right];
            if(right - left + 1 == k){
                maxAvg = max(maxAvg, sum / k);
                sum -= nums[left++];
            }
            right++;
        }
        return maxAvg;
    }
};
