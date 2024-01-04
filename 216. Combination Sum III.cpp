#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> cur;
        dfs(cur, k, n, 1);
        return r;
    }

private:
    vector<vector<int>> r;
    void dfs(vector<int> cur, int k, int n, int i)
    {
        if (k == 0 && n == 0)
        {
            r.push_back(cur);
            return;
        }
        if (k <= 0)
            return;
        for (int j = i; j <= 9; j++)
        {
            cur.push_back(j);
            dfs(cur, k - 1, n - j, j + 1);
            cur.pop_back();
        }
    }
};