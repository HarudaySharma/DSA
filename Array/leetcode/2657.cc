#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // TC: O(n^2)
    // SC: 0(n^2)
    vector<int> method2(vector<int>& A, vector<int>& B) {
        // given 1 <= n <= 50 and no dups in an array
        // construct freq array at each index;
        int size = A.size();
        vector<int> res(size);
        vector<int> freq(size + 1, 0); // freq[num] = freq count;
        vector<vector<int>> idxFreqArr(size + 1, vector<int>(size + 1, 0)); // v[idx] = freqArr till that idx
        for(int i = 0; i < size; i++) {
            int aVal = A[i];
            int bVal = B[i];
            freq[aVal] += 1;
            freq[bVal] += 1;
            idxFreqArr[i] = freq;
        }

        for(int i = 0; i < size; i++) {
            auto row = idxFreqArr[i];
            int commonCount = 0;

            for(int num = 0; num < row.size(); num++) {
                int count = row[num];

                if(count % 2 == 0) {
                    commonCount += (count / 2);
                }
            }

            res[i] = commonCount;
        }

        return res;
    }

    // TC: O(n)
    // SC: 0(n) // {1 <= n <= 50}
    vector<int> method1(vector<int>& A, vector<int>& B) {

        // given 1 <= n <= 50 and no dups in an array
        // therefore if count of a number gets to 2 at some point that means
        // number must be common in both arrays
        int size = A.size();
        vector<int> res(size);
        map<int, int> mp;
        int count = 0;

        for(int i = 0; i < size; i++) {
            mp[A[i]] += 1;
            if(mp[A[i]] == 2) {
                count += 1;
            }
            mp[B[i]] += 1;
            if(mp[B[i]] == 2) {
                count += 1;
            }

            res[i] = count;
        }

        return res;
    }

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        return method1(A, B);
    }
};

