#include <vector>
using namespace std;
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        N = grid.size();
        dp = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, INT_MIN)));
        g = grid;
        return max(0, dfs(0, 0, 0));
    }

private:
    int N;
    vector<vector<vector<int>>> dp;
    vector<vector<int>> g;
    int dfs(int r1, int c1, int c2)
    {
        int r2 = r1 + c1 - c2;
        if (r1 == N || r2 == N || c1 == N || c2 == N || g[r1][c1] == -1 || g[r2][c2] == -1)
            return -1e4;
        if (r1 == N - 1 && c1 == N - 1)
            return g[r1][c1];
        if (dp[r1][c1][c2] != INT_MIN)
            return dp[r1][c1][c2];
        int r = g[r1][c1];
        if (r1 != r2)
            r += g[r2][c2];
        r += max(max(dfs(r1 + 1, c1, c2), dfs(r1 + 1, c1, c2 + 1)), max(dfs(r1, c1 + 1, c2), dfs(r1, c1 + 1, c2 + 1)));
        return dp[r1][c1][c2] = r;
    }
};