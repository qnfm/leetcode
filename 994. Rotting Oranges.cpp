#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int r = 0, f = 0;
        deque<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    ++f;
                else if (grid[i][j] == 2)
                    q.push_back({i, j});
            }
        }
        auto chk = [&](int i, int j)
        {
            bool r = i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1;
            if (!r)
                return false;
            grid[i][j] = 2;
            --f;
            return true;
        };
        while (!q.empty() && f > 0)
        {
            int len = q.size();
            // iterator?
            for (int i = 0; i < len; i++)
            {
                auto p = q.front();
                q.pop_front();
                if (chk(p.first - 1, p.second))
                    q.push_back({p.first - 1, p.second});
                if (chk(p.first + 1, p.second))
                    q.push_back({p.first + 1, p.second});
                if (chk(p.first, p.second - 1))
                    q.push_back({p.first, p.second - 1});
                if (chk(p.first, p.second + 1))
                    q.push_back({p.first, p.second + 1});
            }
            ++r;
        }
        return f == 0 ? r : -1;
    }

private:
    int m, n;
};