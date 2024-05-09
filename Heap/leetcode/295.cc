#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    // will store all the maximum elements
    // return min(max Eles) => o(1)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // will store all the minimum elements
    // return max(min Eles) => o(1)
    priority_queue<int> maxHeap;
    // BALANCE DATA IN THESE TWO (HALF HALF)
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // add to the maxHeap
        maxHeap.push(num);
        // pop the max Ele and push in minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        return;
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()) {
            return double(maxHeap.top() + minHeap.top()) / 2;
        }
        return double(maxHeap.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

