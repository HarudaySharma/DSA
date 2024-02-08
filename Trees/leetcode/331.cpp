#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
    public:
        //capacity of tree 
        //initially = 1(root)
        //with occurence of each node (node or null)
        //capacity decreases by 1
        //as a new non null node enters => capacity 
        //  increases by 2 (left and right node)
        bool isValidSerialization(string preorder) {
            int capacity = 1;
            for (int i = 0; i < preorder.size(); i++) {
                if (preorder[i] == ',')
                    continue;
                capacity--;
                if (preorder[i] != '#') {
                    capacity += 2;
                    while (preorder[i] != ',' && i < preorder.size())
                        i++;
                }
                if(capacity < 0) {
                    return false;
                }
            }
            return capacity == 0;
        }
};
