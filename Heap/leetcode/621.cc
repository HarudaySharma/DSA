#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getFrequencies(vector<char> &tasks) {
        vector<int> freq;
        unordered_map<char, int> fr;
        for(auto el : tasks) {
            fr[el] += 1;
        }
        for(auto el : fr) {
            freq.push_back(el.second);
        }
        return freq;
    }

    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> freq = getFrequencies(tasks);
        // fill the max Heap
        for(auto el : freq) {
            pq.push(el);
        }
        int time = 0;
        queue<pair<int, int>> q;
        while(!pq.empty() || !q.empty()) {
            time += 1;
            if(!pq.empty())  {
                int mostFreqTask = pq.top();
                pq.pop();
                mostFreqTask -= 1;
                // interval after which this task can be executed again
                // time + n
                if(mostFreqTask) {
                    q.push({mostFreqTask, time + n});
                }
            }
            // checking for the task in queue if it's wait time is ended
            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};

