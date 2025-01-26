#include <bits/stdc++.h>
#include <vector>

using namespace std;

// for integer values only
class UnionSetRank {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionSetRank(int size) {
        parent.resize(size + 1);
        rank.resize(size + 1, 0);
        for(int i = 0; i < size + 1; i++) {
            parent[i] = i;
        }
    }

    int getSetSize(int a) {
        int parent = find(a);

        return rank[parent];
    }

    void unionByRank(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);

        if(parentA == parentB) {
            return;
        }

        if(rank[parentA] > rank[parentB]) {
            parent[parentB] = parentA;
        } else if (rank[parentA] < rank[parentB]) {
            parent[parentA] = parentB;
        }  else {
            parent[parentA] = parentB;
            rank[parentB] += 1;
        }

        return;
    }

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }
};


// for integer values only
class UnionSetSize {
private:
    vector<int> parent;
    vector<int> setSize;

public:
    UnionSetSize(int size) {
        parent.resize(size + 1);
        setSize.resize(size + 1, 1);
        for(int i = 0; i < size + 1; i++) {
            parent[i] = i;
        }
    }

    int getSetSize(int a) {
        int parent = find(a);

        return setSize[parent];
    }

    void unionByRank(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);

        if(parentA == parentB) {
            return;
        }

        if(setSize[parentA] > setSize[parentB]) {
            parent[parentB] = parentA;
            setSize[parentA] += setSize[parentB];
        } else {
            parent[parentA] = parentB;
            setSize[parentB] += setSize[parentA];
        }

        return;
    }

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

};
