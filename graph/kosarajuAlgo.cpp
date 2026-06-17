#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
public:
  vector<vector<int>> adj;
  int V;

  Graph(int V)
  {
    this->V = V;
    adj.resize(V);
  }
  void addEdge(int u, int v)
  {
    adj[u].push_back(v);
  }

  void topoSort(int u, vector<bool> &vis, stack<int> &st)
  {
    vis[u] = true;
    for (int v : adj[u])
    {
      if (!vis[v])
      {
        topoSort(v, vis, st);
      }
    }
    st.push(u);
  }

  void dfs(int u, vector<bool> &vis, vector<vector<int>> &transpose)
  {
    vis[u] = true;
    cout << u << " ";
    for (int v : transpose[u])
    {
      if (!vis[v])
      {
        dfs(v, vis, transpose);
      }
    }
  }

  void kosaraju()
  {
    // topop sort
    stack<int> st;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        topoSort(i, vis, st);
      }
    }
    // transpose graph
    vector<vector<int>> transpose(V);

    for (int u = 0; u < V; u++)
    { // u->v
      vis[u] = false;
      for (int v : adj[u])
      {
        transpose[v].push_back(u); // v->u
      }
    }

    // dfs
    cout << "Stongly connected components : \n";

    while (st.size() > 0)
    {
      int curr = st.top();
      st.pop();

      if (!vis[curr])
      {
        dfs(curr, vis, transpose);
        cout << endl;
      }
    }
  }
};

int main()
{
  Graph g(5);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(1, 0);
  g.addEdge(2, 1);
  g.addEdge(3, 4);

  g.kosaraju();

  return 0;
}