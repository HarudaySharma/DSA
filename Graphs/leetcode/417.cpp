#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    public:
        set<pair<int, int>> valid;
        vector<vector<int>> marked;
        bool toAtlantic(int i, int j, int n, int m, int prevVal,
                vector<vector<int>> &heights) {
            if (i < 0 || j < 0)
                return false;
            if (i >= n || j >= m)
                return true;
            if (prevVal < heights[i][j])
                return false;
            if (marked[i][j])
                return false;
            if (valid.count({i, j}))
                return true;
            marked[i][j] = true;
            int res = (toAtlantic(i + 1, j, n, m, heights[i][j], heights) ||
                    toAtlantic(i, j + 1, n, m, heights[i][j], heights)) ||
                toAtlantic(i - 1, j, n, m, heights[i][j], heights) ||
                toAtlantic(i, j - 1, n, m, heights[i][j], heights);
            marked[i][j] = false;
            return res;
        }

        bool toPacific(int i, int j, int n, int m, int prevVal,
                vector<vector<int>> &heights) {
            if (i < 0 || j < 0)
                return true;
            if (i >= n || j >= m)
                return false;
            if (prevVal < heights[i][j])
                return false;
            if (marked[i][j])
                return false;
            if (valid.count({i, j}))
                return true;
            marked[i][j] = true;
            bool res = (toPacific(i + 1, j, n, m, heights[i][j], heights) ||
                    toPacific(i, j + 1, n, m, heights[i][j], heights)) ||
                toPacific(i - 1, j, n, m, heights[i][j], heights) ||
                toPacific(i, j - 1, n, m, heights[i][j], heights);
            marked[i][j] = false;
            return res;
        }

        vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
            int n = heights.size();
            int m = heights[0].size();
            vector<vector<int>> res;
            marked.resize(n, vector<int>(m, false));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (toAtlantic(i, j, n, m, INT_MAX, heights) &&
                            toPacific(i, j, n, m, INT_MAX, heights)) {
                        res.push_back({i, j});
                        valid.insert({i, j});
                    }
                }
            }
            return res;
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

