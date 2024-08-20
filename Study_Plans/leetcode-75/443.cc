#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        for(auto curr = chars.begin(); curr != chars.end() ; curr++) {
            int count = 1;

            auto j = curr + 1;
            while(j != chars.end()) {
                if(*curr != *j) {
                    break;
                }
                j = chars.erase(j);
                count++;
            }

            if(count == 1) {
                continue;
            }
            
            string num = to_string(count);
            for(auto dig : num) {
                curr = chars.insert(curr + 1, dig);
            }
        }
        
        return chars.size();
    }
};



