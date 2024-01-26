#include <vector>
using namespace std;
class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        dp = vector<vector<vector<int>>>(51, vector<vector<int>>(51, vector<int>(51, -1)));
        return helper(m, n, maxMove, startRow, startColumn) % mod;
    }

private:
    static const int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    long helper(const int m, const int n, int mm, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 1;
        if (mm <= 0)
            return 0;
        if (dp[i][j][mm] != -1)
            return dp[i][j][mm];
        long r = 0;
        r += helper(m, n, mm - 1, i - 1, j);
        r += helper(m, n, mm - 1, i + 1, j);
        r += helper(m, n, mm - 1, i, j - 1);
        r += helper(m, n, mm - 1, i, j + 1);
        return dp[i][j][mm] = r % mod;
    }
};