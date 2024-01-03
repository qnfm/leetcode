#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        dfs(nums, 0);
        return r;
    }

private:
    vector<vector<int>> r;
    void dfs(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            r.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            dfs(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
};