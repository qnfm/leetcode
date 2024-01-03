#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> cur;
        dfs(nums, 0, cur);
        return r;
    }

private:
    vector<vector<int>> r;
    void dfs(vector<int> &nums, int i, vector<int> cur)
    {
        if (i >= nums.size())
        {
            r.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        dfs(nums, i + 1, cur);
        cur.pop_back();
        dfs(nums, i + 1, cur);
        return;
    }
};