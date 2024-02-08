#include "bits/stdc++.h"
#include <vector>
using namespace std;

// 136, 283
class Solution {
public:
    // arr[i] = i + 1
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sortList(nums);
        return disappearedNums(nums);
    }
    vector<int> disappearedNums(vector<int> &nums) {
        vector<int>res;
        for(int i = 0; i < nums.size(); i++) {
            if(nums.at(i) != i + 1) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
    
    void swap(int &a, int &b) {
        a +=  b;
        b = a - b;
        a = a - b;
        return;
    }


    void sortList(vector<int> &nums) {
        // nums range(1 to n) 
        // if (1 present):
        //  pos(1) => 0 => (1 - 1);
        //
        // i.e 
        //  if(nums[i]) => correct postion => nums[i] - 1
        //
        // if(nums[i] = 11):
        //  correct postion = 11 - 1 => 10
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] - 1 < nums.size() && nums[i] != nums[nums[i] - 1]) {
              swap(nums[i], nums[nums[i] - 1]);
            }
            else {
                i++;
            }
        }
    }
};
