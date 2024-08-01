#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoizationSol(vector<int> &rating) {
        map<pair<int, pair<bool, int>>, int> dp;

        auto rec = [&](int i, int isAscend, int count, auto &&rec) -> int {
            if(dp.count({i, {isAscend, count}}))
                return dp[{i, {isAscend, count}}];
            if(count == 3)
                return 1;
            if(i >= rating.size())
                return 0;

            int teams = 0;
            for(int j = i + 1; j < rating.size(); j++) {
                if(isAscend && (rating[j] > rating[i]))
                    teams += rec(j, isAscend, count + 1, rec);
                if(!isAscend && (rating[j] < rating[i]))
                    teams += rec(j, isAscend, count + 1, rec);
            }

            return dp[{i, {isAscend, count}}] = teams;
        };

        int teams = 0;
        for(int i = 0; i < rating.size(); i++)
            teams += rec(i, true, 1, rec) + rec(i, false, 1, rec);

        return teams;
    }

    int numTeams(vector<int>& rating) {

        // dp Solution
        return memoizationSol(rating);

        // greedy Solution
        int teams = 0;

        for(int mid = 1; mid < rating.size() - 1; mid++) {
            int leftAsc = 0;
            int rightAsc = 0;
            
            for(int i = 0; i < mid; i++)
                if(rating[i] < rating[mid])
                    leftAsc += 1;
            for(int i = mid + 1; i < rating.size(); i++)
                if(rating[i] > rating[mid])
                    rightAsc += 1;

            int leftDesc = mid - leftAsc;
            int rightDesc = rating.size() - mid - rightAsc - 1;

            teams += (leftAsc * rightAsc); // count ascending
            teams += (leftDesc * rightDesc); // count descending        
        }

        return teams;
    }
};

