#include<bits/stdc++.h>
#include <vector>
using namespace std;

/* 
 * LOGIC FAILED
 */
class Solution {
public:
    vector<pair<int,pair<int, int>>> heap;
    int getParent(int i) {
        int p = i % 2 == 0 ? (i - 2) / 2 : (i - 1) / 2;
        return p < 0 ? -1 : p;
    }

    void swap(pair<int,pair<int, int>>&a, pair<int, pair<int, int>>&b) {
        pair<int, pair<int, int>> temp = a;
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

    pair<int,pair<int, int>>& min(pair<int,pair<int, int>> &a, pair<int,pair<int, int>>&b){
        return a.first < b.first ? a : b;
    }

    void downHeap(int p) {
        int lChild = getLeftChild(p);
        int rChild = getRightChild(p);
        if(lChild == -1 && rChild == -1)
            return;
        if(lChild == -1 && heap[p].first < heap[rChild].first) {
            swap(heap[p], heap[rChild]);
            return;
        }
        else if(rChild == -1 && heap[p].first < heap[lChild].first) {
            swap(heap[p], heap[lChild]);
            return;
        }
        else {
            if(lChild == -1 || rChild == -1){
                return;
            }
            auto &child = min(heap[rChild], heap[lChild]);
            if(heap[p].first < child.first){
                swap(heap[p], child);
            }
            return;;
        } 
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
    
    void insertHeap(int sum, pair<int, int> val) {
        pair<int,pair<int, int>> p{sum, val};
        heap.push_back(p);
        upHeap(heap.size() - 1);
    }

    bool contains(vector<pair<int, int>> &v, pair<int, int> p) {
        for(auto el : v) {
            if(el.first == p.first && el.second == p.second)
                return true;
        }
        return false;
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // hash for containing the already formed pairs
        vector<pair<int, int>> v;
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while(i < nums1.size() && j < nums2.size()) {
            pair<int, int> p{i, j};
            if(!contains(v, p)){
                insertHeap(nums1[i] + nums2[j],p); 
                v.push_back(p);
            }
            if(i + 1 < nums1.size()) {
                p = {i + 1, j};
                if(!contains(v, p)){
                    insertHeap(nums1[i + 1] + nums2[j], p);
                    v.push_back(p);
                }
            }
            if(j + 1 < nums2.size()) {
                p = {i, j + 1};
                if(!contains(v, p)){
                    insertHeap(nums1[i] + nums2[j + 1], p);
                    v.push_back(p);
                }
            }
            i++, j++;
        }
        for(auto el : heap) {
            cout << "{ " <<nums1[el.second.first] << ", " << nums2[el.second.second ] << " }";
            cout << endl;
        }
        while(k--) {
            vector<int> min {nums1[heap.back().second.first], nums2[heap.back().second.second]};
            ans.push_back(min);
            heap.pop_back();
        }
        return ans;
    }
};

/*
 class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>finalans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
               int sum =nums1[i]+nums2[j];
               if(pq.size()<k){
                 pq.push({sum,{nums1[i],nums2[j]}}) ;
               }
               else if(sum < pq.top().first) {
                  pq.pop();
                  pq.push({sum,{nums1[i],nums2[j]}}) ;
               }
               else{
                   break;
               }
            }
        }
         while(!pq.empty()){
               finalans.push_back({pq.top().second.first,pq.top().second.second});
               pq.pop();
           }
    return finalans;
    }
};
*/
