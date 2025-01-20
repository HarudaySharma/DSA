#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    void Reverse(stack<int> &st){
        if(st.empty()) {
            return;
        }

        int num = st.top();
        st.pop();
        Reverse(st);
        insertAtBottom(st, num);

        return;
    }

    void insertAtBottom(stack<int> &st, int &num) {
        if(st.empty()) {
            st.push(num);
            return;
        }

        int tmp = st.top();
        st.pop();
        insertAtBottom(st, num);
        st.push(tmp);

        return;

    }
};
