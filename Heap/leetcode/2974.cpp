#include "bits/stdc++.h"
#include <vector>
using namespace std;

class Heap {
    private:
        vector<int>heap;

        void swap(int &a, int &b) {
            int temp = a;
            a = b;
            b = temp;
        }

        int getLeftChild(int i) {
            int l = 2 * i + 1;
            return l < heap.size() ? l : -1;
        }

        int getRightChild(int i) {
            int r = 2 * i + 2;
            return r < heap.size() ? r : -1;
        }
        
        int getParent(int i) {
            int p = i % 2 == 0 ? (i - 2) / 2 : (i - 1) / 2 ;
            return p < 0 ? -1 : p;
        }

        void upHeap() {
            int i = heap.size() - 1;
            while(1) {
                int parent = getParent(i);
                if(parent == -1 || i == parent)
                    return;
                if(heap[parent] > heap[i])
                    swap(heap[parent], heap[i]);
                i = parent;
            }
        }
        void downHeap() {
            int i = 0;
            while (1) {
                int l = getLeftChild(i);
                int r = getRightChild(i);
                if(l == -1 && r == -1) {
                    return;
                }
                if(l != -1 && r != -1) {
                    int t = heap[l] < heap[r] ? l : r;
                    if(heap[t] < heap[i]) {
                        swap(heap.at(t), heap.at(i));
                        i = t;
                    }
                    else {
                        return;
                    }
                }
                else if(l != -1 && heap[l] < heap[i]) {
                    swap(heap.at(l), heap.at(i));
                    i = l;
                }
                else if(r != -1 && heap[r] < heap[i]) {
                    swap(heap.at(r), heap.at(i));
                    i = r;
                }
                else {
                    return;
                }
            }
        }

    public:
        void insert(int ele) {
            heap.push_back(ele);
            // up heap (for min heap)
            upHeap();
        }

        int remove() {
            if(heap.empty()) {
                return -1;
            }
            int f = heap.front();
            heap.front() = heap.back();
            heap.pop_back();
            if(!heap.empty()) {
                downHeap();
            } else {
                heap.clear();
            }
            return f;
        }

        bool isEmpty() {
            return heap.empty();
        }
};
class Solution {
public:
    vector<int> numberGame(vector<int> &nums) {
        Heap h;
        for(auto el : nums) {
            h.insert(el);
        }
        vector<int> sortedArray;
        int f ;
        int s;
        while(!h.isEmpty()) {
            f = h.remove();
            s = h.remove();
            sortedArray.push_back(s);
            sortedArray.push_back(f);
        }
        return sortedArray;
    }
};
int main (int argc, char *argv[]) {
    vector<int> in{84,72,12,68,100,31,67,28,53,22,28,30,60,30,80,59,16,92,98,57,54,89,34,45,76,4,39,47,44,64 };
    Solution s;
    vector<int> r= s.numberGame(in);
    for(auto el : r) {
        cout << el << endl;
    }

}
