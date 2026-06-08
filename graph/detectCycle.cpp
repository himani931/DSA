#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
  int V;
  list<int> *l;

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

  bool isCycleDFS(int src, vector<bool> &vis, int par)
  {
    vis[src] = true;
    list<int> neigh = l[src];
    for (int v : neigh)
    {
      if (!vis[v])
      {
        if (isCycleDFS(v, vis, src))
        {
          return true;
        }
      }
      else if (v != par)
      {
        return true;
      }
    }
    return false;
  }

  bool isCycleBFS(int src, vector<bool> &vis)
  {
    queue<pair<int, int>> q;
    q.push({src, -1});
    vis[src] = true;
    while (q.size() > 0)
    {
      int u = q.front().first;
      int par = q.front().second;
      q.pop();

      list<int> neigh = l[u];

      for (int v : neigh)
      {
        if (!vis[v])
        {
          q.push({v, u});
          vis[v] = true;
        }
        else if (v != par)
        {
          return true;
        }
      }
    }
    return false;
  }

  bool isCycle()
  {
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) // for disconnected graph too
    {
      if (!vis[i])
      {
        // dfs
        //  if (isCycleDFS(i, vis, -1))
        //  {
        //    return true;
        //  }

        // bfs
        if (isCycleBFS(i, vis))
        {
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{
  Graph g(5);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(1, 2);
  g.addEdge(3, 4);

  cout << g.isCycle() << endl;

  return 0;
}
