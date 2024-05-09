#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<bool>> marked;
    void rec(int i, int j, vector<vector<char>>& board, int n, int m) {
        if(i < 0 || j < 0 || j >= m || i >= n || marked[i][j] || board[i][j] == 'X') {
            return;
        }
        marked[i][j] = true;
        rec(i + 1, j, board, n, m);
        rec(i, j + 1, board, n, m);
        rec(i - 1, j, board, n, m);
        rec(i, j - 1, board, n, m);
    }

    void callDFS(vector<vector<char>>& board, int n, int m){
        // first Row
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O')
                rec(0, j, board, n, m);
        }
        // first Col
        for(int i = 1; i < n; i++){
            if(board[i][0] == 'O')
                rec(i, 0, board, n, m);
        }
        // last Row
        for(int j = 1; j < m; j++){
            if(board[n - 1][j] == 'O')
                rec(n - 1, j, board, n, m);
        }
        //last Col
        for(int i = 1; i < n; i++){
            if(board[i][m - 1] == 'O')
                rec(i, m - 1, board, n, m);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        marked.resize(n, vector<bool>(m, false));
        callDFS(board, n, m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!marked[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};

