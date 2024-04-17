#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void rec(vector<int>& candidates, int curr, vector<int> ans, int sum, int &target) {
        if(sum > target) {
            return;
        }
        sum += candidates[curr];
        ans.push_back(candidates[curr]);
        if(sum == target)  {
            res.push_back(ans);
            return;
        }
        rec(candidates, curr, ans, sum, target);
        for(int i = curr + 1; i < candidates.size(); i++)
            rec(candidates, i, ans, sum, target);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(int i = 0; i < candidates.size(); i++) {
            rec(candidates, i, {}, 0, target);
        }
        return res;
    }
};

