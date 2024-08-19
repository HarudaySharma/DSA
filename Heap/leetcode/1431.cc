#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = candies[0];
        for(auto &candie : candies) {
            maxCandies = max(maxCandies, candie);
        }

        vector<bool> res;
        for(auto &candie : candies) {
            if(candie + extraCandies >= maxCandies)
                res.push_back(true);
            else
                res.push_back(false);
        }

        return res;
    }
};

