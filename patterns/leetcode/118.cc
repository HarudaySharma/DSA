#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> generateRow(int n) {
        // n => rowNo.
        vector<int> row;
        row.push_back(1);
        long long res = 1;
        for(int i = 1; i < n; i++) {
            // i => col
            // prevRes * (rowNo - col) / col
            res *= (n - i);
            res /= i;
            row.push_back(res);
        }

        return row;
    }
    int get_nCr(int n, int r) {
        long long res = 1;
        for(int i = 0; i < r; i++) {
            // NcR => {n*(n - 1)*(n - 2)...(n - (r - 1))} / {1*2*3...r}
            res *= (n - i);
            res /= (i + 1);
        }

        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 1; i <= numRows; i++) {
            res.push_back(generateRow(i));
        }

        // to get a particular cell of the pascal's triangle
        // (r - 1) C (c - 1)
        // cout << get_nCr(5 - 1, 3 - 1) << endl; // 6th row 3rd col => 6

        return res;
    }
};

