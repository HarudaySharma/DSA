#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    long val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(long x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(long x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}
};

struct ListNode {
    long val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(long x) : val(x), next(nullptr) {}
    ListNode(long x, ListNode *next) : val(x), next(next) {}
};

class DSU {
private:
    unordered_map<int, int> parent; // as we don't know the total nodes
    unordered_map<int, int> rank; // rank is depecting the number of nodes in a disjoint set (i.e. rank of representative node of ds)

public:
    DSU(vector<vector<int>>& edges) {
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // inital config
            parent[u] = u;
            parent[v] = v;
            rank[u] = 1;
            rank[v] = 1;
        }
    }

    int find(int node) {
        int p = parent[node];
        if(p == node) {
            return p;
        }

        return parent[node] = find(p);
    }

    int unite(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if(p1 == p2) {
            return false; // already in the same disjoint set.
        }

        if(rank[p1] >= rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else{
            parent[p1] = p2;
            rank[p2] += rank[p1]; // rank is to be added
        }

        return true;
    }

};

class Solution {
public:
    bool isBipartite(int i, int prevColor, vector<int> &color, vector<vector<int>> &adjList) {
        if(color[i] != -1) {
            return color[i] != prevColor; // is
        }

        color[i] = !prevColor;
        for(auto nei : adjList[i]) {
            if(nei == i) {
                continue;
            }
            if(!isBipartite(nei, !prevColor, color, adjList)) {
                return false;
            }
        }

        return true;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n + 1); // 1 indexed graph
        vector<int> color(n + 1, -1); // {-1 (not coloured) || 0 (color1) || 1 (color2) }

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for(int u = 1; u <= n; u++) {
            if(color[u] != -1) continue;
            // as graph can be disconnected => checking from all the nodes
            if(!isBipartite(u, 0, color, adjList)) {
                return -1;
            }
        }

        // BFS from each node to find the maximum Groups that can be formed
        // we will store the number of groups that can be created if started from a node
        // as later if there are disconnected graphs we can get the
        // maximum group we can get from each connected graph and add it up to constitue the maximum number of groups possible.

        vector<int> maxGroup(n + 1, 0);

        for(int u = 1; u <= n; u++) {
            maxGroup[u] = maxGroupsFormingFromThisNode(u, adjList);
        }

        vector<bool> visited(n + 1, false);
        // find the maximumGroup for each comp
        int maxGroupsForming = 0;
        for(int u = 1; u <= n; u++) {
            if(visited[u]) continue;
            maxGroupsForming += findMaxGroupInGraph(u, adjList, visited, maxGroup);
        }

        return maxGroupsForming;
    }


    int findMaxGroupInGraph(int u, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &maxGroup) {
        if(visited[u])
            return INT_MIN;

        visited[u] = true;

        int maxi = maxGroup[u];
        for(auto &nei : adjList[u]) {
            maxi = max(maxi, findMaxGroupInGraph(nei, adjList, visited, maxGroup));
        }

        return maxi;
    }

    int maxGroupsFormingFromThisNode(int u, vector<vector<int>> &adjList) {
        vector<bool> visited(adjList.size() + 1, false);
        queue<int> q;

        q.push(u);

        int lvl = 1; // nodes on the same level can be in the same group
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int curr = q.front();
                q.pop();

                if(visited[curr]) {
                    continue;
                }

                visited[curr] = true;
                for(auto nei : adjList[curr]) {
                    if(visited[nei]) continue; // as levels are increasing in sufficiently
                    q.push(nei);
                }
            }
            lvl += 1;
        }

        return lvl - 1; // as lvl will get incremented 1 extra for last iteration (when queue will get empty)
    }
};
