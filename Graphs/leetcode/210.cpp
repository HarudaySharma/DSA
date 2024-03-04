#include "bits/stdc++.h"
#include <forward_list>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> res;
    unordered_set<int> included;

    bool dfs(const int &curr, map<int, forward_list<int>*> &preqList, vector<bool> &visited) {
        if(visited[curr])
            return false;

        if(included.count(curr)) {
            return true;
        }

        if(preqList[curr]->empty()) {
            res.push_back(curr);
            // mark the added node
            included.insert(curr);
            return true;
        }

        visited[curr] = true;
        for(auto &preq : *preqList[curr]) {
            if(!dfs(preq, preqList, visited))
                return false;
        }

        visited[curr] = false;
        preqList[curr]->clear();

        res.push_back(curr);
        // mark the added node
        included.insert(curr);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
            if(included.count(i))
                continue;
            if(!dfs(i, preqList, visited)) {
                res.clear();
                return res;
            }
        }

        for(int i = 0; i < numCourses; i++){
            delete preqList[i]; 
        }
        return res;
    }
};

int main (int argc, char *argv[]) {
    vector<vector<int>> v = {{1,0},{2,0},{3,1},{3,2}};
    Solution s;
    vector<int> res = s.findOrder(4, v);
    for(auto el : res) {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}
