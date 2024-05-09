#include <bits/stdc++.h>
#include <map>
using namespace std;

/*
 * NOT DONE (LOGIC FAILED)
 */
class Heap {
    private:
        vector<pair<char,int>>heap;

        void swap(pair<char,int> &a, pair<char,int> &b) {
            pair<char,int> temp = a;
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

        void upHeap(int i) {
            if(i == 0)
                return;
            if(heap[i].second > heap[i - 1].second) {
                swap(heap[i - 1], heap[i]);
                upHeap(i - 1);
                return;
            }

            int parent = getParent(i);
            if(parent == -1 || i == parent)
                return;
            if(heap[parent].second < heap[i].second)
                swap(heap[parent], heap[i]);

            upHeap(parent);
        }

        void downHeap(int i = 0) {
            while (1) {
                int l = getLeftChild(i);
                int r = getRightChild(i);
                if(l == -1 && r == -1) {
                    return;
                }
                if(l != -1 && r != -1) {
                    int t = heap[l].second < heap[r].second ? l : r;
                    if(heap[t].second > heap[i].second) {
                        swap(heap.at(t), heap.at(i));
                        i = t;
                    }
                    else {
                        return;
                    }
                }
                else if(l != -1 && heap[l].second > heap[i].second) {
                    swap(heap.at(l), heap.at(i));
                    i = l;
                }
                else if(r != -1 && heap[r].second > heap[i].second) {
                    swap(heap.at(r), heap.at(i));
                    i = r;
                }
                else {
                    return;
                }
            }
        }

    public:
        pair<char, int>& front() {
            return heap.front();
        }

        void insert(pair<char, int> ele) {
            heap.push_back(ele);
            // up heap (for min heap)
            upHeap(heap.size() - 1);
        }

        int remove(int i = 0) {
            if(heap.empty()) {
                return -1;
            }
            auto f = heap[i];
            heap[i] = heap.back();
            heap.pop_back();
            if(!heap.empty()) {
                downHeap(i);
            } else {
                heap.clear();
            }
            return f.first;
        }

        bool isEmpty() {
            return heap.empty();
        }
        void display() {
            for(auto el : heap) {
                cout << el.first << " : " << el.second << endl;
            }
        }
        int size() {
            return heap.size();
        }
        pair<char,int>& operator[](int index){
            return heap[index];
        }
};
class Solution {
public:
    string reorganizeString(string s) {
        map<char, int>hash;
        for(auto el : s) {
            if(hash.count(el)) {
                hash[el] += 1;
            }
            else {
                hash[el] = 1;
            }
        }
        Heap heap;
        for(auto el : hash) {
            heap.insert(el);
        }

        s.clear();
        while(!heap.isEmpty()) {
            heap.display();
            cout << "-------------------" << endl;
            for(int i = 0; i < heap.size(); i++) {
                auto p = heap[i];
                if(s.empty()) {
                    s.push_back(p.first);
                    cout << s << endl;
                    heap.remove(i);
                    p.second--;
                    if(p.second != 0) {
                        heap.insert({p.first, p.second});
                        break;
                    }
                }
                if(s.back() != p.first) {
                    s.push_back(p.first);
                    cout << s << endl;
                    heap.remove(i);
                    p.second--;
                    if(p.second != 0) {
                        heap.insert({p.first, p.second});
                        break;
                    }
                }
                else {
                    if(heap.size() == 1)
                        return "";
                }
            }
        }
        return s;
    }
};
