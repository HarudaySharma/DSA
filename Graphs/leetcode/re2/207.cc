#include "bits/stdc++.h"
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto p : prerequisites) {
            adjList[p[0]].push_back(p[1]);
        }

        auto DFS = [&](int i, vector<bool> &currPath, auto &&DFS) {
            if(currPath[i])
                return false;

            currPath[i] = true;
            for(auto pre : adjList[i]) {
                if (!DFS(pre, currPath, DFS)) {
                    return false;
                }
            }
            currPath[i] = false;
            adjList[i].clear(); // done visited all the preq nodes of this node

            return true;
        };

        vector<bool> currPath(numCourses, false);
        for(int i = 0; i < numCourses; i++) {
            if (!DFS(i, currPath, DFS)) {
                return false;
            }
        }

        return true;
    }
};

