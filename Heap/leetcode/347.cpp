#include "bits/stdc++.h"
#include <functional>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> heap;

    int getParent(int i) {
        int p = i % 2 == 0 ? (i - 2) / 2 : (i - 1) / 2;
        return p < 0 ? -1 : p;
    }

    void swap(pair<int, int>&a, pair<int, int>&b) {
        pair<int, int> temp = a;
        a = b;
        b = temp;
    }
    int getLeftChild(int i) {
        int l = i * 2 + 1;
        return l > heap.size() - 1 ? -1 : l;
    }
    int getRightChild(int i) {
        int r = i * 2 + 2;
        return r > heap.size() - 1 ? -1 : r;
    }

    void upHeap(int i) {
        if(i == 0)
            return;
        if(heap[i].first > heap[i - 1].first) {
            swap(heap[i], heap[i - 1]);
            upHeap(i - 1);
            return;
        }
        int p = getParent(i);
        if(p == -1 || heap[p].first >= heap[i].first){
            return;
        }
        swap(heap[p], heap[i]);
        upHeap(p);
    }
    
    void insertHeap(pair<int, int> val) {
        heap.push_back(val);
        upHeap(heap.size() - 1);
    }

    bool contains(vector<pair<int, int>> &v, pair<int, int> p) {
        for(auto el : v) {
            if(el.first == p.first && el.second == p.second)
                return true;
        }
        return false;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>freq;
        for(auto el : nums){
            if(freq.count(el)) {
                freq[el] += 1;
            }
            else {
                freq.insert({el, 1});
            }
        }
        for(auto el : freq){ 
            if(heap.size() < k){
                insertHeap({el.second, el.first});
            }
            else {
                if(heap.back().first < el.second){
                    heap.pop_back();
                    insertHeap({el.second, el.first});
                }
            }
        }
        vector<int> res;
        while(!heap.empty()) {
            res.push_back(heap.back().second);
            heap.pop_back();
        }
        return res;
    }
};
