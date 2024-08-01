#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool DFS(int currNum, vector<vector<int>> &adjList, vector<int> &order,
                vector<bool> &visited, vector<bool> &path) {
            if (path[currNum])
                return false;
            if (visited[currNum])
                return true;

            path[currNum] = true;
            visited[currNum] = true;
            for (auto num : adjList[currNum]) {
                if (!DFS(num, adjList, order, visited, path))
                    return false;
            }

            order.push_back(currNum);
            path[currNum] = false;
            return true;
        };

        vector<int> topoSort(vector<vector<int>> &conditions, int &k) {
            vector<bool> path(k + 1, false);
            vector<bool> visited(k + 1, false);
            vector<int> order;

            // adjacency list;
            vector<vector<int>> adjList(k + 1);
            for (auto pr : conditions) {
                adjList[pr[1]].push_back(pr[0]);
            }

            for (int i = 1; i < k + 1; i++) {
                if (!DFS(i, adjList, order, visited, path)) {
                    return {};
                }
            }
            // reverse(order.begin(), order.end());

            return order;
        };
        vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                vector<vector<int>> &colConditions) {

            vector<int> rowOrder = topoSort(rowConditions, k);
            vector<int> colOrder = topoSort(colConditions, k);

            if (rowOrder.empty() || colOrder.empty()) {
                return {};
            }

            map<int, int> rowPos;
            map<int, int> colPos;
            for (int i = 0; i < rowOrder.size(); i++) {
                rowPos[rowOrder[i]] = i;
            }
            for (int i = 0; i < colOrder.size(); i++) {
                colPos[colOrder[i]] = i;
            }

            vector<vector<int>> mat(k, vector<int>(k, 0));
            for (int i = 1; i < k + 1; i++) {
                int r = rowPos[i];
                int c = colPos[i];
                mat[r][c] = i;
            }
            return mat;
        }
};
