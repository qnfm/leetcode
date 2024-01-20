#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        m = rooms.size();
        n = rooms[0].size();
        deque<pair<int, int>> q;

        auto chk = [&](int i, int j)
        {
            bool r = i < 0 || i >= m || j < 0 || j >= n || rooms[i][j] != INT_MAX;
            return !r;
        };
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rooms[i][j] == 0)
                {
                    q.push_back({i, j});
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop_front();
            for (auto del : dirs)
            {
                int i = x + del[0], j = y + del[1];
                if (chk(i, j))
                {
                    rooms[i][j] = rooms[x][y] + 1;
                    q.push_back({i, j});
                }
            }
        }
    }

private:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};