#include <bits/stdc++.h> #include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool helper(int curr, int jump, int &target, set<int> &st, unordered_map<int, unordered_set<int>> &mp) {
        if(curr == target) return true;
        if(!st.count(curr)) return false;

        if(!mp.count(curr))
            mp.insert({curr, unordered_set<int>()});
        bool res;
        if(jump - 1 > 0) {
            if(!mp[curr].count(jump - 1)) {
                res = helper(curr + jump - 1, jump - 1, target, st, mp);
                if(res) return true;
                mp[curr].insert(jump - 1);
            }
        }
        if(jump > 0) {
            if(!mp[curr].count(jump)) {
                res = helper(curr + jump, jump, target, st, mp);
                if(res) return true;
                mp[curr].insert(jump);
            }
        }
        if(!mp[curr].count(jump + 1)) {
            res = helper(curr + jump + 1, jump + 1, target, st, mp);
            if(res) return true;
            mp[curr].insert(jump + 1);
        }
        return false;
    }
    bool canCross(vector<int>& stones) {
        set<int> st(stones.begin(), stones.end());
        // stone, <invalid jumps>
        unordered_map<int, unordered_set<int>> mp;
        return helper(stones.front(), 0, stones.back(), st, mp);
    }
};
