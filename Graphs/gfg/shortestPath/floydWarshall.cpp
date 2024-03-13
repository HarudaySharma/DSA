#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
    public:
        void shortest_distance(vector<vector<int>> &matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++) {
                    if(matrix[i][j] == -1)
                        matrix[i][j] = INT_MAX;
                    if (i == j)
                        matrix[i][j] = 0;
                }
            }

            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                            continue;
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == INT_MAX)
                        matrix[i][j] = -1;
                }
            }
        }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortest_distance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
