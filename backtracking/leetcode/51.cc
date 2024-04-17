#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    private:
        vector<int> positions;
        vector<vector<string>> validPositions;

        void buildBoard(vector<int> &positions) {
            int n = positions.size();
            vector<string> rows(n, string(n, '.'));
            int i = 0;
            for(auto x : positions) {
                rows[i][x] = 'Q';
                i++;
            }
            validPositions.push_back(rows);
            return;
        }

        bool canPlace(int row, int col, int n) {
            for(int i = 0; i < row; i++) {
                // checking same col;
                if(positions[i] == col)
                    return false;
                // checking diognals
                if(abs(row - i) == abs(col - positions[i]))
                    return false;
            }
            return true;
        }

    public:

        void rec(int currRow, int n) {
            if(n == currRow) {
                buildBoard(positions);
                return;
            }
            for(int i = 0; i < n; i++) {
                if(canPlace(currRow, i, n)) {
                    positions[currRow] = i;
                    rec(currRow + 1, n);
                    positions[currRow] = -1;
                }
            }
            return;
        }

        vector<vector<string>> solveNQueens(int n) {
            positions.resize(n, -1);
            rec(0, n);
            return validPositions;
        }
};

