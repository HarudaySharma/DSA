#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
using namespace std;

string palindrome(unordered_map<char, int>chars){
    string str;
    string str2;
    pair<char, int> mid;
    bool midFound = false;
    for(auto el : chars) {
        if(el.second % 2 != 0) {
            if(!midFound){
                midFound = true;
                mid.first = el.first;
                mid.second = el.second;
            }
            else {
                return "NO SOLUTION";
            }
        }
        else {
            int n = el.second / 2;
            for(int i = 1; i <= n; i++) {
                str += el.first;
                str2 += el.first;
            }
        }
    }
    if(midFound) {
        for(int i = 1; i <= mid.second; i++)
            str += mid.first;
    }
    while(!str2.empty()) {
        str += str2.back();
        str2.pop_back();
    }
    return str;
}

int main (int argc, char *argv[]) {
    unordered_map<char, int>chars;
    string str;
    cin >> str;
    while(!str.empty()) {
        char x = str.back();
        str.pop_back();
        if(chars.count(x)) {
            chars[x] += 1;
        }
        else {
            chars.insert({x, 1});
        }
    }
    cout << palindrome(chars);
    return 0;
}
