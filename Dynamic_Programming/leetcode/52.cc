#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> queens;

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

    int rec(int i, int n) {
        if(i == n) {
            return 1;
        }

        int ans = 0;
        for(int x = 0; x < n; x++) {
            if(check(x, i)) {
                queens[i] = x;
                ans += rec(i + 1, n);
                queens[i] = -1;
            }
        }
        return ans;
    }

    int totalNQueens(int n) {
        queens.resize(n, -1);
        return rec(0, n);
    }
};

