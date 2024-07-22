#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2003, 0);

        for(auto num : arr) {
            freq[num + 1002] += 1;
        }

        unordered_set<int> hasFreq;
        for(auto eleCount : freq) {
            if(hasFreq.count(eleCount)) {
                return false;
            }
            if(eleCount == 0)
                continue;
            hasFreq.insert(eleCount);
        }

        return true;
    }
};

