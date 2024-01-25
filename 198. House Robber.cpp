#include <vector>
#include <unordered_map>
using namespace std;
/*
// Timeout
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        dfs(nums, 0, 0);
        return sum;
    }

private:
    int sum = INT_MIN;
    void dfs(vector<int> &n, int idx, int cur)
    {
        if (idx >= n.size())
        {
            sum = max(sum, cur);
            return;
        }
        for (int i = idx; i < n.size(); i++)
        {
            cur += n[i];
            dfs(n, i + 2, cur);
            cur -= n[i];
        }
    }
};
*/

/* memo
class Solution
{
public:
    int rob(vector<int> &nums)
    {

        return dfs(nums, 0);
    }

private:
    unordered_map<int, int> map;
    int dfs(vector<int> &n, int idx)
    {
        if (idx >= n.size())
            return 0;

        if (map.contains(idx))
            return map[idx];
        return map[idx] = max(n[idx] + dfs(n, idx + 2), dfs(n, idx + 1));
    }
};
*/

// vector dp
/*
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        const int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};
*/

// memory optimal dp
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        const int n = nums.size();
        if (n == 1)
            return nums[0];
        int cur = 0, prev = nums[0], np = 0;
        for (int i = 1; i < n; i++)
        {
            cur = max(prev, np + nums[i]);
            np = prev;
            prev = cur;
        }
        return cur;
    }
};