#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int longestCommonSubsequence(string t1, string t2)
    {
        const int m = t1.size(), n = t2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (t1[i] == t2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[m][n];
    }
};