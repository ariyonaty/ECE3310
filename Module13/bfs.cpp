#include <iostream>
#include <list>

class Graph
{
private:
    int V;               // number of vertices
    std::list<int> *adj; //pointer to adjacency list
public:
    Graph(int v);
    void addEdge(int v, int w);
    void BFS(int s);
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

/* Perform BFS given a starting vertex */
void Graph::BFS(int s)
{
    // Start with all vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // Create a queue for BFS
    std::list<int> queue;

    // Starting vertex marked as visited and added to queue
    visited[s] = true;
    queue.push_back(s);

    // Continue until queue is empty
    while (!queue.empty())
    {
        // Get fron to queue and remove it
        s = queue.front();
        queue.pop_front();

        // Get all adjacent vertices from that vertex
        std::cout << "Checking adjacent vertices for vertex " << s << std::endl;
        for (auto i = adj[s].begin(); i != adj[s].end(); i++)
        {
            // we only care about nodes not visited yet
            if (!visited[*i])
            {
                // Mark as visited
                std::cout << "Visit and enqueue " << *i << std::endl;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
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

    // Perform BFS and print result
    g.BFS(2);

    return EXIT_SUCCESS;
}