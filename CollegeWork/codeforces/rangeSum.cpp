#include <bits/stdc++.h>
using namespace std;
/*
 * https://codeforces.com/group/MWSDmqGsZm/contest/326907/problem/D
 */
long long rangeSum(long long l, long long r) {
    return ((r / 2) * (r + 1)) - ((l / 2) * (l + 1)) + 1;
}

int main (int argc, char *argv[]) {
    int t;
    cin >> t;
    while(t--) {
        long long l, r;
        cin >> l >> r;
        cout << rangeSum(l, r) << endl;
    }


    return 0;
}
