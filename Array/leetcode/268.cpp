#include "bits/stdc++.h"
#include <sys/types.h>
#include <vector>

using namespace std;

class Solution {
public:
    // 0 - n => arr[i] = i {if not like this, make it}
    int missingNumber(vector<int>& nums) {
        sortList(nums);
        return check(nums);
    }

    int check(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums.at(i) != i) 
                return i;
        }
        return nums.size();
    }
    
    void swap(int &a, int &b) {
        a +=  b;
        b = a - b;
        a = a - b;
        return;
    }

    void sortList(vector<int> &nums) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] < nums.size() && nums[i] != i) {
              swap(nums[i], nums[nums[i]]);
            }
            else {
                i++;
            }
        }
    }
};
