#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Not Completed
class Solution {
    public:
        static void dfs(vector<vector<int>> &heights, vector<vector<bool>> &check, int i,
                int j, int maxHeight, int dir) {
            if (dir == 1) {
                if (j >= heights[i].size())
                    return;
                if( heights[i][j] >= maxHeight)
                    check[i][j] = true;
                dfs(heights, check, i, j + 1, max(heights[i][j], maxHeight), 1);
                return;
            }

            if (dir == -1) {
                if (j < 0)
                    return;
                if(heights[i][j] >= maxHeight)
                    check[i][j] = true;
                dfs(heights, check, i, j - 1, max(heights[i][j], maxHeight), -1);
                return;
            }

            if (dir == 2) {
                if(i < 0)
                    return;
                if(heights[i][j] >= maxHeight)
                    check[i][j] = true;
                dfs(heights, check, i - 1, j, max(heights[i][j], maxHeight), 2);
                return;
            }

            if (dir == -2) {
                if(i >= heights.size())
                    return;
                if(heights[i][j] >= maxHeight)
                    check[i][j] = true;
                dfs(heights, check, i + 1, j, max(heights[i][j], maxHeight), -2);
                return;
            }
        }

        static vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
            if(!heights.size() || !heights[0].size()) {
                return heights;
            }
            int ROWS = heights.size();
            int COLS = heights[0].size();
            vector<vector<bool>> pcf(ROWS);
            vector<vector<bool>> atl(ROWS);
            for (int i = 0; i < ROWS; i++) {
                pcf[i] = vector<bool>(COLS);
                atl[i] = vector<bool>(COLS);
                for (int j = 0; j < COLS; j++) {
                    pcf[i][j] = false;
                    atl[i][j] = false;
                }
            }
            for (int i = 0; i < heights.size(); i++) {
                // direction right
                dfs(heights, pcf, i, 0, heights[i][0], 1);
            }
            for (int j = 0; j < heights[0].size(); j++) {
                // direction down
                dfs(heights, pcf, 0, j, heights[0][j], -2);
            }
            for (int i = 0; i < heights.size(); i++) {
                // direction left
                dfs(heights, atl, i, heights[i].size() - 1,
                        heights[i][heights[i].size() - 1], -1);
            }
            for (int j = 0; j < heights[0].size(); j++) {
                // directon up
                dfs(heights, atl, heights.size() - 1, j, heights[heights.size() - 1][j], 2);
            }
            cout << "----" << endl;
            for(auto row : pcf) {
                for(auto cell : row) {
                    cout << cell << " ";
                }
                cout << endl;
            }
            cout << "---------" << endl;
            for(auto row : atl) {
                for(auto cell : row) {
                    cout << cell << " ";
                }
                cout << endl;
            }
            vector<vector<int>> result;
            for(int i = 0; i < heights.size(); i++) {
                for(int j = 0; j < heights[i].size(); j++) {
                    if(pcf[i][j] && atl[i][j]) {
                        cout << "(" << i << "," << j << ")" << " ";
                        vector<int>cell{i, j};
                        result.push_back(cell);
                    }
                    else {
                        cout << "x" << " ";
                    }
                }
                cout << endl;
            }
            return result;
        }
};

        //{1, 2,2,3,5},
        //    {3,2, 3, 4 ,4},
        //    {2,4,5,3,1},
        //    {6,7,1,4,5},
        //    {5,1,1,2,4}
int main (int argc, char *argv[]) {

    vector<vector<int>>heights {
        {1}
    };
    vector<vector<int>> res = Solution::pacificAtlantic(heights);
    for(auto row : res) {
        for(auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}

