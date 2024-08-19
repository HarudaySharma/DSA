#include <bits/stdc++.h>
#include <climits>
#include <cwchar>
using namespace std;

class Solution {
public:
    // TLE
    long long approach1(vector<vector<int>> &points) {
        int n = points.size();
        int m = points[0].size();

        vector<long long> lastRow;
        for(auto cell : points[0])
            lastRow.push_back(cell);

        auto rec = [&](int i, auto &&rec) {
            if(i >= n)
                return;

            // consider each and every cell
            vector<long long> currRow;
            for(int j = 0; j < points[i].size(); j++) {
                // compare each cell with result of previous row
                long long colMax = LONG_MIN;
                for(int col = 0; col < m; col++) {
                    colMax = max(
                            colMax,
                            points[i][j] + lastRow[col]
                            - abs(col - j)
                            );
                }
                currRow.push_back(colMax);
            }
            lastRow = currRow;

            rec(i + 1, rec);
        };

        rec(1, rec);

        long long res = LONG_MIN;
        for(auto cell : lastRow) {
            res = max(res, cell);
        }

        return res;
    }

    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        
        vector<long long> prevRow;
        for(auto el : points[0]) {
            prevRow.push_back(el);
        }

        for(int i = 1; i < n; i++) {
            vector<long long> leftMax(m, 0);
            vector<long long> rightMax(m, 0);

            for(int i = 0, j = m - 1; i < m; i++, j--) {
                if(i == 0 && j == m -1) {
                    leftMax[i] = prevRow[i];
                    rightMax[j] = prevRow[j];
                    continue;
                }

                leftMax[i] = max(prevRow[i], leftMax[i - 1] - 1);
                rightMax[j] = max(prevRow[j], rightMax[j + 1] - 1);
            }

            for(int j = 0; j < m; j++) {
                prevRow[j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }
        }

        long long res = LONG_MIN;
        for(auto el : prevRow)
            res = max(res, el);

        return res;
    }
};

