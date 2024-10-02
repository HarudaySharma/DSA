#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            // adjList {string, numerors...}
            int n = equations.size();
            map<string, vector<pair<string, double>>> adjList;
            for(int i = 0; i < n; i++) {
                // a -> {b. 0}, c
                string numer = equations[i][0];
                string denom = equations[i][1];
                double val = values[i];

                pair<string, double> pr(denom, val);
                // a / b = 2
                adjList[numer].push_back(pr);
                // b / a = 1 / 2
                pair<string, double> pr2(numer, 1 / val);
                adjList[denom].push_back(pr2);
            }

            auto dfs = [&](string numer, string denom, unordered_set<string> &visited, auto &&dfs) -> double {
                // x/ y
                // check all the denoms of the curr node
                if(!adjList.count(numer) || !adjList.count(denom)) {
                    return -1.0;
                }
                if(numer == denom) {
                    return 1.0;
                }

                vector<double> answers;
                for(auto pr : adjList[numer]) {
                    string d = pr.first;
                    auto val = pr.second;

                    if(d == denom) {
                        return val;
                    }

                    if(visited.count(d)) {
                        continue;
                    }

                    visited.insert(d);
                    double ret = dfs(d, denom, visited, dfs);
                    if(ret != -1) {
                        if(!answers.empty())
                            return -1.0;
                        answers.push_back(val * ret);
                    }
                }

                return answers.empty() ? -1 : answers[0];
            };

            vector<double> res;
            for(auto query : queries) {
                // x / y
                string numer = query[0];
                string denom = query[1];
                unordered_set<string> us;
                res.push_back(dfs(numer, denom, us, dfs));
            }

            return res;
        }
};

