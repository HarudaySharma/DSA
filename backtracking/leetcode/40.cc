#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void rec(vector<int> &candidates, int i, int target, vector<int> ans) {
        if(target == 0) {
            res.push_back(ans);
            return;
        }
        if(i >= candidates.size() || target < 0) {
            return;
        }
        // using the curr element to reach the target
        ans.push_back(candidates[i]);
        rec(candidates, i + 1, target - ans.back(), ans);
        // not using the curr element
        // ignoring the dups so to eleminate duplicate combinations
        ans.pop_back();
        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
            i++;
        rec(candidates, i + 1, target, ans);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        rec(candidates, 0, target, {});
        return res;
    }
};

