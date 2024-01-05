#include <vector>
using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        const int sz = cost.size();
        vector<int> dp(sz, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < sz; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[sz - 1], dp[sz - 2]);
    }
};