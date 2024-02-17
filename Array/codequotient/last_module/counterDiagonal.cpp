#include<bits/stdc++.h>
using namespace std;
/*     
 * Complete the 'counterDiagonal' function below.
 * Print the counter diagonal traversal of the matrix, seperated by space
 * @params
 *   mat -> square matrix of size (n x n) 
 *   n -> integer denoting size of square matrix
 */
#define N 10

/*
 * N * N
 * i j
 * 00 01 02
 * 10 11 12
 * 20 21 22
 * i++ < N
 * j-- >= 0
 *
 */
void display(int mat[N][N], int i, int j) {
        int x = i, y = j;
        while(x <= j && y >= i) {
            cout << mat[x][y] << " ";
            x++, y--;
        }

}
void counterDiagonal(int mat[N][N], int n) {
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            for(int j = 0; j < n; j++) {
                display(mat, i, j);
            }
            continue;
        }
        display(mat, i, n - 1);
    }
}
