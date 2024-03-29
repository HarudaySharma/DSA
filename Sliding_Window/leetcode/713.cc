#include "bits/stdc++.h"
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0 || k == 1)
            return 0;

        int product = 1;
        int subarrays = 0;
        for(int left = 0, right = 0; right < nums.size(); right++) {
            product *= nums[right];
            
            // check if the product is >= k
            while(product >= k){
                product /= nums[left++];
            }
            // append the sub array count to totalcount
            subarrays += (right - left) + 1;
        }
        return subarrays;
    }
};
