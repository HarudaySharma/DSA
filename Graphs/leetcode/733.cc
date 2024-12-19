#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int pxlColor = image[sr][sc];

        auto DFS = [&](int i, int j, auto &&DFS) {
            if(i < 0 || i >= m || j < 0 || j >= n) {
                return;
            }
            if(image[i][j] == color || image[i][j] != pxlColor){
                return;
            }

            image[i][j] = color;

            DFS(i - 1, j, DFS);
            DFS(i, j + 1, DFS);
            DFS(i + 1, j, DFS);
            DFS(i, j - 1, DFS);

        };
        DFS(sr, sc, DFS);

        return image;
    }
};

