#include <vector>
using namespace std;
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        g = grid;
        m = grid.size();
        n = grid[0].size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return dfs(0, 0, n - 1);
    }

private:
    int m;
    int n;
    vector<vector<vector<int>>> dp;
    vector<vector<int>> g;
    int dfs(int r, int c1, int c2)
    {
        if (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n)
            return 0;
        if (dp[r][c1][c2] != INT_MIN)
            return dp[r][c1][c2];
        int res = 0;
        res += g[r][c1];
        if (c1 != c2)
            res += g[r][c2];
        if (r != m - 1)
        {
            int cur = 0;
            for (int i = c1 - 1; i <= c1 + 1; i++)
            {
                for (int j = c2 - 1; j <= c2 + 1; j++)
                {
                    cur = max(cur, dfs(r + 1, i, j));
                }
            }
            res += cur;
        }
        return dp[r][c1][c2] = res;
    }
};