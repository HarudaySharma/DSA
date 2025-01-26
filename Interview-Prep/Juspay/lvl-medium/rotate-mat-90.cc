#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// You are given an n x n 2D matrix representing an image,
// rotate the image by 90 degrees(clockwise).
//
// You have to rotate the image in - place, which means you have to
// modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        // steps:
        // 1. transpose
        // 2. reverse (for 90deg clockwise)

        int n = matrix.size();
        int m = matrix[0].size();

        // finding transpose
        for(int i = 0; i < n; i++) {
            for(int j = i; j < m; j++) { // upper triangle
                // swap the elements of the grip digonally
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse the matrix rows
        for(int i = 0; i < n; i++) {
            reverse(begin(matrix[i]), end(matrix[i]));
        }
    }
};
