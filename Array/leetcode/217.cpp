#include "bits/stdc++.h"
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>hash;
        for(auto el : nums) {
            auto it = hash.find(el);
            if(it != hash.end()) {
                return true;
            }
            hash.insert(el);
        }
        return false;
    }
};
