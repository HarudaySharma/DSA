#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        int count = 0;
        int sum = 0;
        for(auto num : nums) {
            sum += num;
            auto it = mp.find(sum - k);
            if(it != mp.end())
                count += it->second;
            if(mp.count(sum))
                mp[sum] += 1;
            else {
                mp.insert({sum, 1});
            }
        }
        return count;
    }
};
