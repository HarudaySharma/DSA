#include <bits/stdc++.h>
using namespace std;
 
int divisors(int n) {
    int res = 0;
    for(int i = 1; i * i <= n; i += 1) {
        if(n % i == 0) {
            if(i % 2 == 0)
                res++;
            // if i divides n => n / i also divides n 
            // if n / i => even => count++
            if((n/i) % 2 == 0 && n/i != i)
                res++;
        }
    }
    return res;
}

int main (int argc, char *argv[]) {
    return 0;
}
