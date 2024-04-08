#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> dp(n, 1);
        int r = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            r = max(r, dp[i]);
        }
        return r;
    }
};