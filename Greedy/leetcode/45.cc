#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {

            int minJmp = 0;
            int l = 0, r = 0;
            while(r < nums.size() - 1) {
                int farthest = 0;
                for(int i = l; i <= r; i++) {
                    farthest = max(farthest, i + nums[i]);
                }
                l = r + 1;
                r = farthest;
                minJmp += 1;
            }

            return minJmp;
        }
};

