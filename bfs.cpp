#include<iostream>
#include <list>

using namespace std;

class Graph
{

    list<int> *adj;
public:
    int V;
    Graph(int V);
    void addEdge(int v, int w);
    void bfs(int s);
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

void Graph::bfs(int s)
{

    bool *vis = new bool[V];
    for(int i = 0; i < V; i++)
        vis[i] = false;


    list<int> q;

    vis[s] = true;
    q.push_back(s);


    list<int>::iterator i;

    while(!q.empty())
    {

        s = q.front();
        cout << s << " ";
        q.pop_front();

        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!vis[*i])
            {
                vis[*i] = true;
                q.push_back(*i);
            }
        }
    }
}

 void createGraph(Graph &g)
{
cout << "Enter adjacency list as \
the vertex no.(starting from 0) seperated by space \
and terminate adjacency list for each \
vertex by -1" << endl;
cout << "For Example:" << endl;
cout << "0 1 -1" << endl << "1 0 -1" << endl << "This will create" << endl << "0:0->1->N" << endl << "1:1->0->N" << endl << "So,enter now!" << endl;
  int d=0;
  for(int i=0;i<g.V;i++)
    {
     cin >> d;
     while(d!=-1)
     {
      g.addEdge(i,d);
      cin >> d;
     }
    }
    cout << "Graph Created" << endl;
    //print_graph(n);
}
int main()
{

    Graph g(4);
    createGraph(g);
    cout << "Breadth First Traversal (starting from vertex 0) \n";
    g.bfs(0);

    return 0;
}
