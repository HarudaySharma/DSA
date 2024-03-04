#include "bits/stdc++.h"
#include <forward_list>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int &curr, map<int, forward_list<int>*> &preqList, vector<bool> &visited) {
        if(visited[curr])
            return false;
        if(preqList[curr]->empty())
            return true;

        visited[curr] = true;
        for(auto &preq : *preqList[curr]) {
            if(!dfs(preq, preqList, visited))
                return false;
        }
        visited[curr] = false;
        preqList[curr]->clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, forward_list<int>*> preqList;
        vector<bool> visited;
        for(int i = 0; i < numCourses; i++){
            preqList[i] = new forward_list<int>;
            visited.push_back(false);
        }

        for(auto el : prerequisites) {
            preqList[el.at(0)]->push_front(el.at(1));
        }
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i, preqList, visited))
                return false;
        }
        for(int i = 0; i < numCourses; i++){
            delete preqList[i]; 
        }
        return true;
    }
};
