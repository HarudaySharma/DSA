#include <bits/stdc++.h>
using namespace std;

#define string_pair pair<string, string>

class Solution {
    public:
        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            int n = equations.size();
            map<pair<string, string>, double> mp;

            for(int i = 0; i < n; i++) {
                string_pair pr = {equations[i][0], equations[i][1]};
                string_pair revPr = {equations[i][1], equations[i][0]};
                mp[pr] = values[i];
                mp[revPr] = 1 / values[i];
            }

            vector<double> res;
            for(auto query : queries) {
                // check for the exact query
                string numer = query[0];
                string denom = query[1];
                if(mp.count({numer, denom})) {
                    res.push_back(mp[{numer, denom}]);
                    continue;
                }
 
                bool found = false;
                for(auto pr : mp) {
                    auto prNume = pr.first.first;
                    auto prDenom = pr.first.second;
                    auto val = pr.second;
                    if(prNume == numer) {
                        if(mp.count({prDenom, denom})) {
                            auto v = mp[{prDenom, denom}];
                            res.push_back(v * val);
                            found = true;
                            break;
                        }
                    }
                }

                if(!found) {
                    res.push_back(-1.000f);
                }
            }

            return res;
        }
};

