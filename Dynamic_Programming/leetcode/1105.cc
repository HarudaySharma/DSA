#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int approach1(vector<vector<int>>& books, int shelfWidth) {
        // ## states of problem
        // - shelfWidth
        // - books left
        // ## boundary: no more books(return height), width less(height + 1)
        // ## cases:
        // 1. put the book on the shelf
        // 2. don't put the book on the shelf

        map<pair<int ,int>, int> dp;

        auto rec = [&](int idx, int shelfHeight, int width, auto &&rec) -> int {
            if(idx >= books.size())
                return shelfHeight;

            if(dp.count({idx, width}))
                return dp[{idx, width}];

            // put in the curr shelf
            int h = INT_MAX;
            if(books[idx][0] <= width) {
                h = rec(idx + 1, max(shelfHeight, books[idx][1]), width - books[idx][0], rec);
            }
            // put on the next shelf
            h = min(h, shelfHeight + rec(idx + 1, books[idx][1], shelfWidth - books[idx][0], rec));

            return dp[{idx, width}] = h;
        };

        return rec(0, 0, shelfWidth, rec);
    }

    int approach2(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size(), INT_MAX);

        auto rec = [&](int i, auto &&rec) -> int {
            if(i >= books.size())
                return 0;

            if(dp[i] != INT_MAX)
                return dp[i];

            int maxHeight = 0;
            int currWidth = shelfWidth;
            for(int j = i; j < books.size(); j++) {
                int bookWidth = books[j][0];
                int bookHeight = books[j][1];

                if(currWidth - bookWidth < 0)
                    break;

                currWidth -= bookWidth;
                maxHeight = max(maxHeight, bookHeight);

                // put the next book in other shelf
                dp[i] = min(
                        dp[i],
                        rec(j + 1, rec) + maxHeight
                        );
            }

            return dp[i];
        };

        return rec(0, rec);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        //approach1(books, shelfWidth);
        return approach2(books, shelfWidth);
    }
};

