#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // space: O(n);
    // time: O(n^2);
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        // store cols and traverse on cols
        map<vector<int>, int> cols;

        for(int j = 0; j < n; j++) {
            vector<int> col;
            for(int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }
            cols[col] += 1;
        }

        int pairsCount = 0;
        for(auto row : grid) {
            if(cols.count(row))
                pairsCount += cols[row];
        }

        return pairsCount;
    }
};

