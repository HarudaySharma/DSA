#include "bits/stdc++.h"
#include <iostream>

void solve(long long* arr, int n) {
    
    long long res = arr[0] + arr[1] + 1 - 2;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            long long sum = arr[i] + arr[j] + j + 1 - (i + 1) ;
            if(sum < res)
                res = sum;
        }
    }
    std::cout << res << "\n";
}

int main (int argc, char *argv[]) {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        long long *arr  = new long long[n];
        for(int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        solve(arr, n) ;
        delete [] arr;
    }
        
    

    return 0;
}
