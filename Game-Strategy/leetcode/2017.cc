#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // right or down
        int m = grid[0].size();

        vector<long long> firstRow;
        long long firstRowSum = 0;
        for(int j = 0; j < m; j++) {
            firstRowSum += grid[0][j];
            firstRow.push_back(firstRowSum);
        }

        vector<long long> secondRow;
        long long secondRowSum = 0;
        for(int j = 0; j < m; j++) {
            secondRowSum += grid[1][j];
            secondRow.push_back(secondRowSum);
        }

        long long pointCollectedBySecond = LONG_LONG_MAX;
        for(int j = 0; j < m; j++) {
            // if the player one went downwards from this cell.
            long long row1PointsLeft = firstRowSum - firstRow[j]; // for player2
            long long row2PointsLeft = secondRow[j] - grid[1][j]; // for player2

            long long pointTakenBy2 = max(row1PointsLeft, row2PointsLeft); // player2 will try to get as many points as possible
            pointCollectedBySecond = min(pointCollectedBySecond, pointTakenBy2); // as player1 will choose the path such that the points for player2 will be minimum.
        }

        return pointCollectedBySecond;
    }
};

