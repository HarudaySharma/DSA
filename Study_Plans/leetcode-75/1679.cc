#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:

        int approach1(vector<int>& nums, int k) {
            // pairs with sum equals k
            map<int, int> mp;

            int maxOps = 0;
            for(auto num : nums) {
                if(mp.count(k - num)) {
                    maxOps += 1;
                    mp[k - num] -= 1;
                    if(mp[k - num] == 0)
                        mp.erase(k - num);
                }
                else {
                    mp[num] += 1;
                }
            }

            return maxOps;
        }

        int approach2(vector<int>& nums, int k) {
            int maxOps = 0;

            sort(nums.begin(), nums.end());

            int l = 0;
            int r = nums.size() - 1;
            while(l < r) {
                if(nums[l] + nums[r] == k) {
                    maxOps += 1;
                    l++; r--;
                }
                else if(nums[l] + nums[r] > k)
                    r--;
                else
                    l++;
            }

            return maxOps;
        }

    public:
        int maxOperations(vector<int>& nums, int k) {
            return approach2(nums, k);
        }
};

