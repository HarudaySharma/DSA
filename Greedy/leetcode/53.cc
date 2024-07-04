#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxSum = INT_MIN;
       int currSum = 0;
        
       for(auto num : nums) {
           currSum += num;
           maxSum = max(maxSum, currSum);
           if(currSum < 0)
               currSum = 0;
       }

       return maxSum;
    }
};

