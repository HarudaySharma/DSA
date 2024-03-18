#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <unordered_set>
using namespace std;

class Solution {
public:
    //  [[1,3],[6,9]], newInterval = [2,5]
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s = -1;
        int e = -1;
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i++) {
            int x = -1;
            if(newInterval[0] > intervals[i][0] && newInterval[0] < intervals[i][1]) {
                x = i;
                while(newInterval[1] > intervals[i][0] && newInterval[1] > intervals[i][1])
                    i++;
            }
            if(x != -1) {
                int start = min(min(newInterval[0], intervals[x][0]), intervals[x][1]);
                int end = newInterval[1];
                int m = min(min(newInterval[1], intervals[i][0]), intervals[i][1]);
                int l = max(max(newInterval[1], intervals[i][0]), intervals[i][1]);
                if(m != newInterval[1]) {
                    if (l != newInterval[1]) {
                        intervals[i][0] = end + 1;
                    }
                    else {
                        i++;
                    }
                }
                else if(newInterval[1] == intervals[i][0]) {
                    end = intervals[i][1];
                    ans.push_back({start, end});
                    i++;
                }
                else {
                    ans.push_back({start, end});
                    i++;
                }
                if(i < intervals.size())
                    ans.push_back(intervals[i]);
            }
            else {
            ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
