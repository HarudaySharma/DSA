#include<iostream> 
#include<list> 
using namespace std; 

class Graph 
{ 
  int V;
  list<int> *adj; 
  public:
  Graph(int V);
  void addEdge(int v, int w); 
  void DFSUtil(int v, bool visited[]); 
  void DFS(int v); 
}; 

Graph::Graph(int V) 
{ 
  this->V = V; 
  adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
  adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]) { 
    if(visited[v])
        return;
    visited[v] = true;
    cout << v << " ";
    for(auto el : adj[v]) {
        DFSUtil(el, visited);
    }
} 

void Graph::DFS(int v) { 
    bool *visited = new bool[adj->size()];
    for(int i = 0; i < adj->size(); i++)
        visited[i] = false;
    DFSUtil(v, visited);
    delete [] visited;
    return;
}
