#include <bits/stdc++.h>
#include <cmath>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    //(x1 - x2)2 + (y1 - y2)2)
    long double distance(vector<int> v) {
        return sqrt((v[0]*v[0]) + (v[1]*v[1]));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>>q;
        for(auto point : points) {
            long double dist = distance(point);
            if(q.size() < k){
                q.push({dist, point});
            }
            else {
                if(q.top().first > dist) {
                    q.pop();
                    q.push({dist, point});
                }
            }
        }
        vector<vector<int>> res;
        while(!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
