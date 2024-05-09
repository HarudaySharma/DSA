#include <bits/stdc++.h>
#include <unistd.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<bool>> visited;
    int delx[4]{-1, 0, 1, 0};
    int dely[4]{0, 1, 0, -1};
    int tLi; int tLj; int bRi; int bRj;
    // land is found (marking all connected lands)
    void rec(int i, int j, int &n, int &m,  vector<vector<int>> &land) {
        if(i >= n || i < 0 || j >= m || j < 0 || visited[i][j] || land[i][j] == 0)
            return;
        if(tLi >= i && tLj > j) {
            tLi = i;
            tLj = j;
        }
        if(bRi <= i && bRj <= j) {
            bRj = j;
            bRi = i;
        }
        visited[i][j] = true;
        for(int a = 0; a < 4; a++) {
            int x = i + delx[a];
            int y = j + dely[a];
            rec(x, y, n, m, land);
        }
        return;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        if(land.empty()) 
            return res;
        int n = land.size();
        int m = land[0].size();
        visited.resize(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j] == 1 && !visited[i][j]) {
                    tLj = j; tLi = i;
                    bRj = j; bRi = i;
                    rec(i, j, n, m, land);
                    vector<int> v{tLi, tLj, bRi, bRj};
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};

