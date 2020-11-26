/*
    Depth First Search
 */

#include <iostream>
#include <list>

class Graph
{
private:
    int V;
    std::list<int> *adj;
    void DFS_helper(int s, bool *visited);

public:
    Graph(int v);
    void addEdge(int v, int w);
    void DFS(int s);
};

Graph::Graph(int v)
{
    V = v;
    adj = new std::list<int>[v];
}

/* Implementation of method to add edges */
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS_helper(int s, bool *visited)
{
    std::cout << "Visiting node: " << s << std::endl;
    visited[s] = true;

    for (auto i = adj[s].begin(); i != adj[s].end(); i++)
    {
        if (!visited[*i])
        {
            std::cout << "Going to vertex " << *i << " from vertex " << s << std::endl;
            DFS_helper(*i, visited);
        }
    }
}

/*  */
void Graph::DFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    DFS_helper(s, visited);
}

int main(void)
{
    Graph g(6);

    // Add edges for vertices
    // Connections for vertex 0
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    // Connections for vertex 1
    g.addEdge(1, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    // Connections for vertex 2
    g.addEdge(2, 0);
    g.addEdge(2, 4);

    // Connections for vertex 3
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    // Connections for vertex 4
    g.addEdge(4, 1);
    g.addEdge(4, 2);
    g.addEdge(4, 3);
    g.addEdge(4, 5);

    // Connections for vertex 5
    g.addEdge(5, 3);
    g.addEdge(5, 4);

    g.DFS(0);

    return EXIT_SUCCESS;
}