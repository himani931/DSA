#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
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
    l[u].push_back(v); // directed graph
  }

  void dfs(int src, vector<bool> &vis, stack<int> &st)
  {
    vis[src] = true;
    for (int v : l[src])
    {
      if (!vis[v])
      {
        dfs(v, vis, st);
      }
    }
    st.push(src);
  }

  void topologicalSort()
  {
    vector<bool> vis(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        dfs(i, vis, st);
      }
    }
    while (st.size() > 0)
    {
      cout << st.top() << " ";
      st.pop();
    }
    cout << endl;
  }
};

int main()
{
  Graph g(6);

  g.addEdge(3, 1);
  g.addEdge(2, 3);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(5, 0);
  g.addEdge(5, 3);

  cout << "Topoplogical Sort : ";
  g.topologicalSort();

  return 0;
}