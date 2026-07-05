#include <iostream>
#include <vector>
using namespace std;

// top down approach
int fib(int n, vector<int> &dp)
{
  if (n == 0 || n == 1)
    return n;
  if (dp[n] != -1)
    return dp[n];

  dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
  return dp[n];
}

// bottom approach
int fibonacci(int n)
{
  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

// space optimization
int fibon(int n)
{
  int prev1 = 1;
  int prev2 = 0;

  if (n == 0)
    return prev2;

  for (int i = 2; i <= n; i++)
  {
    int curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}
int main()
{
  int n;
  cout << "Enter number : ";
  cin >> n;
  vector<int> dp(n + 1);

  for (int i = 0; i <= n; i++)
  {
    dp[i] = -1;
  }

  cout << fib(n, dp) << endl;

  cout << fibonacci(n) << endl;

  cout << fibon(n) << endl;

  return 0;
}