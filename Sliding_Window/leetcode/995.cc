#include <bits/stdc++.h>
using namespace std;

// TLE
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int onesCount = 0;
        int flips = 0;
        int l = 0, r = 0;
        while(l < nums.size() && nums[l] == 1) {
            l++; r++;
        }
        while(r < nums.size()) {
            if(r - l + 1 == k) {
                int i = -1;
                while(l <= r) {
                    nums[l] = nums[l] == 0 ? 1 : 0;
                    if(i == -1 && nums[l] == 0)
                        i = l;
                    l++;
                }
                l = i;
                flips++;
            }
            r++;
        }
        cout << l << endl;
        return l == nums.size() ? flips : -1;
    }
};
