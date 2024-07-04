#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <ctime>
#include <unordered_set>
#include <vector>
using namespace std;

class Interval {
    public:
        int start, end;
        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }
};


class Solution {
    public:
        // minimum meetings required to held all the meetings
        // overlapping intervals => more meeting rooms
        int minMeetingRooms(vector<Interval>& intervals) {
            int minRooms = 0;

            vector<int> start;
            vector<int> end;
            for(auto interval : intervals) {
                start.push_back(interval.start);
                end.push_back(interval.end);
            }
            sort(start.begin(), start.end());
            sort(end.begin(), end.end());
            
            int i = 0;
            int j = 0;
            int count = 0; // will keep track of no. of meetings being held simultaneoulsy
            while(i < start.size() && j < end.size()) {
                if(start[i] < end[j]) {
                    // new meeting started
                    count++;
                    minRooms = max(count, minRooms);
                    i++;
                }
                else {
                    // previous meeting ended
                    count--;
                    j++;
                }
            }
            
            return minRooms;
        }
};

