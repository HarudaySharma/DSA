#include "bits/stdc++.h"
#include <stack>

using namespace std;
class Solution {
public:
  bool isValid(string s) {
    std::stack<int> stk;
    for (auto ch : s) {
      if (stk.empty() && (ch == ')' || ch == '}' || ch == ']'))
        return false;
      if ((ch == '(' || ch == '{' || ch == '[')) {
          stk.push(ch);
          continue;
      }
      switch (ch) {
          case ')':
              if(stk.top() == '(') {
                  stk.pop();
              }
              else {
                  return false;
              }
              break;
          case '}':
              if(stk.top() == '{') {
                  stk.pop();
              }
              else {
                  return false;
              }
              break;
          case ']':
              if(stk.top() == '[') {
                  stk.pop();
              }
              else {
                  return false;
              }
              break;
          default: 
              stk.push(ch);
      }
    }
    return stk.empty() ? true : false;
  }
};
