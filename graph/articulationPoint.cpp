#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Graph
{
public:
  vector<vector<int>> adj;
  int V;
  int time;
  vector<int> dt, low;

  Graph(int V)
  {
    this->V = V;
    adj.resize(V);
  }
  void addEdge(int u, int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void tarjansAlgo(int u, int parU, set<int> &critical)
  {
    dt[u] = low[u] = ++time;
    int child = 0;
    for (int v : adj[u])
    {
      if (dt[v] == -1)
      {
        child++;
        tarjansAlgo(v, u, critical);
        low[u] = min(low[u], low[v]);
        if (parU != -1 && low[v] >= dt[u])
        { // critical point
          critical.insert(u);
        }
      }
      else if (v != parU)
      {
        low[u] = min(low[u], dt[v]);
      }
    }
    if (parU == -1 && child > 1)
    { // critical point
      critical.insert(u);
    }
  }

  int articulationPoint()
  {
    time = 0;
    dt.resize(V, -1);
    low.resize(V, 0);
    set<int> critical;

    for (int i = 0; i < V; i++)
    {
      if (dt[i] == -1)
      {
        tarjansAlgo(i, -1, critical);
      }
    }
    for (auto i : critical)
    {
      cout << i << " ";
    }
    cout << endl;
    return critical.size();
  }
};

int main()
{
  Graph g(6);
  g.addEdge(1, 0);
  g.addEdge(1, 2);
  g.addEdge(4, 3);
  g.addEdge(4, 5);
  g.addEdge(4, 1);

  cout << "Number of Articulation / Critical Points : " << g.articulationPoint() << endl;

  return 0;
}