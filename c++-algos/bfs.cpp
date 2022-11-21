#include <bits/stdc++.h>
using namespace std;

class BFS {
    int V;
    vector<list<int>> adj;

    public:
        void addEdge(int v, int w);

        BFS(int V);

        void Traverse(int s);
};

BFS::BFS(int V) {
    this->V = V;
    adj.resize(V);
};

void BFS::addEdge(int v, int w) {
    adj[v].push_back(w);
};

void BFS::Traverse(int s) {
    vector<bool> visited;
    visited.resize(V, false);

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (auto e : adj[s])
        {
            if(!visited[e]) {
                visited[e] = true;
                queue.push_back(e);
            };
        }
        
    }
    
};

int main() {
    BFS b(4);
    b.addEdge(0, 1);
    b.addEdge(0, 2);
    b.addEdge(1, 2);
    b.addEdge(2, 0);
    b.addEdge(2, 3);
    b.addEdge(3, 3);

    b.Traverse(2);
    return 0;
};