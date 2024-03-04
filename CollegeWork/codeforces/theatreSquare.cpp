#include <bits/stdc++.h>
using namespace std;
/*
 * https://codeforces.com/group/MWSDmqGsZm/contest/326907/problem/D
 */
long long findMinSquaresReq(long long n,long long m, long long a) {
    long long i = 1;
    long long squaresArea = 0;
    while(1) {
        squaresArea = a * a * i;
        if(squaresArea >= n * m) {
            break;
        }
        i++;
    }
    return squaresArea == n * m ? i : i % 2 == 0 ? i : i + 1;
}

int main (int argc, char *argv[]) {
    long long  n, m, a;
    cin >> n >> m >> a;
    cout << findMinSquaresReq(n, m, a);


    return 0;
}
