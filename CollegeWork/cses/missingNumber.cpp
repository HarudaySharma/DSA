#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
    long long n;
    cin >> n;
    long long sum = 0;
    for(int i = 1; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
    }
    cout << (n*(n + 1) / 2 - sum);
    return 0;
}
