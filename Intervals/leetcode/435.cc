#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int minIntervals = 0;

        sort(intervals.begin(), intervals.end());
        vector<int> last;

        for (int i = 0; i < intervals.size(); i++) {
            if(last.empty()) {
                last = intervals[i];
                continue;
            }
            // overlapping
            if(!last.empty() && intervals[i][0] < last[1]) {
                minIntervals++;
                // keep the interval win minimum end
                if(intervals[i][1] < last[1]) {
                    last = intervals[i];
                }
            }
            else {
                last = intervals[i];
            }

        }
        
        return minIntervals;
    }
};

