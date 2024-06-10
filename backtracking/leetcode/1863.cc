#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int subsetXORSum(vector<int> &nums) {
            int ans1 = intutiveSol(nums);
            int ans2 = optimzedSol(nums);
            if(ans1 == ans2) {
                cout << "result is the same" << endl;
                return ans1;
            }
            cout << "result mismatch" << endl;
            return -1;
        }

    private:
        int optimzedSol(vector<int> &nums) {
            int subSum = 0;

            auto rec = [&](int i, int XOR, auto &&rec) {
                if (i == nums.size()) {
                    subSum += XOR;
                    return;
                }

                rec(i + 1, XOR, rec);
                rec(i + 1, XOR ^ nums[i], rec);
                return;
            };

            rec(0, 0, rec);
            return subSum;
        }

        int intutiveSol(vector<int> &nums) {
            int subSum = 0;

            auto rec = [&](int i, vector<int> subset, auto &&rec) {
                if (i == nums.size()) {
                    int x = 0;
                    for (auto el : subset) {
                        x ^= el;
                    }
                    subSum += x;
                    return;
                }

                rec(i + 1, subset, rec);
                subset.push_back(nums[i]);
                rec(i + 1, subset, rec);
                return;
            };

            rec(0, {}, rec);
            return subSum;
        }

};

