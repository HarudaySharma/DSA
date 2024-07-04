#include <bits/stdc++.h>
using namespace std;

class Interval {
    public:
        int start, end;
        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }
};

class compare {
    public: 
        bool operator() (const Interval &a, const Interval &b) const {
            if(a.start != b.start) {
                return a.start < b.start;
            }
            return a.end < b.end;
        }
};

class Solution {
    public:
        bool canAttendMeetings(vector<Interval>& intervals) {
            sort(intervals.begin(), intervals.end(), compare());

            for(auto meet : intervals) {
                cout << meet.start << ", " << meet.end << endl;
            }

            Interval *lastMeet = &intervals[0];
            for(int i = 1; i < intervals.size(); i++) {
                if(intervals[i].start < lastMeet->end) { 
                    return false;
                }
                else {
                    lastMeet = &intervals[i];
                }
            }

            return true;
        }
};


