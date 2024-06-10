#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <vector>

class Graph {
private:
    int V;
    std::list<int>* adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new std::list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFSUtil(int v, std::vector<bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                DFSUtil(*i, visited);
            }
        }
    }

    void DFS(int v) {
        std::vector<bool> visited(V, false);
        DFSUtil(v, visited);
    }

    void BFS(int s) {
        std::vector<bool> visited(V, false);
        std::queue<int> queue;

        visited[s] = true;
        queue.push(s);

        while (!queue.empty()) {
            s = queue.front();
            std::cout << s << " ";
            queue.pop();

            for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    queue.push(*i);
                }
            }
        }
    }

    ~Graph() {
        delete[] adj;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "DFS (starting from vertex 2): ";
    g.DFS(2);

    std::cout << "\nBFS (starting from vertex 2): ";
    g.BFS(2);

    return 0;
}
