#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> allCombs;
        vector<int> currComb;

        auto rec = [&](int currNum, vector<int> &currComb, auto &&rec) {
            if(currComb.size() == k) {
                allCombs.push_back(currComb);
                return;
            }
            if(currNum > n) {
                return;
            }

            for(int i = currNum; i <= n; i++) {
                currComb.push_back(i);
                rec(i + 1, currComb, rec);
                currComb.pop_back();
            }

            return;

        };

        rec(1, currComb, rec);

        return allCombs;
    }
};


