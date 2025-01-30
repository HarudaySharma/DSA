#include "bits/stdc++.h"

using namespace std;

class Solution {
public:

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //return usingDFS(numCourses, prerequisites, queries);
        return usingKahnAlgo(numCourses, prerequisites, queries);
    }

private:

    vector<bool> usingKahnAlgo(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDeg(numCourses, 0);

        for(auto prerequisite : prerequisites) {
            int u = prerequisite[0];
            int v = prerequisite[1];

            adjList[u].push_back(v); // u --> v
            inDeg[v] += 1;
        }

        // running kahn's algorithm  (topo sort)
        //  to compute prerequisite nodes for all the nodes in the graph
        queue<int> q;
        for(int i = 0; i < inDeg.size(); i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }

        unordered_map<int, unordered_set<int>> mp; //{node, {prerequisite nodes}}
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto &nei : adjList[node]) {
                mp[nei].insert(node); // node is the prerequisite of nei
                // finding the prerequisite nodes of 'node' to add into the prerequisite list of nei
                for(auto &preReqNode : mp[node]) {
                    mp[nei].insert(preReqNode);
                }

                inDeg[nei] -= 1;
                if(inDeg[nei] == 0){
                    q.push(nei);
                }
            }
        }

        vector<bool> res;
        // solving the queries
        for(auto q : queries) {
            int u = q[0]; // src
            int v = q[1]; // dest
            // check if the src is prerequisite of dest
            if(mp[v].count(u)) { // if 'u' is present in the prerequisite list of 'v'
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }

        return res;
    }

    vector<bool> usingDFS(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // create an adj list
        vector<vector<int>> adjList(numCourses);
        vector<bool> res;

        for(auto prerequisite : prerequisites) {
            int u = prerequisite[0];
            int v = prerequisite[1];
            adjList[u].push_back(v);
        }

        for(auto query : queries) {
            int u = query[0];
            int v = query[1];
            vector<bool> visited(numCourses, false);
            res.push_back(dfs(u, v, adjList, visited));
        }

        return res;
    }

    bool dfs(int src, int dest, vector<vector<int>> &adjList, vector<bool> &visited) {
        if(src == dest) {
            return true;
        }
        if(visited[src]) {
            return false;
        }

        visited[src] = true;
        for(auto preReq : adjList[src]) {
            if(dfs(preReq, dest, adjList, visited)) {
                return true;
            }
        }

        return false;
    }

};
