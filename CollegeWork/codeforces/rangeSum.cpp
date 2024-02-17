#include <bits/stdc++.h>
using namespace std;
/*
 * https://codeforces.com/group/MWSDmqGsZm/contest/326907/problem/D
 */
long long rangeSum(long long l, long long r) {
    
    long long rSum = (r + 1) * r / 2 ;
    long long lSum = (l - 1) * (l)/ 2;
    return rSum - lSum;
}

int main (int argc, char *argv[]) {
    int t;
    cin >> t;
    while(t--) {
        long long l, r;
        cin >> l >> r;
        cout << rangeSum(min(l, r), max(l, r)) << endl;
    }


    return 0;
}
