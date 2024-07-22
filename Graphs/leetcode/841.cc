#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        int visitedCount = 0;

        auto rec = [&](int roomIdx, auto &&rec) {
            if(visited[roomIdx])
                return;

            visited[roomIdx] = true;
            visitedCount += 1;
            for(auto idx : rooms[roomIdx]) {
                rec(idx, rec);
            }
        };
        rec(0, rec);

        return visitedCount == rooms.size();
    }
};

