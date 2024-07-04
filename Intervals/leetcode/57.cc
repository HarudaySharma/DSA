#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
            vector<vector<int>> res;
            for(int i = 0; i < intervals.size(); i++) {
                if(newInterval[1] < intervals[i][0]) {
                    res.push_back(newInterval);
                    while(i < intervals.size()) {
                        res.push_back(intervals[i]);
                        i++;
                    }
                    return res;
                }
                else if(newInterval[0] > intervals[i][1]) {
                    res.push_back(intervals[i]);
                }
                else {
                    int start = min(intervals[i][0], newInterval[0]);
                    int end = max(intervals[i][1], newInterval[1]);
                    newInterval = {start, end};
                }
            }
            res.push_back(newInterval);
            return res;
        }
};
