#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> visited;
    bool DFS(int i, vector<int> *adjList) {
        if(visited[i])
            return false;
        vector<int> &prereq =  adjList[i];
        if(prereq.empty())
            return true;
        visited[i] = true;
        for(auto el : prereq) {
            if(!DFS(el, adjList))
                return false;
        }
        visited[i] = false;
        prereq.clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create a AdjList
        vector<int> adjList[numCourses];
        visited.resize(numCourses, false);
        for(auto pr : prerequisites) {
            adjList[pr[0]].push_back(pr[1]);
        }
        for(int i = 0; i < numCourses; i++){
                if(!DFS(i, adjList))
                    return false;
        }
        return true;
    }
};

