#include <queue>
#include <vector>
using namespace std;

class Solution
{

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool isSafe(int i, int j, int n)
    {
        return (i >= 0 && j >= 0 && i < n && j < n);
    }

    int dfs(priority_queue<pair<int, pair<int, int>>> &q, vector<vector<int>> &dis, int &n)
    {
        int count = 0;
        while (!q.empty())
        {
            pair<int, pair<int, int>> top = q.top();
            q.pop();
            if (top.second.first == n - 1 && top.second.second == n - 1)
            {
                return top.first;
            }
            for (int i = 0; i < 4; ++i)
            {
                int x = top.second.first + dx[i];
                int y = top.second.second + dy[i];
                if (isSafe(x, y, n))
                {
                    if (dis[x][y] != -1)
                    {
                        int minm = min(top.first, dis[x][y]);
                        q.push({minm, {x, y}});
                        dis[x][y] = -1;
                    }
                }
            }
        }
        return -1;
    }

public:
    int maximumSafenessFactor(vector<vector<int>> &v)
    {
        int n = v.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        vector<vector<int>> dis(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == 1)
                {
                    dis[i][j] = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty())
        {

            int size = q.size();
            while (size--)
            {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny])
                    {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                        dis[nx][ny] = dis[x][y] + 1;
                    }
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({dis[0][0], {0, 0}});
        dis[0][0] = -1;
        return dfs(pq, dis, n);
    }
};