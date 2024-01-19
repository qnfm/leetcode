#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        n = matrix[0].size();
        if (m == 1 || n == 1)
            return matrix[0][0];
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        int r = INT_MAX;
        for (int j = 0; j < n; j++)
            r = min(r, dfs(matrix, dp, 0, j));
        return r;
    }

private:
    int m, n;
    int dfs(vector<vector<int>> &mat, vector<vector<int>> &dp, int i, int j)
    {
        if (i == m - 1)
            return dp[i][j] = mat[i][j];
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        int left = INT_MAX, right = INT_MAX, straight = INT_MAX;
        if (j > 0)
            left = dfs(mat, dp, i + 1, j - 1);
        straight = dfs(mat, dp, i + 1, j);
        if (j < n - 1)
            right = dfs(mat, dp, i + 1, j + 1);
        return dp[i][j] = mat[i][j] + min(straight, min(left, right));
    }
};