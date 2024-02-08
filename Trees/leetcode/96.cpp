#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        static long long T(int n, unordered_map<int, int> **hash) {
            if (n == 1 || n == 0)
                return 1;
            int sum = 0;
            for (int i = n; i >= 1; i--) {
                auto it = (*hash)->find(i - 1);
                int t1;
                if(it != (*hash)->end())
                    t1 = it->second;
                else {
                    t1 = T(i - 1, hash);
                    (*hash)->insert({i - 1, t1});
                }
                it = (*hash)->find(n - i);
                int t2;

                if(it != (*hash)->end())
                    t2 = it->second;
                else {
                    t2 = T(i - 1, hash);
                    (*hash)->insert({i - 1, t2});
                }
                sum += t1 * t2;
            }
            return sum;
        }
        static long long numTrees(int n) {
            unordered_map<int, int> *hash = new unordered_map<int, int>;
            return T(n, &hash);
        }
};

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    cout << Solution::numTrees(n);
    return 0;
}
