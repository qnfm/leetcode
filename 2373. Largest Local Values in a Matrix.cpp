#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        const size_t M = grid.size(), N = grid[0].size();
        vector<vector<int>> res(M - 2, vector<int>(N - 2));
        size_t r = 0, c = 0;
        while (r + 2 < M)
        {
            while (c + 2 < N)
            {
                int cur = INT_MIN;
                for (auto i = r; i <= r + 2; ++i)
                {
                    for (auto j = c; j <= c + 2; ++j)
                    {
                        cur = max(cur, grid[i][j]);
                    }
                }
                res[r][c] = cur;
                ++c;
            }
            c = 0;
            ++r;
        }
        return res;
    }
};