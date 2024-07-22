#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (auto asteroid : asteroids) {
            if (asteroid < 0) {
                bool pushAsteroid = true;
                while (!st.empty() && st.top() > 0) {
                    int diff = abs(asteroid) - st.top();
                    if(diff > 0){
                        if(st.size() == 1) {
                            st.pop();
                            break;
                        }
                    }
                    else if(diff == 0) {
                        st.pop();
                        pushAsteroid = false;
                        break;
                    }
                    else if(diff < 0) {
                        pushAsteroid = false;
                        break;
                    }
                    st.pop();
                }
                if(pushAsteroid)
                    st.push(asteroid);
            }
            else {
                st.push(asteroid);
            }
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};


