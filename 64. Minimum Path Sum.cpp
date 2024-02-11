#include <vector>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = min(i + 1 < m ? dp[i + 1][j] : INT_MAX, j + 1 < n ? dp[i][j + 1] : INT_MAX);
                if (dp[i][j] == INT_MAX)
                    dp[i][j] = 0;
                dp[i][j] += grid[i][j];
            }
        }
        return dp[0][0];
    }
};