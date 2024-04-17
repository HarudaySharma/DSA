#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    private:
        // valid? : <bool, {int,int}>;
        vector<vector<bool>> visited;
        int delx[4]{-1, 0, 1, 0};
        int dely[4]{0, 1, 0, -1};
        bool helper(int i, int j, int x, vector<vector<char>> &board, string &word, int n, int m) {
            if (x >= word.size())
                return true;
            visited[i][j] = true;
            for(int a = 0; a < 4; a++) {
                int e = i + delx[a];
                int f = j + dely[a];
                if((e < n && e >= 0) && (f >= 0 && f < m) && !visited[e][f] && board[e][f] == word[x]) {
                    if(helper(e, f, x + 1, board, word, n, m)) {
                        return true;
                    }
                }
            }
            visited[i][j] = false;
            return false;
        }

    public:
        bool exist(vector<vector<char>> &board, string word) {
            int n = board.size();
            int m = board[0].size();
            visited.resize(n, vector<bool>(m, false));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == word.front()) {
                        if (helper(i, j, 1, board, word, n, m))
                            return true;
                    }
                }
            }
            return false;
        }
};
