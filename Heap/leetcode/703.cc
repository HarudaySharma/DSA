#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {

    private:
        int k;
        priority_queue<int, vector<int>, greater<int>> pq;

    public:
        KthLargest(int k, vector<int>& nums) {
            this->k = k;
            for(auto el : nums) {
                if(pq.size() < k) {
                    pq.push(el);
                }
                else {
                    if(pq.top() < el){
                        pq.pop();
                        pq.push(el);
                    }
                }

            }
        }

        int add(int val) {
            if(pq.size() < k)
                pq.push(val);
            else if(pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
            return pq.top();
        }
};

