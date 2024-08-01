#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adjList(n + 1);
        for(auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        vector<vector<int>> visited(n + 1);
        int curr_time = 0;
        bool secondTime = false;

        q.push(1);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                q.pop();

                if(node == n) {
                    if(secondTime) {
                        return curr_time;
                    }
                    secondTime = true;
                }

                for(auto nei : adjList[node]) {
                    if(visited[nei].empty() || (visited[nei].size() == 1 && visited[nei].back() != curr_time)) {
                        q.push(nei);
                        visited[nei].push_back(curr_time);
                    }
                }
            }
            if((curr_time / change) % 2 == 1) {
                curr_time += (change - (curr_time % change));
            }
            curr_time += time;
        }

        return -1;
    }
};

