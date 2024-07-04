#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class compare {
    public:
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
            return a.first > b.first;
        }
};

class Solution {
    public:
        vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

            vector<int> sortedQueries = queries;
            sort(sortedQueries.begin(), sortedQueries.end());
            sort(intervals.begin(), intervals.end());

            map<int, int> res;
            priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minHeap;
            int i = 0;
            for(auto query : sortedQueries) {
                // add all the intervals starting at the value less than query
                while(i < intervals.size() && intervals[i][0] <= query) {
                    int left = intervals[i][0];
                    int right = intervals[i][1];
                    minHeap.push({right - left + 1, right});
                    i++;
                }
                // remove all the intervals which does not contain query and contains no. less than query(as sorted Intervals)
                while(!minHeap.empty() && minHeap.top().second < query) {
                    minHeap.pop();
                }
                // add query result to the hashmap
                res[query] = minHeap.empty()? -1 : minHeap.top().first;
            }

            // get the queries stored in hashmap in the result array in correct order.
            vector<int> minIntervals;
            for(auto query : queries) {
                minIntervals.push_back(res[query]);
            }

            return minIntervals;
        }
};

