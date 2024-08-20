// Graph.cpp
#include "Graph.hpp"
#include <vector>

// I am not able to define the private functions in this file
vector<vector<int>>* Graph::convertToAdjList(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<vector<int>> *adjList = new vector<vector<int>>(n, vector<int>());
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(mat[i][j] == 1)
                adjList->at(i).push_back(j);
        }
    }
    return adjList;
}

void Graph::BFS(vector<vector<int>> &mat) {
    vector<vector<int>>* adjList = Graph::convertToAdjList(mat);
}
