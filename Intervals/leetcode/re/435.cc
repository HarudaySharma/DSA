#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int minOverlaps = 0;

        sort(intervals.begin(), intervals.end());
        int prevEnd = INT_MIN;
        for(auto interval : intervals) {
            if(interval[0] < prevEnd) {
                minOverlaps += 1;
                if(interval[1] < prevEnd)
                    prevEnd = interval[1];
            }
            else {
                prevEnd = interval[1];
            }
        }

        return minOverlaps;
    }
};

