#include "bits/stdc++.h"
#include <set>
using namespace std;

vector<int> divisors;
void findDivisors(int n) {
    set<int>divs;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divs.insert(i);
            if( i * i != n)
            divs.insert(n / i);
        }
    }
    for(auto el : divs) 
        divisors.push_back(el);
}

bool checkForD(int d, int n) {
    for(int i = 0; i < divisors.size() - 1; i++) {
        if(divisors[i + 1] - divisors[i] < d)
            return false;
    }
    return true;
}

int differentDivisors(int d) {
    int n = 6;
    while (1) {
        findDivisors(n);
        if(divisors.size() >= 4) {
            if(checkForD(d, n)) {
                divisors.clear();
                return n;
            }
        }
        divisors.clear();
        n++;
    }
}

int main (int argc, char *argv[]) {
    int t;
    cin >> t;
    while(t--) {
        int d;
        cin >> d;
        cout << differentDivisors(d) << endl;
    }
    return 0;
}
