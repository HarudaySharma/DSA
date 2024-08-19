#include <bits/stdc++.h>
#include <unordered_set>
#include <variant>

using namespace std;

class Solution {
    public:
        int minReorder(int n, vector<vector<int>>& connections) {
            vector<vector<int>> adjListOut(n);
            vector<vector<int>> adjListIn(n);
            for(auto connection : connections) {
                adjListOut[connection[0]].push_back(connection[1]);
                adjListIn[connection[1]].push_back(connection[0]);
            }

            int minRevs = 0;
            vector<bool> visited(n, false);

            auto dfs = [&](int curr, auto &&dfs) {
                if(visited[curr])
                    return 0;
                visited[curr] = true;

                int reorderCount = 0;
                for(auto nei : adjListOut[curr]) {
                    if(!visited[nei])
                        reorderCount += dfs(nei, dfs) + 1; 
                }
                for(auto nei : adjListIn[curr]) {
                    reorderCount += dfs(nei, dfs);
                }

                return reorderCount;
            };

            return dfs(0, dfs);
        }
};

