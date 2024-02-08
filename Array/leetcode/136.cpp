#include "bits/stdc++.h"
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number = 0;
        for(auto el : nums) 
            number ^= el;
        return number;
    }
};
