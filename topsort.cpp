// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <stack>
using namespace std;


class Graph
{
    int V;

    list<int> *adj;

    void topologicalSortUtil(int v, bool vis[], stack<int> &Stack);
public:
    Graph(int V);
    void addEdge(int v, int w);


    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);}

void Graph::topologicalSortUtil(int v, bool vis[], stack<int> &Stack)
{

    vis[v] = true;
    Stack.push(v);
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!vis[*i])
            topologicalSortUtil(*i, vis, Stack);

    // Push current vertex to stack which stores result

}
void Graph::topologicalSort()
{
    stack<int> Stack;

    bool *vis = new bool[V];
    for (int i = 0; i < V; i++)
        vis[i] = false;

    for (int i = 0; i < V; i++)
      if (vis[i] == false)
        topologicalSortUtil(i, vis, Stack);

    // Print contents of stack
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}
