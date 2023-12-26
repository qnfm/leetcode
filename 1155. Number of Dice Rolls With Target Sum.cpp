#include <algorithm>
#include <vector>
using namespace std;

// recursive without memorizing

/*
class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        if (n == 0)
            return target == 0;
        int ways = 0;
        for (int i = 1; i <= min(k, target); i++)
        {
            ways = (ways + numRollsToTarget(n - 1, k, target - i)) % mod;
        }
        return ways;
    }

private:
    const int mod = 1e9 + 7;
};
*/

// recursive with memorizing

class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        return helper(memo, n, k, target);
    }

private:
    const int mod = 1e9 + 7;
    int helper(vector<vector<int>> &memo, int n, int k, int target)
    {
        if (n == 0)
            return target == 0;
        if (memo[n][target] != -1)
            return memo[n][target];

        int ways = 0;
        for (int i = 1; i <= min(k, target); i++)
        {
            ways = (ways + helper(memo, n - 1, k, target - i)) % mod;
        }
        return memo[n][target] = ways;
    }
};