#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, vector<vector<bool>> &vis,
         vector<vector<char>> &grid, int n, int m)
{

  if (i < 0 || j < 0 || i >= n || j >= m ||
      vis[i][j] || grid[i][j] != '1')
    return;

  vis[i][j] = true;

  dfs(i - 1, j, vis, grid, n, m); // top
  dfs(i, j + 1, vis, grid, n, m); // right
  dfs(i + 1, j, vis, grid, n, m); // bottom
  dfs(i, j - 1, vis, grid, n, m); // left
}

int numIslands(vector<vector<char>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<bool>> vis(n, vector<bool>(m, false));
  int islands = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == '1' && !vis[i][j])
      {
        dfs(i, j, vis, grid, n, m);
        islands++;
      }
    }
  }

  return islands;
}

int main()
{
  int n, m;

  cout << "Enter number of rows and columns: ";
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));

  cout << "Enter grid elements (0 or 1):\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }

  cout << "Number of Islands: " << numIslands(grid) << endl;

  return 0;
}