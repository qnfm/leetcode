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