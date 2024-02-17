#include "bits/stdc++.h"
#include <iostream>
using namespace std;


// building min heap
template <typename T>
class Heap {
    private:
        vector<T>heap;
        void swap(T &a, T &b) {
            T temp = a;
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

        // root => 0 (index)
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
        void insert(T ele) {
            heap.push_back(ele);
            // up heap (for min heap)
            upHeap();
        }

        T remove() {
            if(heap.empty()) {
                return -1;
            }
            T f = heap.front();
            if(!heap.empty()) {
                T l = heap.back();
                heap.front() = l;
                downHeap();
            }
            cout << f << endl;
            return f;
        }
};

int main (int argc, char *argv[]) {
    Heap<int> h;
    h.insert(23);
    h.insert(34);
    h.insert(10);
    h.insert(12);
    h.insert(56);
    int i = 5;
    while(--i) {
        cout << h.remove() << " ";
    }
    cout << endl;
    return 0;
}
