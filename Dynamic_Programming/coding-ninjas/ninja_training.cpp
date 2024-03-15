#include "bits/stdc++.h"
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

struct PairHash {
    size_t operator () (const pair<int, int> &p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

int top_bottom(int idx, int last, vector<vector<int>> &points,unordered_map<pair<int, int>, int, PairHash> &mp) {
    int mx = INT_MIN;
    if(idx == 0){
        for(int i = 0; i < 3; i++) {
            if(i != last)
                mx = max(points[idx][i], mx);
        }
        return mx;
    }
    if(mp.count({idx, last}))
        return mp[{idx, last}];
    for(int i = 0; i < 3; i++) {
        if(i != last)
            mx = max(mx, points[idx][i] + top_bottom(idx - 1, i, points, mp));
    }
    mp[{idx, last}] = mx;
    return mx;
}

int bottom_top(vector<vector<int>> &points, int n) {
    unordered_map<pair<int, int>, int, PairHash> mp;
    mp[{0, 0}] = max(points[0][1], points[0][2]);
    mp[{0, 1}] = max(points[0][0], points[0][2]);
    mp[{0, 2}] = max(points[0][0], points[0][1]);

    int last = -1;
    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 3; last++) {
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int pts =  points[day][task] + mp[{day - 1, task}];
                    mp[{day, last}] = max(mp[{day, last}], pts);
                }
            }

        }
    }
    return max(mp[{n - 1, 0}], max(mp[{n - 1, 1}], mp[{n - 1, 2}]));
}


int ninjaTraining(int n, vector<vector<int>> &points) {
    // unordered_map<pair<int, int>, int, PairHash> mp;
    // return top_bottom(n - 1, -1, points, mp);
    return bottom_top(points, n);
}
