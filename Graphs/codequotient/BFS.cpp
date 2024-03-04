#include<iostream> 
#include<list> 
#include <queue>
#include <unordered_set>
using namespace std; 

class Graph { 
    int V;
    list<int> *adj; 
    public:
    Graph(int V);
    void addEdge(int v, int w); 
    void BFS(int v); 
}; 

Graph::Graph(int V) { 
    this->V = V; 
    adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) { 
    adj[v].push_back(w);
}


void Graph::BFS(int start) {
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    queue<int>q;
    q.push(start);
    while (!q.empty()) {
        int size = q.size();
        while(size--) {
            const int curr = q.front();
            q.pop();
            if(visited[curr]) 
                continue;
            visited[curr] = true;
            cout << curr << " ";
            for(auto el : adj[curr]) {
                if(!visited[el])
                    q.push(el);
            }
        }
    }
    delete [] visited;
    return;
} 

int main() { 
    int V,E,v1,v2,s,i;
    cin>>V>>E;
    Graph g(V);
    for(i=0;i<E;i++)
    {
        cin>>v1>>v2;
        g.addEdge(v1, v2);
    }
    cin>>s;
    g.BFS(s); 
    return 0; 
}
