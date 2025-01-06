#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // making the non reachable nodes "inf"
        // and same node distance "0"
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == -1) matrix[i][j] = 1e9;
                if(i == j) matrix[i][j] = 0;
            }

        }

        // main algorithm: basically it is a brute force approach
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = min(
                        matrix[i][j],
                        matrix[i][via] + matrix[via][j]
                    );
                }
            }
        }

        // negative cycle check
        for(int i = 0; i < n; i++) {
            if(matrix[i][i] < 0) {
                // negative cycle
            }
        }


        // resetting the matrix non-reachable nodes to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(matrix[i][i] == 1e9)
                    matrix[i][j] = -1;
            }
        }

        return;
    }
};
