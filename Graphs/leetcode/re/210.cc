#include <bits/stdc++.h>
#include <unordered_set>
#include <variant>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> taken;
    vector<bool> visited;
    vector<int> order;

    bool topoSort(int i, unordered_set<int> *adjList) {
        if(visited[i])
            return false;
        if(taken[i])
            return true;
        visited[i] = true;
        for(auto el : adjList[i]){
            if(!taken[el]){
                if(!topoSort(el, adjList))
                    return false;
            }
        }
        taken[i] = true;
        visited[i] = false;
        order.push_back(i);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // create a AdjList
        unordered_set<int> adjList[numCourses];
        taken.resize(numCourses, false);
        visited.resize(numCourses, false);
        
        for(auto pr : prerequisites) {
            adjList[pr[0]].insert(pr[1]);
        }
        for(int i = 0; i < numCourses; i++){
                if(!topoSort(i, adjList)){
                    return {};
                }
        }
        if(order.size() != numCourses)
            return {};
        return order;
    }
};

