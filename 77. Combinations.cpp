#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        N = n;
        K = k;
        vector<int> cur;
        dfs(cur, 1);
        return r;
    }

private:
    int N;
    int K;
    vector<vector<int>> r;
    void dfs(vector<int> cur, int idx)
    {
        if (cur.size() == K)
        {
            r.push_back(cur);
            return;
        }
        for (int i = idx; i <= N; i++)
        {
            cur.push_back(i);
            dfs(cur, i + 1);
            cur.pop_back();
        }
    }
};