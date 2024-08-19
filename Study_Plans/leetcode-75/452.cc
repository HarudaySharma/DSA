#include <bits/stdc++.h>
#include <queue>
using namespace std;

class comp {
    public:
        bool operator() (const vector<int> a, const vector<int> b) const {
            return a[0] == b[0] ? a[1] > b[1] :
                a[0] > b[0];
        }
};

class Solution {
public:

    int method1(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp());

        int minArrows = 0;
        for(int i = 0; i < points.size(); ) {
            int endPoint = points[i][1];

            int j = i;
            while(j < points.size() && points[j][0] <= endPoint){
                // as the jth ballon can be small than ith one
                endPoint = min(endPoint, points[j][1]); 
                j++;
            }

            minArrows += 1;
            i = j;
        }
        return minArrows;
    }

    int method2(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;

        for(auto point : points)
            pq.push(point);

        int minArrows = 0;
        int currEndPoint = -1;

        while(!pq.empty()) {
            currEndPoint = pq.top()[1];
            pq.pop();
            minArrows += 1;

            while(!pq.empty() && pq.top()[0] <= currEndPoint) {
                currEndPoint = min(currEndPoint, pq.top()[1]);
                pq.pop();
            }

        }

        return minArrows;
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        //return method1(points);
        return method2(points);
    }
};

