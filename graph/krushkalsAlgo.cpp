#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{
public:
  int u, v, wt;
  Edge(int u, int v, int wt)
  {
    this->u = u;
    this->v = v;
    this->wt = wt;
  }
  // comparator
  bool operator<(const Edge &other) const
  {
    return this->wt < other.wt;
  }
};

class Graph
{
public:
  int V;
  vector<Edge> edges;
  vector<int> par, rank;

  Graph(int V)
  {
    this->V = V;

    for (int i = 0; i < V; i++)
    {
      par.push_back(i);
      rank.push_back(0);
    }
  }

  void addEdge(int u, int v, int wt)
  {
    edges.push_back(Edge(u, v, wt));
  }

  int find(int x)
  {
    if (par[x] == x)
      return x;
    return par[x] = find(par[x]);
  }

  void unionByRank(int a, int b)
  {
    int parA = find(a);
    int parB = find(b);

    if (parA == parB)
      return;

    if (rank[parA] == rank[parB])
    {
      par[parB] = parA;
      rank[parA]++;
    }
    else if (rank[parA] > rank[parB])
    {
      par[parB] = parA;
    }
    else
    {
      par[parA] = parB;
    }
  }

  void krushkalAlgo()
  {
    sort(edges.begin(), edges.end());
    int mstCost = 0;
    int cnt = 0;

    for (int i = 0; i < edges.size() && cnt < V - 1; i++)
    {
      Edge e = edges[i];
      int parU = find(e.u);
      int parV = find(e.v);
      if (parU != parV)
      {
        unionByRank(e.u, e.v);
        mstCost += e.wt;
        cnt++;
      }
    }
    cout << "MST COST :" << mstCost << endl;
  }
};

int main()
{
  Graph g(4);

  g.addEdge(0, 1, 10);
  g.addEdge(0, 2, 6);
  g.addEdge(0, 3, 5);
  g.addEdge(1, 3, 15);
  g.addEdge(2, 3, 4);

  g.krushkalAlgo();

  return 0;
}