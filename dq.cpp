#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        while(1) {
            if(tickets[k] == 0)
                break;
            for(int i = 0; i < tickets.size(); i++) {
                int &ticket = tickets[i];
                if(ticket > 0) {
                    time++;
                    ticket--;
                    if(i == k && ticket == 0)
                        return time;
                }
            }
        }
        return time;
    }
};

