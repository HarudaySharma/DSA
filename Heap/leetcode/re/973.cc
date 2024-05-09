#include <bits/stdc++.h>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

class Comp {
    public:
        bool operator() (const pair<int, int> a, const pair<int, int> b) const {
            double distA = sqrt(pow(a.first, 2) + pow(a.second, 2));
            double distB = sqrt(pow(b.first, 2) + pow(b.second, 2));
            return distA < distB;
        }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
        Comp compare;
        for(auto point : points) {
            if(pq.size() < k) {
                pq.push({point[0], point[1]});
            }
            else {
                if(!compare(pq.top(), {point[0], point[1]})) {
                    pq.pop();
                    pq.push({point[0], point[1]});
                }
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()) {
            vector<int> ans;
            ans.push_back(pq.top().first);
            ans.push_back(pq.top().second);
            res.push_back(ans);
            pq.pop();
        }
        return res;
    }
};


