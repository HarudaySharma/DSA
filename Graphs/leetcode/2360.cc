#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int longest = -1;

    int longestCycle(vector<int>& edges) {

        // creating a adjList
        int n = edges.size();
        vector<vector<int>> adjList(n);

        for(int i = 0; i < n; i++) {
            if(edges[i] == -1) {
                continue;
            }
            adjList[i].push_back(edges[i]);
        }

        vector<bool> visited(n, false);
        // finding the largest possible cycle
        for(int i = 0; i < n; i++) {
            // cout << "for src : " << i << endl;
            cycleCount(i, i, 0, adjList, visited);
            // cout << endl;;
        }

        return longest;
    }

    void cycleCount(int &src, int curr, int pathNodes, vector<vector<int>> &adjList, vector<bool> &visited) {
        // cout << curr << " -> ";
        if(curr == src && visited[src]) {
            longest = max(longest, pathNodes);
            return;
        }

        visited[curr] = true;

        for(auto &nei : adjList[curr]) {
            if(nei == src || !visited[nei]) {
                cycleCount(src, nei, pathNodes + 1, adjList, visited);
            }
        }

        visited[curr] = false;

        return;
    }
};

