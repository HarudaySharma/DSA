#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> rowsPaint(n, 0);
        vector<int> colsPaint(m, 0);

        // finding the number in the mat
        // cache the location of numbers as a hashmap
        map<int, pair<int, int>> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int num = mat[i][j];
                mp[num] = {i, j};
            }
        }

        for(int x = 0; x < arr.size(); x++) {
            int num = arr[x];
            auto [i, j] = mp[num];
            rowsPaint[i] += 1;
            colsPaint[j] += 1;
            if(rowsPaint[i] >= m) {
                return x;
            }
            if(colsPaint[j] >= n) {
                return x;
            }
        }

        return -1;
    }
};

