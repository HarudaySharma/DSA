#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> queens;
    vector<vector<string>> res;


    vector<string> buildBoard(int n) {
        vector<string> res;
        for(int i = 0; i < n; i++) {
            string row(n, '.');
            row[queens[i]] = 'Q';
            res.push_back(row);
        }
        return res;
    }

    bool check(int col, int row) {
        for(int i = 0; i < row; i++) {
            int prow = i;
            int pcol = queens[i];
            if(pcol == col || /*if slope == 1 => same diognal*/ abs(row - prow) == abs(col - pcol)) {
                return false;
            }
        }
        return true;
    }

    void rec(int i, int n) {
        if(i == n) {
            res.push_back(buildBoard(n));
            return;
        }

        for(int x = 0; x < n; x++) {
            if(check(x, i)) {
                queens[i] = x;
                rec(i + 1, n);
                queens[i] = -1;
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        queens.resize(n, -1);
        rec(0, n);
        return res;
    }
};
