#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
  int V;
  list<int> *l; // int *arr(dynamic array)

public:
  Graph(int V)
  {
    this->V = V;
    l = new list<int>[V];
  }

  void addEdge(int u, int v)
  {
    l[u].push_back(v);
    l[v].push_back(u);
  }

  void printAdjList()
  {
    for (int i = 0; i < V; i++)
    {
      cout << i << " : ";
      for (int neigh : l[i])
      {
        cout << neigh << " ";
      }
      cout << endl;
    }
  }

  // BFS TRAVERSAL
  void bfs()
  {
    queue<int> q;
    vector<bool> vis(V, false);
    q.push(0);
    vis[0] = true;
    while (q.size() > 0)
    {
      int u = q.front(); // source
      q.pop();
      cout << u << " ";
      for (int v : l[u])
      {
        if (!vis[v])
        {
          vis[v] = true;
          q.push(v);
        }
      }
    }
    cout << endl;
  }

  // DFS TRAVERSAL
  void dfsHelper(int u, vector<bool> &vis)
  {
    cout << u << " ";
    vis[u] = true;
    for (int v : l[u])
    {
      if (!vis[v])
      {
        dfsHelper(v, vis);
      }
    }
  }

  void dfs()
  {
    int src = 0;
    vector<bool> vis(V, false);
    dfsHelper(src, vis);
  }
};

int main()
{
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 4);

  cout << "ADJACENCY LIST : " << endl;
  g.printAdjList();

  cout << endl;

  cout << "BFS TRAVERSAL : ";
  g.bfs();

  cout << endl;

  cout << "DFS TRAVERSAL : ";
  g.dfs();

  return 0;
}