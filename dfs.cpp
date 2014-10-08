#include <iostream>
#include <list>

using namespace std;

class Graph{
 int V;
 list<int> *adj;
 void dfsUtil(int s,bool vis[]);
 public:
 Graph(int V);
 void addEdge(int u,int v);
 void dfs(int s);
 void createGraph(Graph &g);
 };
 Graph::Graph(int V)
 {
    this->V=V;
    adj = new list<int>[V];
 }
 void Graph::addEdge(int u,int v)
 {
     adj[u].push_back(v);

 }

void Graph::createGraph(Graph &g)
{
cout << "Enter adjacency list as \
the vertex no.(starting from 0) seperated by space \
and terminate adjacency list for each \
vertex by -1" << endl;
cout << "For Example:" << endl;
cout << "0 1 -1" << endl << "1 0 -1" << endl << "This will create" << endl << "0:0->1->N" << endl << "1:1->0->N" << endl << "So,enter now!" << endl;
  int d=0;
  for(int i=0;i<V;i++)
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


 void Graph::dfsUtil(int s,bool vis[])
 {
     /*static bool *vis = new bool[V];
     for(int i = 0; i < V; i++)
        vis[i] = false;*/

     cout << s << " ";
     vis[s]=true;

     list<int>::iterator it;
     for(it=adj[s].begin();it!=adj[s].end();++it)
        if(!vis[*it])
          dfsUtil(*it,vis);
 }
void Graph::dfs(int s)
{
    bool *vis=new bool[V];
    for(int i=0;i<V;i++)
      vis[i]=false;
    dfsUtil(s,vis);
}
int main()
{
    Graph g(4);
    g.createGraph(g);
    g.dfs(2);

    return 0;
}

