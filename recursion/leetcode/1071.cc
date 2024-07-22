#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string comp = str1.length() < str2.length() ? str1 : str2;
        string gcd;

        auto rec = [&](int i, string target, auto &&rec) -> void {
            if(str1.find(target) != std::string::npos 
                    && str2.find(target) != std::string::npos) {
                if(gcd.length() < target.length()) {
                    gcd = target;
                }
            }
            rec(i + 1, target, rec);
            target.push_back(comp[i]);
            rec(i + 1, target, rec);
        };
        rec(0, "", rec);

        return gcd;
    }
};

