#include <bits/stdc++.h>
using namespace std;
/* 
 * https://codeforces.com/problemset/problem/1512/A
 */

int main (int argc, char *argv[]) {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int n1 = -1, n2 = -1;
        int i1 = -1, i2 = -1;
        int ans = -1;
        int i = 1;
        while(i <= n) {
            int x;
            cin >> x;
            if(ans == -1) {
                if(n1 != -1) {
                    if(n2 == -1 && x != n1) {
                        n2 = x;
                        i2 = i;
                    }
                    else {
                        if(n2 != -1) {
                            ans = x == n2 ? i1 : i2;
                        }
                    }
                }
                else {
                    n1 = x;
                    i1 = i;
                }
            }
            i++;
        }
        ans = ans == -1 ? i - 1 : ans;
        cout << ans << endl;
    }
    return 0;
}
