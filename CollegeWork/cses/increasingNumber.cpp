#include <bits/stdc++.h>
#include <vector>
using namespace std;

long long minMoves(vector<long long> &v) {
    long long moves = 0;
    for(long long i = 1; i < v.size(); i++) {
        if(v[i] < v[i - 1]) {
            moves += v[i - 1] - v[i];
            v[i] += v[i - 1] - v[i];
        }
    }
    return moves;
}

int main (int argc, char *argv[]) {
    long long n;
    cin >> n;
    vector<long long> v;
    for(long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    cout << minMoves(v);
    return 0;
}
