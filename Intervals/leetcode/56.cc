#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // merge overlapping intervals
        vector<vector<int>> res;
        // sort the intervals;
        sort(intervals.begin(), intervals.end());
        // append merged intervals to the res;
        res.push_back(*intervals.begin());
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][0] <= res.back()[1]) {
                res.back()[0] = min(res.back()[0], intervals[i][0]);
                res.back()[1] = max(res.back()[1], intervals[i][1]);
                continue;
            }
            res.push_back(intervals[i]);
        }
        return res;
    }
};

