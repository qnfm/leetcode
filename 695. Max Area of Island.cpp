#include <vector>
using namespace std;
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                r = max(dfs(grid, i, j), r);
        return r;
    }

private:
    int r = 0, m, n;
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
    }
};