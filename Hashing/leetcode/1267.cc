#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // 1 -> server
        // 0 -> no server
        // two server communicate -> if one same row or same col
        // retrun
        //  number of servers that communicate with any other servers.


        // bruteforce
        // optmized -> save the number of computers on same row and same col

        int n = grid.size();
        int m = grid[0].size();
        vector<int> rowComs(n, 0);
        vector<int> colComs(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    rowComs[i] += 1;
                    colComs[j] += 1;
                }
            }
        }

        int serverCount = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    if(rowComs[i] > 1 || colComs[j] > 1) {
                        serverCount += 1;
                    }
                }
            }
        }

        return serverCount;
    }
};

