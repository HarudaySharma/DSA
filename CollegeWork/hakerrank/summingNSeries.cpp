#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main (int argc, char *argv[]) {
    int t;
    cin >> t;
    while(t--) {
        long n;
        cin >> n;
        // in order to low the value of n so that
        // it doesn't go out of range of the mod;
        // and therefore prevent arithmetic overflow
        n %= mod;
        cout << (n * n) % mod << endl;
    }


    return 0;
}
