#include <vector>
using namespace std;
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        const int N = arr.size();
        vector<int> dp(N);
        for (int i = 0; i < N; i++)
        {
            int cur = 0;
            for (int _k = 1; _k <= k && i - _k + 1 >= 0; _k++)
            {
                cur = max(cur, arr[i - _k + 1]);
                dp[i] = max(dp[i], (i >= k ? dp[i - _k] : 0) + cur * _k);
            }
        }
        return dp[N - 1];
    }
};