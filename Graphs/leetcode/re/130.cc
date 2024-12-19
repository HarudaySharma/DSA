#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<char>> dummyBoard(n, vector<char>(m, 'X'));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        auto BFS = [&](int i, int j) {
            queue<pair<int, int>> q;

            q.push({i, j});
            while(!q.empty()) {
                int size = q.size();
                while(size--) {
                    auto [i, j] = q.front();
                    q.pop();

                    if(i >= n || i < 0 || j >= m || j < 0) {
                        continue;
                    }
                    if(visited[i][j]) {
                        continue;
                    }
                    if(board[i][j] != 'O') {
                        continue;
                    }

                    visited[i][j] = true;
                    dummyBoard[i][j] = 'O';

                    q.push({i + 1, j});
                    q.push({i - 1, j});
                    q.push({i, j + 1});
                    q.push({i, j - 1});
                }
            }
        };

        // check the boundary cells only
        for(int i = 0; i < n; i++) {
            // top down left
            if(board[i][0] == 'O') {
                BFS(i, 0);
            }
            // top down right
            if(board[i][m - 1] == 'O') {
                BFS(i, m - 1);
            }
        }
        for(int j = 0; j < m; j++) {
            // left to right top
            if(board[0][j] == 'O') {
                BFS(0, j);
            }
            // left right bottom
            if(board[n - 1][j] == 'O') {
                BFS(n - 1, j);
            }
        }

        // modify the board
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board[i][j] = dummyBoard[i][j];
            }
        }

    }
};

