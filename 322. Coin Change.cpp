#include <vector>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (auto c : coins)
            {
                int diff = i - c;
                if (diff < 0)
                    continue;
                else
                    dp[i] = min(dp[i], dp[diff]);
            }
            if (dp[i] != amount + 1)
                dp[i]++;
        }
        return dp.back() != amount + 1 ? dp.back() : -1;
    }
};