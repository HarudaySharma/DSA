// Graph.hpp
#include <vector>
using namespace std;

class Graph {
    private:
        vector<vector<int>>* convertToAdjList(vector<vector<int>> &);
    public:
        void BFS(vector<vector<int>> &);
        void DFS(vector<vector<int>> &);
};
