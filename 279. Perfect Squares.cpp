#include <vector>
using namespace std;
/*
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        int sum = 1;
        for (int i = 1; sum <= n; i++)
        {
            dp[sum] = 1;
            sum = i * i;
        }

        return helper(dp, n);
    }
    int helper(vector<int> &dp, int n)
    {
        if (n < 0)
            return INT_MAX;
        if (dp[n] != INT_MAX)
            return dp[n];
        int sum = 1, cur = INT_MAX;
        for (int i = 1; sum <= n; i++)
        {
            cur = min(1 + helper(dp, n - sum), cur);
            sum = i * i;
        }
        return dp[n] = cur;
    }
};
*/

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};