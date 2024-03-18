#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int top_bottom(int i, int row ,vector<vector<int>>& triangle, vector<vector<int>> &dp) {
        if(i > row || i < 0)
            return 1e9;
        if(row == triangle.size() - 1)
            return triangle[row][i];
        if(dp[row][i] != INT_MAX)
            return dp[row][i];
        int down = triangle[row][i] + top_bottom(i, row + 1, triangle, dp);
        int diognal = triangle[row][i] + top_bottom(i + 1, row + 1, triangle, dp);
        dp[row][i] = min(down, diognal);
        return dp[row][i];
    }

    int bottom_up(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        int row = triangle.size();
        for(int i = 1; i <= row; i++) {
            dp.push_back(vector<int>(i, INT_MAX));
        }
        for(int i = 0; i < row; i++) {
            dp[row - 1][i] = triangle[row - 1][i];
        }
        for(int r = row - 2; r >= 0; r--) {
            for(int j = r; j >= 0; j--) {
                int x = triangle[r][j] + dp[r + 1][j];
                int y = triangle[r][j] + dp[r + 1][j + 1];
                dp[r][j] = min(x, y);
            }
        }
        return dp[0][0];
    }
    int space_optmized(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<int> front;
        for(int i = 0; i < rows; i++)
            front.push_back(triangle[rows - 1][i]);
        for(int i = rows - 2; i >= 0; i--) {
            vector<int> curr(i, 0);
            for(int j = i; j >= 0; j--) {
                int x = triangle[i][j] + front[j];
                int y = triangle[i][j] + front[j + 1];
                curr[j] = min(x, y);
            }
            front = curr;
        }
        return front[0];
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        //vector<vector<int>> dp;
        //int row = triangle.size() - 1;
        //for(int i = 1; i <= row + 1; i++) {
        //    dp.push_back(vector<int>(i, INT_MAX));
        //}
        //return top_bottom(0, 0, triangle, dp);
        //return bottom_up(triangle);
        return space_optmized(triangle);
    }
};
