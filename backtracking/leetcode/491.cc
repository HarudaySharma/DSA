#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    set<vector<int>> seqSet;

    void rec(int i, vector<int> &nums, vector<int> &seq, vector<vector<int>> &res) {
        if(i >= nums.size()) {
            if(seq.size() <= 1 || seqSet.count(seq))
                return;
            seqSet.insert(seq);
            res.push_back(seq);

            return;
        }

        rec(i + 1, nums, seq, res);
        if(seq.empty() || seq.back() <= nums[i]) {
            seq.push_back(nums[i]);
            rec(i + 1, nums, seq, res);
            seq.pop_back();
        }

        return;
    }


    // FIX: Not working
    void optimalApp(int i, vector<int> &nums, vector<int> &seq, vector<vector<int>> &res) {
        if(seq.size() >= 2) {
            res.push_back(seq);
        }

        unordered_set<int> st;

        while(i < nums.size()) {
            if(seq.empty() || nums[i] >= seq.back() && !st.count(nums[i])) {
                seq.push_back(nums[i]);
                optimalApp(i + 1, nums, seq, res);
                seq.pop_back();

                // don't call for the same number more than one time
                st.insert(nums[i]);
            }
            i++;
        }

        return;

    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // find non decreasing Subsequences
        vector<int> seq;
        vector<vector<int>> res;

        // optimalApp(0, nums, seq, res);
        //
        // return res;
        rec(0, nums, seq, res);

        return res;
    }
};


