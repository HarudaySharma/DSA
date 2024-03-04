#include "bits/stdc++.h"
#include <map>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
    public:
        void topoSort(map<int, unordered_set<int>> &adjList, vector<int> indegree, vector<int> &sorted) {
            queue<int>q;
            for(int i = 0; i < indegree.size(); i++) {
                if(indegree[i] == 0)
                    q.push(i);
            }
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                sorted.push_back(curr);
                for(auto prev : adjList[curr]) {
                    indegree[prev] -= 1;
                    if(indegree[prev] == 0) {
                        q.push(prev);
                    }
                }
            }
            return;
        }

        vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
            // finding the indegree of the beforeItems
            vector<int> itemsSorted;
            vector<int> groupsSorted;
            map<int, unordered_set<int>> itemsAdjList;
            map<int, unordered_set<int>> groupsAdjList;
            vector<int> indegreeItem(n, 0);
            vector<int> indegreeGroup(m + 1, 0);

            for(auto &el : group) {
                if(el == -1) {
                    el = m;
                }
            }
            for(int i = 0; i < n; i++) {
                itemsAdjList[i] = unordered_set<int>();
            }
            for(int i = 0; i <= m; i++) {
                groupsAdjList[i] = unordered_set<int>();
            }

            // giving a group to -1 group items

            for(int i = 0; i < n; i++) {
                for(auto prev : beforeItems[i]) {
                    itemsAdjList[i].insert(prev);
                    indegreeItem[prev] += 1;
                    if(group[i] != group[prev]){
                        groupsAdjList[group[i]].insert(group[prev]);
                        indegreeGroup[group[prev]] += 1;
                    }
                }
            }

            topoSort(itemsAdjList, indegreeItem, itemsSorted);
            if(itemsSorted.size() != n)
                return {};
            topoSort(groupsAdjList, indegreeGroup, groupsSorted);

            for(auto el : groupsAdjList){
                cout << el.first << " --- ";
                for(auto i : el.second) {
                    cout << i << " ";
                }
                cout << endl;
            }
            vector<int> res;
            for (auto g : groupsSorted) {
                vector<int> itemsInGroup;
                for (auto item : itemsSorted) {
                    if (group[item] == g) {
                        itemsInGroup.push_back(item);
                    }
                }
                // Append items in reverse order to the result
                for (int i = itemsInGroup.size() - 1; i >= 0; i--) {
                    res.push_back(itemsInGroup[i]);
                }
            }
            for(auto el : itemsSorted)
                cout << el << " ";
            cout << endl << "----" << endl;
            for(auto el : groupsSorted)
                cout << el << " ";
            return res;
        }
};

int main(int argc, char *argv[]) { return 0; }
