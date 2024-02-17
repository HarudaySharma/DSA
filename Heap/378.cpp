#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> heap;

        void swap(int &a, int &b) {
            int temp = a;
            a = b;
            b = temp;
        }

        int getParent(int i) {
            int p = i % 2 == 0 ? (i - 2) / 2 : (i - 1) / 2 ;
            return p < 0 ? -1 : p;
        }

        void upHeap(int i) {
            if(i == 0)
                return;
            if(heap[i] < heap[i - 1]) {
                swap(heap[i], heap[i - 1]);
                upHeap(i - 1);
                return;
            }
            int p = getParent(i);
            if(p == -1 || heap[i] >= heap[p]) 
                return;
            swap(heap[i], heap[p]);
            upHeap(p);
        }

        void insertInHeap(int val) {
            heap.push_back(val);
            upHeap(heap.size() - 1);
        }

        int kthSmallest(vector<vector<int>>& matrix, int k) {
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[i].size(); j++) {
                    insertInHeap(matrix[i][j]);
                }
            }
            return k <= heap.size() ? heap[k - 1] : -1;
        }
};
