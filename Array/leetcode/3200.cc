#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {

        auto rec = [&](int row, int red, int blue, bool redTurn, auto &&rec) {
            if(redTurn) {
                if(red - (row + 1) < 0) {
                    return row;
                }
                red -= (row + 1);
            }
            if(!redTurn) {
                if (blue - (row + 1) < 0) {
                    return row;
                }
                blue -= (row + 1);
            }

             return rec(row + 1, red, blue, !redTurn, rec);
        };

        return max(rec(0, red, blue, true, rec),
                rec(0, red, blue, false, rec));

    }
};


