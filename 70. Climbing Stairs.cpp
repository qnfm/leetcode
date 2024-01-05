// Recursion
/*
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
*/

// Memoization
/*
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        if (!map.contains(n))
            map[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return map[n];
    }

private:
    unordered_map<int, int> map;
};
*/

// Tabulation
#include <vector>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};