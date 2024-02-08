#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int i, vector<int> &leftChild, vector<int> &rightChild, set<int>&visited) {
        if(i == -1)
            return true;
       
        if(visited.count(i))
            return false;
        visited.insert(i);

        return dfs(leftChild[i], leftChild, rightChild, visited) 
            && dfs(rightChild[i],leftChild, rightChild, visited);

    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // checking if the root node is there
        set<int> allChilds;
        for(int i = 0; i < n; i++) {
            allChilds.insert(leftChild[i]);
            allChilds.insert(rightChild[i]);
        }
        // removing the nulls
        allChilds.extract(-1);
        if(allChilds.size() == n) 
            // every node has a parent
            return false;

        set<int>visited;
        int root;
        // number not in allChilds is root
        for(int i = 0; i < n; i++) {
            if(!allChilds.count(i)) {
                root = i;
                break;
            }
        }
        // dfs
        return dfs(root, leftChild, rightChild, visited) && visited.size() == n;
    }
};
